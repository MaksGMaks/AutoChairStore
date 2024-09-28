#pragma once

#include <iostream>
#include <sqlite3.h>

#include <nlohmann/json.hpp>

#include "DatabaseQueries.hpp"
#include "../../_common/src/Repositories.hpp"

#include "UserTable.hpp"
#include "SuppliersTable.hpp"
#include "PurchaseOrdersTable.hpp"
#include "ProductsTable.hpp"
#include "ProductInfoTable.hpp"
#include "PhotosTable.hpp"
#include "ManagersTable.hpp"
#include "InventoryTable.hpp"

using json = nlohmann::json;

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    void readRequest(Request request, Common::Dataset &entity);
private:
    sqlite3 *dataTable;

    UsersTable *users;
    SuppliersTable *suppliers;
    PurchaseOrdersTable *purchaseOrders;
    ProductsTable *products;
    ProductInfoTable *productInfo;
    PhotosTable *photos;
    ManagersTable *managers;
    InventoryTable *inventory;
};
