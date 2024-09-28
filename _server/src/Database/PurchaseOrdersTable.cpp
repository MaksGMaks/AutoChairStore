#include "PurchaseOrdersTable.hpp"

PurchaseOrdersTable::PurchaseOrdersTable(sqlite3*& db) {
    dataBase = db;
}

PurchaseOrdersTable::~PurchaseOrdersTable() {}

bool PurchaseOrdersTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::PurchaseOrders::TABLE_NAME) + " (userId, productInfoId, isPrePaid, isFullPaid, shouldPaid, destination, packageId, deliveryDate) "
                        "VALUES ('" + entity[Common::PurchaseOrders::USERID_KEY].front() + "', '" + entity[Common::PurchaseOrders::PRODUCTINFOID_KEY].front() + "', '"
                        + entity[Common::PurchaseOrders::ISPREPAID_KEY].front() + "', '" + entity[Common::PurchaseOrders::ISFULLPAID_KEY].front() + "', '"
                        + entity[Common::PurchaseOrders::SHOULDPAID_KEY].front() + "', '" + entity[Common::PurchaseOrders::DESTINATION_KEY].front() + "', '"
                        + entity[Common::PurchaseOrders::PACKAGEID_KEY].front() + "', '" + entity[Common::PurchaseOrders::DELIVERYDATE_KEY].front() + "');";
    
    return database::execute_query(query, dataBase);
}

bool PurchaseOrdersTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::PurchaseOrders::ID_KEY];
    auto userId_list = data[Common::PurchaseOrders::USERID_KEY];
    auto productionInfoId_list = data[Common::PurchaseOrders::PRODUCTINFOID_KEY];
    auto isPrePaid_list = data[Common::PurchaseOrders::ISPREPAID_KEY];
    auto isFullPaid_list = data[Common::PurchaseOrders::ISFULLPAID_KEY];
    auto shouldPaid_list = data[Common::PurchaseOrders::SHOULDPAID_KEY];
    auto destination_list = data[Common::PurchaseOrders::DESTINATION_KEY];
    auto packageId_list = data[Common::PurchaseOrders::PACKAGEID_KEY];
    auto deliveryDate_list = data[Common::PurchaseOrders::DELIVERYDATE_KEY];
    
    for (auto element : data[Common::PurchaseOrders::ID_KEY]) {
        query += "UPDATE " + std::string(Common::PurchaseOrders::TABLE_NAME) + " SET " + std::string(Common::PurchaseOrders::USERID_KEY) + " = '" + 
        userId_list.front() + "', " + std::string(Common::PurchaseOrders::PRODUCTINFOID_KEY) + " = '" + 
        productionInfoId_list.front() + "', " + std::string(Common::PurchaseOrders::ISPREPAID_KEY) + " = '" + 
        isPrePaid_list.front() + "', " + std::string(Common::PurchaseOrders::ISFULLPAID_KEY) + " = '" + 
        isFullPaid_list.front() + "', " + std::string(Common::PurchaseOrders::SHOULDPAID_KEY) + " = '" + 
        shouldPaid_list.front() + "', " + std::string(Common::PurchaseOrders::DESTINATION_KEY) + " = '" + 
        destination_list.front() + "', " + std::string(Common::PurchaseOrders::PACKAGEID_KEY) + " = '" + 
        packageId_list.front() + "', " + std::string(Common::PurchaseOrders::DELIVERYDATE_KEY) + " = '" + 
        deliveryDate_list.front() + "' WHERE " + std::string(Common::PurchaseOrders::ID_KEY) + " = " + 
        id_list.front() + ";";

        userId_list.pop_front();
        productionInfoId_list.pop_front();
        isPrePaid_list.pop_front();
        isFullPaid_list.pop_front();
        shouldPaid_list.pop_front();
        destination_list.pop_front();
        packageId_list.pop_front();
        deliveryDate_list.pop_front();
        id_list.pop_front();
    }

    return database::execute_query(query, dataBase);
}

bool PurchaseOrdersTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::PurchaseOrders::TABLE_NAME) + " WHERE id = " + entity[Common::PurchaseOrders::ID_KEY].front() + ";";
    return database::execute_query(query, dataBase);
}

Common::Dataset PurchaseOrdersTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::PurchaseOrders::TABLE_NAME) + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void PurchaseOrdersTable::get(Common::Dataset &entity) {
    Common::Data values = entity["COLUMNS"];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    if (!values.empty()) {
        for (const auto& column : values) {
            sql += ", ";
            sql += column;
        }
    }

    sql += " FROM " + std::string(Common::PurchaseOrders::TABLE_NAME) + " WHERE id = " + entity[Common::PurchaseOrders::ID_KEY].front() + ";";
    entity.clear();
    entity = database::selectAllFromTable(sql, dataBase);
}
