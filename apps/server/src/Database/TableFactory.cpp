#include "TableFactory.hpp"

std::unique_ptr<ITable> TableFactory::makeUsersTable(sqlite3*& db) {
    return std::make_unique<UsersTable>(db);
}

std::unique_ptr<ITable> TableFactory::makePurchaseOrdersTable(sqlite3*& db) {
    return std::make_unique<PurchaseOrdersTable>(db);
}

std::unique_ptr<ITable> TableFactory::makeProductsTable(sqlite3*& db) {
    return std::make_unique<ProductsTable>(db);
}

std::unique_ptr<ITable> TableFactory::makePhotosTable(sqlite3*& db) {
    return std::make_unique<PhotosTable>(db);
}

std::unique_ptr<ITable> TableFactory::makeBaseSeatTable(sqlite3*& db) {
    return std::make_unique<BaseSeatTable>(db);
}

std::unique_ptr<ITable> TableFactory::makeChildSeatTable(sqlite3*& db) {
    return std::make_unique<ChildSeatTable>(db);
}

std::unique_ptr<ITable> TableFactory::makeLuxurySeatTable(sqlite3*& db) {
    return std::make_unique<LuxurySeatTable>(db);
}

std::unique_ptr<ITable> TableFactory::makeSportSeatTable(sqlite3*& db) {
    return std::make_unique<SportSeatTable>(db);
}