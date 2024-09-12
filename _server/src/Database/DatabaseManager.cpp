#include "DatabaseManager.hpp"

bool database::create_db(sqlite3*& db) {
    std::string query = "CREATE TABLE IF NOT EXISTS Users ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(255) NOT NULL,"
                        "surname VARCHAR(255) NOT NULL,"
                        "email VARCHAR(255) NOT NULL,"
                        "password VARCHAR(255) NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Managers ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "username VARCHAR(255) NOT NULL,"
                        "password VARCHAR(255) NOT NULL"
                        ");"
                    "CREATE TABLE IF NOT EXISTS Suppliers ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(255),"
                        "number VARCHAR(20),"
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
                        "productInfo INTEGER,"
                        "isPrePaid BOOLEAN,"
                        "isFullPaid BOOLEAN,"
                        "shouldPaid BOOLEAN,"
                        "destination TEXT,"
                        "packageId VARCHAR(255),"
                        "deliveryDate DATETIME,"
                        "FOREIGN KEY (userId) REFERENCES Users(id),"
                        "FOREIGN KEY (productInfo) REFERENCES ProductInfo(id)"
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