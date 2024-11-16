#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

#include "Repositories.hpp"
#include "StructureSerializer.hpp"

class NetworkManager {
public:
    NetworkManager();
    void sendRequest(const Common::Dataset data, const Common::Request request);
    Common::Dataset readResponse();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;
    boost::system::error_code error;
};