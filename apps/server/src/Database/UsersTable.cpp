#include "UsersTable.hpp"

UsersTable::UsersTable(sqlite3*& db) {
    dataBase = db;
}

UsersTable::~UsersTable() {}

bool UsersTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::Users::TABLE_NAME) + " (name, surname, email, password) "
                        "VALUES ('" + entity[Common::Users::NAME_KEY].front() + "', '" + entity[Common::Users::SURNAME_KEY].front() + "', '"
                        + entity[Common::Users::EMAIL_KEY].front() + "', '" + entity[Common::Users::PASSWORD_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool UsersTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::Users::ID_KEY];
    auto name_list = data[Common::Users::NAME_KEY];
    auto surname_list = data[Common::Users::SURNAME_KEY];
    auto email_list = data[Common::Users::EMAIL_KEY];
    auto password_list = data[Common::Users::PASSWORD_KEY];
    
    for(auto element : data[Common::Users::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Users::TABLE_NAME) + " SET " + std::string(Common::Users::NAME_KEY) + " = '" + 
        name_list.front() + "', " + std::string(Common::Users::SURNAME_KEY) + " = '" + 
        surname_list.front() + "', " + std::string(Common::Users::EMAIL_KEY) + " = '" + 
        email_list.front() + "', " + std::string(Common::Users::PASSWORD_KEY) + " = '" + 
        password_list.front() + "' WHERE " + std::string(Common::Users::ID_KEY) + " = " + 
        id_list.front() + ";";

        name_list.pop_front();
        surname_list.pop_front();
        email_list.pop_front();
        password_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);   
}

bool UsersTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::Users::TABLE_NAME) + " WHERE id = " + entity[Common::Users::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset UsersTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::Users::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void UsersTable::get(Common::Dataset &entity) {
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();

    if(!values.empty()) {
        for(auto column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::Users::TABLE_NAME) + " WHERE id = " + entity[Common::Users::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}

void UsersTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::Users::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
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