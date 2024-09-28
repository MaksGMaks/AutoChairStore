#pragma once

#include <iostream>
#include <sqlite3.h>

#include <nlohmann/json.hpp>

#include "DatabaseQueries.hpp"
#include "../../_common/src/Repositories.hpp"

#include "ITableFactory.hpp"

using json = nlohmann::json;

class DatabaseManager {
public:
    explicit DatabaseManager(std::unique_ptr<ITableFactory> tableFactory);
    ~DatabaseManager();

    void readRequest(Request request, Common::Dataset &entity);
private:
    sqlite3 *dataTable;

    std::unique_ptr<ITable> users;
    std::unique_ptr<ITable> suppliers;
    std::unique_ptr<ITable> purchaseOrders;
    std::unique_ptr<ITable> products;
    std::unique_ptr<ITable> productInfo;
    std::unique_ptr<ITable> photos;
    std::unique_ptr<ITable> inventory;
};
