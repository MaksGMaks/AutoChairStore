#include "BaseSeatTable.hpp"

BaseSeatTable::BaseSeatTable(sqlite3*& db) {
    dataBase = db;
}

bool BaseSeatTable::add(Common::Dataset &entity) {
    std::string query = "";

    auto id_list = entity[Common::BaseSeat::ID_KEY];
    auto brand_list = entity[Common::BaseSeat::BRAND_KEY];
    auto suitableFor_list = entity[Common::BaseSeat::SUITABLEFOR_KEY];
    auto color_list = entity[Common::BaseSeat::COLOR_KEY];
    auto material_list = entity[Common::BaseSeat::MATERIAL_KEY];
    auto type_list = entity[Common::BaseSeat::TYPE_KEY];
    auto description_list = entity[Common::BaseSeat::DESCRIPTION_KEY];

    for(auto element : entity[Common::BaseSeat::ID_KEY]) {
        query += "INSERT INTO " + std::string(Common::BaseSeat::TABLE_NAME) + " (" + std::string(Common::BaseSeat::BRAND_KEY) + ", " + 
        std::string(Common::BaseSeat::SUITABLEFOR_KEY) + ", " + std::string(Common::BaseSeat::COLOR_KEY) + ", " + 
        std::string(Common::BaseSeat::MATERIAL_KEY) + ", " + std::string(Common::BaseSeat::TYPE_KEY) + ", " + 
        std::string(Common::BaseSeat::DESCRIPTION_KEY) + ") VALUES ('" + 
        brand_list.front() + "', '" + suitableFor_list.front() + "', '" + color_list.front() + "', '" + 
        material_list.front() + "', '" + type_list.front() + "', '" + description_list.front() + "');";

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
    Common::Data values = entity[Common::COLUMN_KEY];
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

void BaseSeatTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::BaseSeat::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
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