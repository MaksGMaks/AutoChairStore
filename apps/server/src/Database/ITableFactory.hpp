#pragma once
#include <iostream>
#include <memory>
#include <sqlite3.h>

#include "ITable.hpp"

#include "UserTable.hpp"
#include "SuppliersTable.hpp"
#include "PurchaseOrdersTable.hpp"
#include "ProductsTable.hpp"
#include "ProductInfoTable.hpp"
#include "PhotosTable.hpp"
#include "InventoryTable.hpp"

class ITableFactory {
public:
    virtual ~ITableFactory();
    std::unique_ptr<ITable> makeUsersTable(sqlite3*& db);
    std::unique_ptr<ITable> makeSuppliersTable(sqlite3*& db);
    std::unique_ptr<ITable> makePurchaseOrdersTable(sqlite3*& db);
    std::unique_ptr<ITable> makeProductsTable(sqlite3*& db);
    std::unique_ptr<ITable> makeProductInfoTable(sqlite3*& db);
    std::unique_ptr<ITable> makePhotosTable(sqlite3*& db);
    std::unique_ptr<ITable> makeInventoryTable(sqlite3*& db);
};