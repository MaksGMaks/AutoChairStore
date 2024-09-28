#include "ITableFactory.hpp"

ITableFactory::~ITableFactory() {}

std::unique_ptr<ITable> ITableFactory::makeUsersTable(sqlite3*& db) {
    return std::make_unique<UsersTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makeSuppliersTable(sqlite3*& db) {
    return std::make_unique<SuppliersTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makePurchaseOrdersTable(sqlite3*& db) {
    return std::make_unique<PurchaseOrdersTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makeProductsTable(sqlite3*& db) {
    return std::make_unique<ProductsTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makeProductInfoTable(sqlite3*& db) {
    return std::make_unique<ProductInfoTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makePhotosTable(sqlite3*& db) {
    return std::make_unique<PhotosTable>(db);
}

std::unique_ptr<ITable> ITableFactory::makeInventoryTable(sqlite3*& db) {
    return std::make_unique<InventoryTable>(db);
}