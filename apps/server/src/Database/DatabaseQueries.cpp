#include "DatabaseQueries.hpp"

bool database::create_db(sqlite3*& db) {
    std::string query = "CREATE TABLE IF NOT EXISTS Users ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(255) NOT NULL,"
                        "surname VARCHAR(255) NOT NULL,"
                        "email VARCHAR(255) NOT NULL UNIQUE,"
                        "password VARCHAR(255) NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Photos ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "productType INTEGER,"
                        "productTypeId INTEGER,"
                        "image BLOB"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Products ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "productName VARCHAR(255) NOT NULL,"
                        "productType INTEGER,"
                        "productTypeId INTEGER,"
                        "price INTEGER,"
                        "priceUnit VARCHAR(255),"
                        "quantity INTEGER,"
                        "hasDiscount BOOLEAN,"
                        "discount INTEGER,"
                        "isReadyToSell BOOLEAN"
                        ");"
                    "CREATE TABLE IF NOT EXISTS PurchaseOrders ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "userId INTEGER,"
                        "productId INTEGER,"
                        "paidType INTEGER,"
                        "destination TEXT,"
                        "packageId VARCHAR(255),"
                        "deliveryDate DATETIME,"
                        "status INTEGER,"
                        "FOREIGN KEY (userId) REFERENCES Users(id),"
                        "FOREIGN KEY (productId) REFERENCES Products(id)"
                        ");"
                    "CREATE TABLE IF NOT EXISTS BaseSeat ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "brand VARCHAR(255) NOT NULL,"
                        "suitableFor VARCHAR(255) NOT NULL,"
                        "color VARCHAR(255) NOT NULL,"
                        "material VARCHAR(255) NOT NULL,"
                        "type VARCHAR(255) NOT NULL,"
                        "description TEXT NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS ChildSeat ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "brand VARCHAR(255) NOT NULL,"
                        "age INTEGER NOT NULL,"
                        "weight INTEGER NOT NULL,"
                        "height INTEGER NOT NULL,"
                        "safetyKey VARCHAR(255) NOT NULL,"
                        "fastening VARCHAR(255) NOT NULL,"
                        "driveway VARCHAR(255) NOT NULL,"
                        "description TEXT NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS LuxurySeat ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "brand VARCHAR(255) NOT NULL,"
                        "suitableFor VARCHAR(255) NOT NULL,"
                        "color VARCHAR(255) NOT NULL,"
                        "material VARCHAR(255) NOT NULL,"
                        "comfortLevel INTEGER NOT NULL,"
                        "customDesign BOOLEAN NOT NULL,"
                        "description TEXT NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS SportSeat ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "brand VARCHAR(255) NOT NULL,"
                        "suitableFor VARCHAR(255) NOT NULL,"
                        "shellType VARCHAR(255) NOT NULL,"
                        "shellMaterial VARCHAR(255) NOT NULL,"
                        "coverMaterial VARCHAR(255) NOT NULL,"
                        "color VARCHAR(255) NOT NULL,"
                        "description TEXT NOT NULL"
                        ");";
    int rc = sqlite3_open("AutoChairShop.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    users = new UsersTable(dataTable);
    suppliers = new SuppliersTable(dataTable);
    purchaseOrders = new PurchaseOrdersTable(dataTable);
    products = new ProductsTable(dataTable);
    productInfo = new ProductInfoTable(dataTable);
    photos = new PhotosTable(dataTable);
    managers = new ManagersTable(dataTable);
    inventory = new InventoryTable(dataTable);
}

DatabaseManager::~DatabaseManager() {}

void DatabaseManager::readRequest(Request request, Common::Dataset &entity) {
    
    if(entity["TABLE:"].front() == Common::Users::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            std::cout << "[UserTable::GETALL] >> operation started\n";
            entity.clear();
            entity = users->getAll();
            break;

        case Request::GET:
            std::cout << "[UserTable::GET] >> operation started\n";
            users->get(entity);
            break;
        case Request::ADD:
            std::cout << "[UserTable::ADD] >> operation started\n";
            if(!users->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            std::cout << "[UserTable::UPDATE] >> operation started\n";
            if(!users->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            std::cout << "[UserTable::DELETE] >> operation started\n";
            if(!users->deleteAt(entity))
                std::cout << "[UserTable::DELETE] >> operation failed\n";
            break;
        default:
            break;
        }
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