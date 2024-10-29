#include "SportSeatTable.hpp"

SportSeatTable::SportSeatTable(sqlite3*& db) {
    dataBase = db;
}

bool SportSeatTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::SportSeat::TABLE_NAME) + " (brand, suitableFor, shellType, shellMaterial, coverMaterial, color, description) "
                        "VALUES ('" + entity[Common::SportSeat::BRAND_KEY].front() + "', '" + entity[Common::SportSeat::SUITABLEFOR_KEY].front() + "', '"
                        + entity[Common::SportSeat::SHELLTYPE_KEY].front() + "', '" + entity[Common::SportSeat::SHELLMATERIAL_KEY].front() + "', '"
                        + entity[Common::SportSeat::COVERMATERIAL_KEY].front() + "', '" + entity[Common::SportSeat::COLOR_KEY].front() + "', '"
                        + entity[Common::SportSeat::DESCRIPTION_KEY].front() + "');";

    return database::execute_query(query, dataBase);
}

bool SportSeatTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::SportSeat::ID_KEY];
    auto brand_list = data[Common::SportSeat::BRAND_KEY];
    auto suitableFor_list = data[Common::SportSeat::SUITABLEFOR_KEY];
    auto shellType_list = data[Common::SportSeat::SHELLTYPE_KEY];
    auto shellMaterial_list = data[Common::SportSeat::SHELLMATERIAL_KEY];
    auto coverMaterial_list = data[Common::SportSeat::COVERMATERIAL_KEY];
    auto color_list = data[Common::SportSeat::COLOR_KEY];
    auto description_list = data[Common::SportSeat::DESCRIPTION_KEY];

    for(auto element : data[Common::SportSeat::ID_KEY]) {
        query += "UPDATE " + std::string(Common::SportSeat::TABLE_NAME) + " SET " + std::string(Common::SportSeat::BRAND_KEY) + " = '" + 
        brand_list.front() + "', " + std::string(Common::SportSeat::SUITABLEFOR_KEY) + " = '" + 
        suitableFor_list.front() + "', " + std::string(Common::SportSeat::SHELLTYPE_KEY) + " = '" + 
        shellType_list.front() + "', " + std::string(Common::SportSeat::SHELLMATERIAL_KEY) + " = '" + 
        shellMaterial_list.front() + "', " + std::string(Common::SportSeat::COVERMATERIAL_KEY) + " = '" + 
        coverMaterial_list.front() + "', " + std::string(Common::SportSeat::COLOR_KEY) + " = '" + 
        color_list.front() + "', " + std::string(Common::SportSeat::DESCRIPTION_KEY) + " = '" + 
        description_list.front() + "' WHERE " + std::string(Common::SportSeat::ID_KEY) + " = " + 
        id_list.front() + ";";

        brand_list.pop_front();
        suitableFor_list.pop_front();
        shellType_list.pop_front();
        shellMaterial_list.pop_front();
        coverMaterial_list.pop_front();
        color_list.pop_front();
        description_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);
}

bool SportSeatTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::SportSeat::TABLE_NAME) + " WHERE id = " + entity[Common::SportSeat::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset SportSeatTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::SportSeat::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void SportSeatTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if(!values.empty()) {
        for(auto column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::SportSeat::TABLE_NAME) + ";";
    entity = database::selectAllFromTable(sql, dataBase);
}