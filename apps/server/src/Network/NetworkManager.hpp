#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <nlohmann/json.hpp>

#include "Database/DatabaseManager.hpp"
#include "Repositories.hpp"
#include "StructureSerializer.hpp"

class NetworkManager {
public:
    NetworkManager(std::unique_ptr<DatabaseManager> dbMan);
    ~NetworkManager() = default;

    nlohmann::json read(boost::asio::ip::tcp::socket &socket);
    void send(boost::asio::ip::tcp::socket &socket, const Common::Dataset user);

    void listen();

private:
    void do_accept();

    boost::asio::io_service io_service;

    std::unique_ptr<DatabaseManager> dbManager;
    boost::asio::ip::tcp::acceptor acceptor_;
};
