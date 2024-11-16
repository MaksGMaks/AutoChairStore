#include "PhotosTable.hpp"

PhotosTable::PhotosTable(sqlite3*& db) {
    dataBase = db;
}

bool PhotosTable::add(Common::Dataset &entity) {
    std::cout << "[PhotosTable::add] Adding photo" << std::endl;
    std::string query = "INSERT INTO " + std::string(Common::Photos::TABLE_NAME) + " (productType, productTypeId, image) "
                        "VALUES ('" + entity[Common::Photos::PRODUCTTYPE_KEY].front() + "', '" + entity[Common::Photos::PRODUCTTYPEID_KEY].front() + "', '"
                        + entity[Common::Photos::IMAGE_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool PhotosTable::update(Common::Dataset &data) {
    std::cout << "[PhotosTable::update] Updating photo" << std::endl;
    std::string query = "";

    auto id_list = data[Common::Photos::ID_KEY];
    auto productType_list = data[Common::Photos::PRODUCTTYPE_KEY];
    auto productTypeId_list = data[Common::Photos::PRODUCTTYPEID_KEY];
    auto image_list = data[Common::Photos::IMAGE_KEY];

    for(auto element : data[Common::Photos::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Photos::TABLE_NAME) + " SET " + std::string(Common::Photos::PRODUCTTYPE_KEY) + " = '" + 
        productType_list.front() + "', " + std::string(Common::Photos::PRODUCTTYPEID_KEY) + " = '" + 
        productTypeId_list.front() + "', " + std::string(Common::Photos::IMAGE_KEY) + " = '" + 
        image_list.front() + "' WHERE " + std::string(Common::Photos::ID_KEY) + " = " + 
        id_list.front() + ";";

        productType_list.pop_front();
        productTypeId_list.pop_front();
        image_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);  
}

bool PhotosTable::deleteAt(Common::Dataset &entity) {
    std::cout << "[PhotosTable::deleteAt] Deleting photo" << std::endl;
    const std::string query =
        "DELETE FROM " + std::string(Common::Photos::TABLE_NAME) + " WHERE id = " + entity[Common::Photos::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset PhotosTable::getAll() {
    std::cout << "[PhotosTable::getAll] Getting all photos" << std::endl;
    std::string sql = "SELECT * FROM " + std::string(Common::Photos::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void PhotosTable::get(Common::Dataset &entity) {
    std::cout << "[PhotosTable::get] Getting photo" << std::endl;
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    
    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", " + column;
        }
    }
    
    sql += " FROM " + std::string(Common::Photos::TABLE_NAME) + " WHERE id = " + entity[Common::Photos::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}

void PhotosTable::getColumns(Common::Dataset &entity) {
    std::cout << "[PhotosTable::getColumns] Getting columns" << std::endl;
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
        sql += " AND " + column + " IN ('" + values.front();
        values.pop_front();
        for(auto value : values) {
            sql += "', '" + value;
        }
        sql += "')";
    }
    sql += ";";
    entity = database::selectAllFromTable(sql, dataBase);
}