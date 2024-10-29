#include "BaseSeatTable.hpp"

BaseSeatTable::BaseSeatTable(sqlite3*& db) {
    dataBase = db;
}

bool BaseSeatTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::BaseSeat::TABLE_NAME) + " (brand, suitableFor, color, material, type, description) "
                        "VALUES ('" + entity[Common::BaseSeat::BRAND_KEY].front() + "', '" + entity[Common::BaseSeat::SUITABLEFOR_KEY].front() + "', '"
                        + entity[Common::BaseSeat::COLOR_KEY].front() + "', '" + entity[Common::BaseSeat::MATERIAL_KEY].front() + "', '"
                        + entity[Common::BaseSeat::TYPE_KEY].front() + "', '" + entity[Common::BaseSeat::DESCRIPTION_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool BaseSeatTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::BaseSeat::ID_KEY];
    auto brand_list = data[Common::BaseSeat::BRAND_KEY];
    auto suitableFor_list = data[Common::BaseSeat::SUITABLEFOR_KEY];
    auto color_list = data[Common::BaseSeat::COLOR_KEY];
    auto material_list = data[Common::BaseSeat::MATERIAL_KEY];
    auto type_list = data[Common::BaseSeat::TYPE_KEY];
    auto description_list = data[Common::BaseSeat::DESCRIPTION_KEY];
    
    for(auto element : data[Common::BaseSeat::ID_KEY]) {
        query += "UPDATE " + std::string(Common::BaseSeat::TABLE_NAME) + " SET " + std::string(Common::BaseSeat::BRAND_KEY) + " = '" + 
        brand_list.front() + "', " + std::string(Common::BaseSeat::SUITABLEFOR_KEY) + " = '" + 
        suitableFor_list.front() + "', " + std::string(Common::BaseSeat::COLOR_KEY) + " = '" + 
        color_list.front() + "', " + std::string(Common::BaseSeat::MATERIAL_KEY) + " = '" + 
        material_list.front() + "', " + std::string(Common::BaseSeat::TYPE_KEY) + " = '" + 
        type_list.front() + "', " + std::string(Common::BaseSeat::DESCRIPTION_KEY) + " = '" + 
        description_list.front() + "' WHERE " + std::string(Common::BaseSeat::ID_KEY) + " = " + 
        id_list.front() + ";";

        brand_list.pop_front();
        suitableFor_list.pop_front();
        color_list.pop_front();
        material_list.pop_front();
        type_list.pop_front();
        description_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);   
}

bool BaseSeatTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::BaseSeat::TABLE_NAME) + " WHERE id = " + entity[Common::BaseSeat::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset BaseSeatTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::BaseSeat::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void BaseSeatTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if(!values.empty()) {
        for(auto element : values) {
            sql += ", " + element;
        }
    }

    sql += " FROM " + std::string(Common::BaseSeat::TABLE_NAME) + ";";
    entity = database::selectAllFromTable(sql, dataBase);
}
