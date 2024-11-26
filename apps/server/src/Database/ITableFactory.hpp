#pragma once
#include <iostream>
#include <memory>
#include <sqlite3.h>

#include "ITable.hpp"

#include "UsersTable.hpp"
#include "PurchaseOrdersTable.hpp"
#include "ProductsTable.hpp"
#include "PhotosTable.hpp"
#include "BaseSeatTable.hpp"
#include "ChildSeatTable.hpp"
#include "LuxurySeatTable.hpp"
#include "SportSeatTable.hpp"
#include "VerificationTable.hpp"

class ITableFactory {
public:
    virtual ~ITableFactory() = default;
    virtual std::unique_ptr<ITable> makeUsersTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makePurchaseOrdersTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeProductsTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makePhotosTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeBaseSeatTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeChildSeatTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeLuxurySeatTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeSportSeatTable(sqlite3*& db) = 0;
    virtual std::unique_ptr<ITable> makeVerificationTable(sqlite3*& db) = 0;
};