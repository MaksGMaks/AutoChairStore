#pragma once

#include <iostream>
#include <sqlite3.h>

#include <nlohmann/json.hpp>

#include "DatabaseQueries.hpp"
#include "Repositories.hpp"

#include "TableFactory.hpp"

class DatabaseManager {
public:
    explicit DatabaseManager(TableFactory &tableFactory);
    ~DatabaseManager();

    void readRequest(Common::Request request, Common::Dataset &entity);
private:
    sqlite3 *dataTable;

    std::unique_ptr<ITable> users;
    std::unique_ptr<ITable> purchaseOrders;
    std::unique_ptr<ITable> products;
    std::unique_ptr<ITable> photos;
    std::unique_ptr<ITable> baseSeats;
    std::unique_ptr<ITable> childSeats;
    std::unique_ptr<ITable> luxurySeats;
    std::unique_ptr<ITable> sportSeats;
};
