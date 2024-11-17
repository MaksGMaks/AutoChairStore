#include "ChildSeatTable.hpp"

ChildSeatTable::ChildSeatTable(sqlite3*& db) {
    dataBase = db;
}

bool ChildSeatTable::add(Common::Dataset &entity) {
    std::string query = "";

    auto id_list = entity[Common::ChildSeat::ID_KEY];
    auto brand_list = entity[Common::ChildSeat::BRAND_KEY];
    auto age_list = entity[Common::ChildSeat::AGE_KEY];
    auto weight_list = entity[Common::ChildSeat::WEIGHT_KEY];
    auto height_list = entity[Common::ChildSeat::HEIGHT_KEY];
    auto safetyKey_list = entity[Common::ChildSeat::SAFETYKEY_KEY];
    auto fastening_list = entity[Common::ChildSeat::FASTENING_KEY];
    auto driveway_list = entity[Common::ChildSeat::DRIVEWAY_KEY];
    auto description_list = entity[Common::ChildSeat::DESCRIPTION_KEY];

    for(auto element : entity[Common::ChildSeat::ID_KEY]) {
        query += "INSERT INTO " + std::string(Common::ChildSeat::TABLE_NAME) + " (" + std::string(Common::ChildSeat::BRAND_KEY) + ", " + 
        std::string(Common::ChildSeat::AGE_KEY) + ", " + std::string(Common::ChildSeat::WEIGHT_KEY) + ", " + 
        std::string(Common::ChildSeat::HEIGHT_KEY) + ", " + std::string(Common::ChildSeat::SAFETYKEY_KEY) + ", " + 
        std::string(Common::ChildSeat::FASTENING_KEY) + ", " + std::string(Common::ChildSeat::DRIVEWAY_KEY) + ", " + 
        std::string(Common::ChildSeat::DESCRIPTION_KEY) + ") VALUES ('" + 
        brand_list.front() + "', '" + age_list.front() + "', '" + weight_list.front() + "', '" + 
        height_list.front() + "', '" + safetyKey_list.front() + "', '" + fastening_list.front() + "', '" + 
        driveway_list.front() + "', '" + description_list.front() + "');";

        brand_list.pop_front();
        age_list.pop_front();
        weight_list.pop_front();
        height_list.pop_front();
        safetyKey_list.pop_front();
        fastening_list.pop_front();
        driveway_list.pop_front();
        description_list.pop_front();
        id_list.pop_front();
    }
    
    return database::execute_query(query, dataBase);
}

bool ChildSeatTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::ChildSeat::ID_KEY];
    auto brand_list = data[Common::ChildSeat::BRAND_KEY];
    auto age_list = data[Common::ChildSeat::AGE_KEY];
    auto weight_list = data[Common::ChildSeat::WEIGHT_KEY];
    auto height_list = data[Common::ChildSeat::HEIGHT_KEY];
    auto safetyKey_list = data[Common::ChildSeat::SAFETYKEY_KEY];
    auto fastening_list = data[Common::ChildSeat::FASTENING_KEY];
    auto driveway_list = data[Common::ChildSeat::DRIVEWAY_KEY];
    auto description_list = data[Common::ChildSeat::DESCRIPTION_KEY];
    
    for(auto element : data[Common::ChildSeat::ID_KEY]) {
        query += "UPDATE " + std::string(Common::ChildSeat::TABLE_NAME) + " SET " + std::string(Common::ChildSeat::BRAND_KEY) + " = '" + 
        brand_list.front() + "', " + std::string(Common::ChildSeat::AGE_KEY) + " = '" + 
        age_list.front() + "', " + std::string(Common::ChildSeat::WEIGHT_KEY) + " = '" + 
        weight_list.front() + "', " + std::string(Common::ChildSeat::HEIGHT_KEY) + " = '" + 
        height_list.front() + "', " + std::string(Common::ChildSeat::SAFETYKEY_KEY) + " = '" + 
        safetyKey_list.front() + "', " + std::string(Common::ChildSeat::FASTENING_KEY) + " = '" + 
        fastening_list.front() + "', " + std::string(Common::ChildSeat::DRIVEWAY_KEY) + " = '" + 
        driveway_list.front() + "', " + std::string(Common::ChildSeat::DESCRIPTION_KEY) + " = '" + 
        description_list.front() + "' WHERE " + std::string(Common::ChildSeat::ID_KEY) + " = " + 
        id_list.front() + ";";

        brand_list.pop_front();
        age_list.pop_front();
        weight_list.pop_front();
        height_list.pop_front();
        safetyKey_list.pop_front();
        fastening_list.pop_front();
        driveway_list.pop_front();
        description_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);
}

bool ChildSeatTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::ChildSeat::TABLE_NAME) + " WHERE id = " + entity[Common::ChildSeat::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset ChildSeatTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::ChildSeat::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void ChildSeatTable::get(Common::Dataset &entity) {
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if(!values.empty()) {
        for(auto column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::ChildSeat::TABLE_NAME) + ";";
    entity = database::selectAllFromTable(sql, dataBase);
}

void ChildSeatTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::ChildSeat::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
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