#include "ProductsTable.hpp"

ProductsTable::ProductsTable(sqlite3*& db) {
    dataBase = db;
}

bool ProductsTable::add(Common::Dataset &entity) {
    std::string query = "";

    auto id_list = entity[Common::Products::ID_KEY];
    auto productName_list = entity[Common::Products::PRODUCTNAME_KEY];
    auto productType_list = entity[Common::Products::PRODUCTTYPE_KEY];
    auto productTypeId_list = entity[Common::Products::PRODUCTTYPEID_KEY];
    auto price_list = entity[Common::Products::PRICE_KEY];
    auto priceUnit_list = entity[Common::Products::PRICEUNIT_KEY];
    auto quantity_list = entity[Common::Products::QUANTITY_KEY];
    auto hasDiscount_list = entity[Common::Products::HASDISCOUNT_KEY];
    auto discount_list = entity[Common::Products::DISCOUNT_KEY];
    auto isReadyToSell_list = entity[Common::Products::ISREADYTOSELL_KEY];

    for(auto element : entity[Common::Products::ID_KEY]) {
        query += "INSERT INTO " + std::string(Common::Products::TABLE_NAME) + " (" + std::string(Common::Products::PRODUCTNAME_KEY) + ", " + 
        std::string(Common::Products::PRODUCTTYPE_KEY) + ", " + std::string(Common::Products::PRODUCTTYPEID_KEY) + ", " + 
        std::string(Common::Products::PRICE_KEY) + ", " + std::string(Common::Products::PRICEUNIT_KEY) + ", " + 
        std::string(Common::Products::QUANTITY_KEY) + ", " + std::string(Common::Products::HASDISCOUNT_KEY) + ", " + 
        std::string(Common::Products::DISCOUNT_KEY) + ", " + std::string(Common::Products::ISREADYTOSELL_KEY) + ") VALUES ('" + 
        productName_list.front() + "', '" + productType_list.front() + "', '" + productTypeId_list.front() + "', '" + 
        price_list.front() + "', '" + priceUnit_list.front() + "', '" + quantity_list.front() + "', '" + 
        hasDiscount_list.front() + "', '" + discount_list.front() + "', '" + isReadyToSell_list.front() + "');";

        productName_list.pop_front();
        productType_list.pop_front();
        productTypeId_list.pop_front();
        price_list.pop_front();
        priceUnit_list.pop_front();
        quantity_list.pop_front();
        hasDiscount_list.pop_front();
        discount_list.pop_front();
        isReadyToSell_list.pop_front();
        id_list.pop_front();
    }
    
    return database::execute_query(query, dataBase);
}

bool ProductsTable::update(Common::Dataset &data) {
    std::cout << "[ProductsTable::update] Updating product" << std::endl;
    std::string query = "";

    auto id_list = data[Common::Products::ID_KEY];
    auto productName_list = data[Common::Products::PRODUCTNAME_KEY];
    auto productType_list = data[Common::Products::PRODUCTTYPE_KEY];
    auto productTypeId_list = data[Common::Products::PRODUCTTYPEID_KEY];
    auto price_list = data[Common::Products::PRICE_KEY];
    auto priceUnit_list = data[Common::Products::PRICEUNIT_KEY];
    auto quantity_list = data[Common::Products::QUANTITY_KEY];
    auto hasDiscount_list = data[Common::Products::HASDISCOUNT_KEY];
    auto discount_list = data[Common::Products::DISCOUNT_KEY];
    auto isReadyToSell_list = data[Common::Products::ISREADYTOSELL_KEY];

    for(auto element : data[Common::Products::ID_KEY]) {
        query += "UPDATE " + std::string(Common::Products::TABLE_NAME) + " SET " + std::string(Common::Products::PRODUCTNAME_KEY) + " = '" + 
        productName_list.front() + "', " + std::string(Common::Products::PRODUCTTYPE_KEY) + " = '" + 
        productType_list.front() + "', " + std::string(Common::Products::PRODUCTTYPEID_KEY) + " = '" + 
        productTypeId_list.front() + "', " + std::string(Common::Products::PRICE_KEY) + " = '" + 
        price_list.front() + "', " + std::string(Common::Products::PRICEUNIT_KEY) + " = '" + 
        priceUnit_list.front() + "', " + std::string(Common::Products::QUANTITY_KEY) + " = '" + 
        quantity_list.front() + "', " + std::string(Common::Products::HASDISCOUNT_KEY) + " = '" + 
        hasDiscount_list.front() + "', " + std::string(Common::Products::DISCOUNT_KEY) + " = '" + 
        discount_list.front() + "', " + std::string(Common::Products::ISREADYTOSELL_KEY) + " = '" + 
        isReadyToSell_list.front() + "' WHERE " + std::string(Common::Products::ID_KEY) + " = " + 
        id_list.front() + ";";

        productName_list.pop_front();
        productType_list.pop_front();
        productTypeId_list.pop_front();
        price_list.pop_front();
        priceUnit_list.pop_front();
        quantity_list.pop_front();
        hasDiscount_list.pop_front();
        discount_list.pop_front();
        isReadyToSell_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);  
}

bool ProductsTable::deleteAt(Common::Dataset &entity) {
    std::cout << "[ProductsTable::deleteAt] Deleting product" << std::endl;
    const std::string query =
        "DELETE FROM " + std::string(Common::Products::TABLE_NAME) + " WHERE id = " + entity[Common::Products::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset ProductsTable::getAll() {
    std::cout << "[ProductsTable::getAll] Getting all products" << std::endl;
    std::string sql = "SELECT * FROM " + std::string(Common::Products::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void ProductsTable::get(Common::Dataset &entity) {
    std::cout << "[ProductsTable::get] Getting product" << std::endl;
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    
    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", " + column;
        }
    }
    
    sql += " FROM " + std::string(Common::Products::TABLE_NAME) + " WHERE id = " + entity[Common::Products::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}

void ProductsTable::getColumns(Common::Dataset &entity) {
    std::cout << "[ProductsTable::getColumns] Getting columns" << std::endl;
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::Products::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
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