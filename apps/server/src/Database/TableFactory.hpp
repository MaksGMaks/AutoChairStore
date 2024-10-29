#pragma once

#include "ITableFactory.hpp"

class TableFactory : public ITableFactory {
public:
    std::unique_ptr<ITable> makeUsersTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makePurchaseOrdersTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makeProductsTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makePhotosTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makeBaseSeatTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makeChildSeatTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makeLuxurySeatTable(sqlite3*& db) override;
    std::unique_ptr<ITable> makeSportSeatTable(sqlite3*& db) override;
};