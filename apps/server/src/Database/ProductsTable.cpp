#include "ProductsTable.hpp"

ProductsTable::ProductsTable(sqlite3*& db) {
    dataBase = db;
}

ProductsTable::~ProductsTable() {}

bool ProductsTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::Products::TABLE_NAME) + " (inventoryId, hasDiscount, discount) "
                        "VALUES ('" + entity[Common::Products::INVENTORYID_KEY].front() + "', '" + entity[Common::Products::HASDISCOUNT_KEY].front() + "', '"
                        + entity[Common::Products::DISCOUNT_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool ProductsTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::Products::ID_KEY];
    auto inventoryId_list = data[Common::Products::INVENTORYID_KEY];
    auto hasDiscount_list = data[Common::Products::HASDISCOUNT_KEY];
    auto discount_list = data[Common::Products::DISCOUNT_KEY];
    
    for (auto element : data[Common::Products::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Products::TABLE_NAME) + " SET " + std::string(Common::Products::INVENTORYID_KEY) + " = '" + 
        inventoryId_list.front() + "', " + std::string(Common::Products::HASDISCOUNT_KEY) + " = '" + 
        hasDiscount_list.front() + "', " + std::string(Common::Products::DISCOUNT_KEY) + " = '" + 
        discount_list.front() + "' WHERE " + std::string(Common::Products::ID_KEY) + " = " + 
        id_list.front() + ";";

        inventoryId_list.pop_front();
        hasDiscount_list.pop_front();
        discount_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);  
}

bool ProductsTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::Products::TABLE_NAME) + " WHERE id = " + entity[Common::Products::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset ProductsTable::getAll() {
    return database::selectAllFromTable(std::string(Common::Products::TABLE_NAME), dataBase);
}

void ProductsTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    
    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", " + column;
        }
    }
    
    sql += " FROM " + std::string(Common::Products::TABLE_NAME) + " WHERE id = " + entity[Common::Products::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}
