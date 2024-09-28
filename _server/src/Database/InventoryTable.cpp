#include "InventoryTable.hpp"

InventoryTable::InventoryTable(sqlite3*& db) {
    dataBase = db;
}

InventoryTable::~InventoryTable() {}

bool InventoryTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::Inventory::TABLE_NAME) + " (productInfoId, quantity, isReadyToSell) "
                        "VALUES ('" + entity[Common::Inventory::PRODUCTINFOID_KEY].front() + "', '" + 
                        entity[Common::Inventory::QUANTITY_KEY].front() + "', '" + 
                        entity[Common::Inventory::ISREADYTOSELL_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool InventoryTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::Inventory::ID_KEY];
    auto productInfoId_list = data[Common::Inventory::PRODUCTINFOID_KEY];
    auto quantity_list = data[Common::Inventory::QUANTITY_KEY];
    auto isReadyToSell_list = data[Common::Inventory::ISREADYTOSELL_KEY];
    
    for (auto element : data[Common::Inventory::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Inventory::TABLE_NAME) + " SET " + 
        std::string(Common::Inventory::PRODUCTINFOID_KEY) + " = '" + productInfoId_list.front() + "', " +
        std::string(Common::Inventory::QUANTITY_KEY) + " = '" + quantity_list.front() + "', " +
        std::string(Common::Inventory::ISREADYTOSELL_KEY) + " = '" + isReadyToSell_list.front() + "' " +
        "WHERE " + std::string(Common::Inventory::ID_KEY) + " = " + id_list.front() + ";";

        productInfoId_list.pop_front();
        quantity_list.pop_front();
        isReadyToSell_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);   
}

bool InventoryTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::Inventory::TABLE_NAME) + " WHERE id = " + entity[Common::Inventory::ID_KEY].front() + ";";
    
    return database::execute_query(query, dataBase);
}

Common::Dataset InventoryTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::Inventory::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void InventoryTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if (!values.empty()) {
        for (auto column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::Inventory::TABLE_NAME) + " WHERE id = " + entity[Common::Inventory::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}
