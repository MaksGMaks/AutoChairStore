#pragma once

#include <iostream>
#include <sqlite3.h>

#include <nlohmann/json.hpp>

#include "DatabaseQueries.hpp"
#include "Repositories.hpp"
#include "Network/EmailSender.hpp"

#include "TableFactory.hpp"

#include "Tests.hpp"

class DatabaseManager {
public:
    explicit DatabaseManager(TableFactory &tableFactory, std::unique_ptr<EmailSender> emailSender);
    ~DatabaseManager() = default;

    void readRequest(Common::Request request, Common::Dataset &entity);
private:
    sqlite3 *dataTable;
    std::unique_ptr<EmailSender> m_emailSender;

    std::unique_ptr<ITable> users;
    std::unique_ptr<ITable> purchaseOrders;
    std::unique_ptr<ITable> products;
    std::unique_ptr<ITable> photos;
    std::unique_ptr<ITable> baseSeats;
    std::unique_ptr<ITable> childSeats;
    std::unique_ptr<ITable> luxurySeats;
    std::unique_ptr<ITable> sportSeats;
    std::unique_ptr<ITable> verifications;

    // Tests
    void runTests();
};
