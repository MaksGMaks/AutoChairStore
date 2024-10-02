#include "ProductInfoTable.hpp"

ProductInfoTable::ProductInfoTable(sqlite3*& db) {
    dataBase = db;
}

ProductInfoTable::~ProductInfoTable() {}

bool ProductInfoTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::ProductInfo::TABLE_NAME) + " (description, supplierId, name, lastPrice, unit, isImported) "
                        "VALUES ('" + entity[Common::ProductInfo::DESCRIPTION_KEY].front() + "', '" + entity[Common::ProductInfo::SUPPLIERID_KEY].front() + "', '" 
                        + entity[Common::ProductInfo::NAME_KEY].front() + "', " + entity[Common::ProductInfo::LASTPRICE_KEY].front() + ", '"
                        + entity[Common::ProductInfo::UNIT_KEY].front() + "', " + entity[Common::ProductInfo::ISIMPORTED_KEY].front() + ");";
    
    return database::execute_query(query, dataBase);
}

bool ProductInfoTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::ProductInfo::ID_KEY];
    auto description_list = data[Common::ProductInfo::DESCRIPTION_KEY];
    auto supplierId_list = data[Common::ProductInfo::SUPPLIERID_KEY];
    auto name_list = data[Common::ProductInfo::NAME_KEY];
    auto lastPrice_list = data[Common::ProductInfo::LASTPRICE_KEY];
    auto unit_list = data[Common::ProductInfo::UNIT_KEY];
    auto isImported_list = data[Common::ProductInfo::ISIMPORTED_KEY];
    
    for (auto element : data[Common::ProductInfo::ID_KEY]) {
        query += "UPDATE " + std::string(Common::ProductInfo::TABLE_NAME) + " SET " + std::string(Common::ProductInfo::DESCRIPTION_KEY) + " = '" + 
        description_list.front() + "', " + std::string(Common::ProductInfo::SUPPLIERID_KEY) + " = " + 
        supplierId_list.front() + ", " + std::string(Common::ProductInfo::NAME_KEY) + " = '" + 
        name_list.front() + "', " + std::string(Common::ProductInfo::LASTPRICE_KEY) + " = " + 
        lastPrice_list.front() + ", " + std::string(Common::ProductInfo::UNIT_KEY) + " = '" + 
        unit_list.front() + "', " + std::string(Common::ProductInfo::ISIMPORTED_KEY) + " = " + 
        isImported_list.front() + " WHERE " + std::string(Common::ProductInfo::ID_KEY) + " = " + 
        id_list.front() + ";";

        description_list.pop_front();
        supplierId_list.pop_front();
        name_list.pop_front();
        lastPrice_list.pop_front();
        unit_list.pop_front();
        isImported_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);  
}

bool ProductInfoTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::ProductInfo::TABLE_NAME) + " WHERE id = " + entity[Common::ProductInfo::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset ProductInfoTable::getAll() {
    return database::selectAllFromTable(std::string(Common::ProductInfo::TABLE_NAME), dataBase);
}

void ProductInfoTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    
    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", " + column;
        }
    }
    
    sql += " FROM " + std::string(Common::ProductInfo::TABLE_NAME) + " WHERE id = " + entity[Common::ProductInfo::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}
