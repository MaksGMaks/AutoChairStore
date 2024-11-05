#include "PurchaseOrdersTable.hpp"

PurchaseOrdersTable::PurchaseOrdersTable(sqlite3*& db) {
    dataBase = db;
}

PurchaseOrdersTable::~PurchaseOrdersTable() {}

bool PurchaseOrdersTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::PurchaseOrders::TABLE_NAME) + " (userId, productId, paidType, destination, packageId, deliveryDate, status) "
                        "VALUES ('" + entity[Common::PurchaseOrders::USERID_KEY].front() + "', '" + entity[Common::PurchaseOrders::PRODUCTID_KEY].front() + "', '" +
                        entity[Common::PurchaseOrders::PAIDTYPE_KEY].front() + "', '" + entity[Common::PurchaseOrders::DESTINATION_KEY].front() + "', '" +
                        entity[Common::PurchaseOrders::PACKAGEID_KEY].front() + "', '" + entity[Common::PurchaseOrders::DELIVERYDATE_KEY].front() + "', '" +
                        entity[Common::PurchaseOrders::STATUS_KEY].front() + "');";

    return database::execute_query(query, dataBase);
}

bool PurchaseOrdersTable::update(Common::Dataset &data) {
    std::string query = "";

    auto id_list = data[Common::PurchaseOrders::ID_KEY];
    auto userId_list = data[Common::PurchaseOrders::USERID_KEY];
    auto productId_list = data[Common::PurchaseOrders::PRODUCTID_KEY];
    auto paidType_list = data[Common::PurchaseOrders::PAIDTYPE_KEY];
    auto destination_list = data[Common::PurchaseOrders::DESTINATION_KEY];
    auto packageId_list = data[Common::PurchaseOrders::PACKAGEID_KEY];
    auto deliveryDate_list = data[Common::PurchaseOrders::DELIVERYDATE_KEY];
    auto status_list = data[Common::PurchaseOrders::STATUS_KEY];

    for (auto element : data[Common::PurchaseOrders::ID_KEY]) {
        query += "UPDATE " + std::string(Common::PurchaseOrders::TABLE_NAME) + " SET " + std::string(Common::PurchaseOrders::USERID_KEY) + " = '" +
                 userId_list.front() + "', " + std::string(Common::PurchaseOrders::PRODUCTID_KEY) + " = '" +
                 productId_list.front() + "', " + std::string(Common::PurchaseOrders::PAIDTYPE_KEY) + " = '" +
                 paidType_list.front() + "', " + std::string(Common::PurchaseOrders::DESTINATION_KEY) + " = '" +
                 destination_list.front() + "', " + std::string(Common::PurchaseOrders::PACKAGEID_KEY) + " = '" +
                 packageId_list.front() + "', " + std::string(Common::PurchaseOrders::DELIVERYDATE_KEY) + " = '" +
                 deliveryDate_list.front() + "', " + std::string(Common::PurchaseOrders::STATUS_KEY) + " = '" +
                 status_list.front() + "' WHERE " + std::string(Common::PurchaseOrders::ID_KEY) + " = " +
                 id_list.front() + ";";

        userId_list.pop_front();
        productId_list.pop_front();
        paidType_list.pop_front();
        destination_list.pop_front();
        packageId_list.pop_front();
        deliveryDate_list.pop_front();
        status_list.pop_front();
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
    Common::Data values = entity[Common::COLUMN_KEY];
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

void PurchaseOrdersTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::PurchaseOrders::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
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