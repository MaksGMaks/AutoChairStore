#pragma once

#include <iostream>
#include <boost/asio.hpp>

#include "Database/DatabaseManager.hpp"
#include "Repositories.hpp"
#include "StructureSerializer.hpp"


namespace bt_ai = boost::asio;
namespace bt_ip = bt_ai::ip;

class NetworkManager {

public:
    NetworkManager(std::unique_ptr<DatabaseManager> dbMan);
    virtual ~NetworkManager();

    nlohmann::json read(bt_ip::tcp::socket & socket);
    void send(bt_ip::tcp::socket & socket, const Common::Dataset user);

    void listen();

private:
    boost::asio::io_service io_service;
    boost::system::error_code error;

    std::unique_ptr<DatabaseManager> dbManager;
};