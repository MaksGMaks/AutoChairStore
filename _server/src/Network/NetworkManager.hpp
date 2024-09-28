#pragma once

#include <iostream>
#include <boost/asio.hpp>

#include "Database/DatabaseManager.hpp"
#include "../../_common/src/Repositories.hpp"
#include "../../_common/src/StructureSerializer.hpp"


namespace bt_ai = boost::asio;
namespace bt_ip = bt_ai::ip;

class NetworkManager {

public:
    NetworkManager(std::unique_ptr<DatabaseManager> dbMan);
    virtual ~NetworkManager();

    json readUs(bt_ip::tcp::socket & socket);
    std::string read_(bt_ip::tcp::socket & socket);

    void send_(bt_ip::tcp::socket & socket, const std::string& message);
    void sendUs(bt_ip::tcp::socket & socket, const Common::Dataset user);

    void listen();

private:
    void processJsonData(const json& jsonData);

    boost::asio::io_service io_service;
    boost::system::error_code error;

    std::unique_ptr<DatabaseManager> dbManager;
};