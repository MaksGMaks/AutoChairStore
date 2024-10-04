#include "DatabaseQueries.hpp"

bool database::create_db(sqlite3*& db) {
    std::string query = "CREATE TABLE IF NOT EXISTS Users ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(255) NOT NULL,"
                        "surname VARCHAR(255) NOT NULL,"
                        "email VARCHAR(255) NOT NULL,"
                        "password VARCHAR(255) NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Suppliers ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(255),"
                        "phone VARCHAR(20),"
                        "email VARCHAR(100)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS ProductInfo ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "description TEXT,"
                        "supplierId INTEGER,"
                        "name VARCHAR(20),"
                        "lastPrice FLOAT,"
                        "unit VARCHAR(20),"
                        "isImported BOOLEAN,"
                        "FOREIGN KEY (supplierId) REFERENCES Suppliers(id)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Photos ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "productId INTEGER,"
                        "image BLOB,"
                        "FOREIGN KEY (productId) REFERENCES ProductInfo(id)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Inventory ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "productInfoId INTEGER,"
                        "quantity INTEGER,"
                        "isReadyToSell BOOLEAN,"
                        "FOREIGN KEY (productInfoId) REFERENCES ProductInfo(id)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Products ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "inventoryId INTEGER,"
                        "hasDiscount BOOLEAN,"
                        "discount INTEGER,"
                        "FOREIGN KEY (inventoryId) REFERENCES Inventory(id)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS PurchaseOrders ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "userId INTEGER,"
                        "productInfoId INTEGER,"
                        "isPrePaid BOOLEAN,"
                        "isFullPaid BOOLEAN,"
                        "shouldPaid BOOLEAN,"
                        "destination TEXT,"
                        "packageId VARCHAR(255),"
                        "deliveryDate DATETIME,"
                        "FOREIGN KEY (userId) REFERENCES Users(id),"
                        "FOREIGN KEY (productInfoId) REFERENCES ProductInfo(id)"
                        ");";
    int rc = sqlite3_open("AutoChairShop.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    rc = sqlite3_exec(db,  query.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << 0 << std::endl;
        sqlite3_free(0);
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;

}

bool database::execute_query(const std::string query, sqlite3*& db) {
    int rc = sqlite3_open("AutoChairShop.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    rc = sqlite3_exec(db,  query.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << 1 << std::endl;
        sqlite3_free(0);
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;
}

Common::Dataset database::selectAllFromTable(const std::string &sql, sqlite3* db) {
    Common::Dataset dataset;
    sqlite3_stmt* stmt;

    if (sqlite3_open("AutoChairShop.db", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return dataset;
    }

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return dataset;
    }

    // Get column names
    int columnCount = sqlite3_column_count(stmt);
    std::vector<std::string> columnNames;
    for (int i = 0; i < columnCount; ++i) {
        columnNames.push_back(sqlite3_column_name(stmt, i));
    }

    // Initialize the dataset with column names as keys
    for (const auto& columnName : columnNames) {
        dataset[columnName] = Common::Data{};
    }

    // Execute the SQL statement and iterate through the result set
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int i = 0; i < columnCount; ++i) {
            const unsigned char* text = sqlite3_column_text(stmt, i);
            if (text) {
                dataset[columnNames[i]].push_back(reinterpret_cast<const char*>(text));
            } else {
                dataset[columnNames[i]].push_back("NULL");
            }
        }
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return dataset;
}