#include "SuppliersTable.hpp"

SuppliersTable::SuppliersTable(sqlite3*& db) {
    dataBase = db;
}

SuppliersTable::~SuppliersTable() {}

bool SuppliersTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::Suppliers::TABLE_NAME) + " (name, phone, email) "
                        "VALUES ('" + entity[Common::Suppliers::NAME_KEY].front() + "', '" + entity[Common::Suppliers::PHONE_KEY].front() + "', '"
                        + entity[Common::Suppliers::EMAIL_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool SuppliersTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::Suppliers::ID_KEY];
    auto name_list = data[Common::Suppliers::NAME_KEY];
    auto phone_list = data[Common::Suppliers::PHONE_KEY];
    auto email_list = data[Common::Suppliers::EMAIL_KEY];
    
    for (auto element : data[Common::Suppliers::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Suppliers::TABLE_NAME) + " SET " + std::string(Common::Suppliers::NAME_KEY) + " = '" + 
        name_list.front() + "', " + std::string(Common::Suppliers::PHONE_KEY) + " = '" + 
        phone_list.front() + "', " + std::string(Common::Suppliers::EMAIL_KEY) + " = '" + 
        email_list.front() + "' WHERE " + std::string(Common::Suppliers::ID_KEY) + " = " + 
        id_list.front() + ";";

        name_list.pop_front();
        phone_list.pop_front();
        email_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);
}

bool SuppliersTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::Suppliers::TABLE_NAME) + " WHERE id = " + entity[Common::Suppliers::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset SuppliersTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::Suppliers::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void SuppliersTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::Suppliers::TABLE_NAME) + " WHERE id = " + entity[Common::Suppliers::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}
