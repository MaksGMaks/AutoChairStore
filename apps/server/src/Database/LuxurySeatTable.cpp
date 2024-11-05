#include "LuxurySeatTable.hpp"

LuxurySeatTable::LuxurySeatTable(sqlite3*& db) {
    dataBase = db;
}

bool LuxurySeatTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::LuxurySeat::TABLE_NAME) + " (brand, suitableFor, color, material, comfortLevel, customDesign, description) "
                        "VALUES ('" + entity[Common::LuxurySeat::BRAND_KEY].front() + "', '" + entity[Common::LuxurySeat::SUITABLEFOR_KEY].front() + "', '"
                        + entity[Common::LuxurySeat::COLOR_KEY].front() + "', '" + entity[Common::LuxurySeat::MATERIAL_KEY].front() + "', '"
                        + entity[Common::LuxurySeat::COMFORTLEVEL_KEY].front() + "', '" + entity[Common::LuxurySeat::CUSTOMDESIGN_KEY].front() + "', '"
                        + entity[Common::LuxurySeat::DESCRIPTION_KEY].front() + "');";

    return database::execute_query(query, dataBase);
}

bool LuxurySeatTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::LuxurySeat::ID_KEY];
    auto brand_list = data[Common::LuxurySeat::BRAND_KEY];
    auto suitableFor_list = data[Common::LuxurySeat::SUITABLEFOR_KEY];
    auto color_list = data[Common::LuxurySeat::COLOR_KEY];
    auto material_list = data[Common::LuxurySeat::MATERIAL_KEY];
    auto comfortLevel_list = data[Common::LuxurySeat::COMFORTLEVEL_KEY];
    auto customDesign_list = data[Common::LuxurySeat::CUSTOMDESIGN_KEY];
    auto description_list = data[Common::LuxurySeat::DESCRIPTION_KEY];

    for(auto element : data[Common::LuxurySeat::ID_KEY]) {
        query += "UPDATE " + std::string(Common::LuxurySeat::TABLE_NAME) + " SET " + std::string(Common::LuxurySeat::BRAND_KEY) + " = '" + 
        brand_list.front() + "', " + std::string(Common::LuxurySeat::SUITABLEFOR_KEY) + " = '" + 
        suitableFor_list.front() + "', " + std::string(Common::LuxurySeat::COLOR_KEY) + " = '" + 
        color_list.front() + "', " + std::string(Common::LuxurySeat::MATERIAL_KEY) + " = '" + 
        material_list.front() + "', " + std::string(Common::LuxurySeat::COMFORTLEVEL_KEY) + " = '" + 
        comfortLevel_list.front() + "', " + std::string(Common::LuxurySeat::CUSTOMDESIGN_KEY) + " = '" + 
        customDesign_list.front() + "', " + std::string(Common::LuxurySeat::DESCRIPTION_KEY) + " = '" + 
        description_list.front() + "' WHERE " + std::string(Common::LuxurySeat::ID_KEY) + " = " + 
        id_list.front() + ";";

        brand_list.pop_front();
        suitableFor_list.pop_front();
        color_list.pop_front();
        material_list.pop_front();
        comfortLevel_list.pop_front();
        customDesign_list.pop_front();
        description_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);
}

bool LuxurySeatTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::LuxurySeat::TABLE_NAME) + " WHERE id = " + entity[Common::LuxurySeat::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset LuxurySeatTable::getAll() {
    const std::string query = "SELECT * FROM " + std::string(Common::LuxurySeat::TABLE_NAME) + ";";
    return database::selectAllFromTable(query, dataBase);
}

void LuxurySeatTable::get(Common::Dataset &entity) {
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if(!values.empty()) {
        for(auto column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::LuxurySeat::TABLE_NAME) + ";";
    entity = database::selectAllFromTable(sql, dataBase);
}

void LuxurySeatTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::LuxurySeat::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
    Common::Data values = entity[columns.front()];
    sql += values.front();
    values.pop_front();
    for(auto value : values) {
        sql += "', '" + value;
    }
    sql += "')";
    columns.pop_front();
    for(auto column : columns) {
        values = entity[column];
        sql += "AND " + column + "IN ('" + values.front();
        values.pop_front();
        for(auto value : values) {
            sql += "', '" + value;
        }
        sql += "')";
    }
    sql += ";";
    entity = database::selectAllFromTable(sql, dataBase);
}