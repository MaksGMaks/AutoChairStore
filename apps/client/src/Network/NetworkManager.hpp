#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

#include "Repositories.hpp"
#include "StructureSerializer.hpp"

namespace bt_ai = boost::asio;
namespace bt_ip = bt_ai::ip;

class NetworkManager {
public:
    NetworkManager();
    void sendRequest(const Common::Dataset data, const Common::Request request);
    Common::Dataset readResponse();

private:
    boost::asio::io_service io_service;
    bt_ip::tcp::socket socket;
    boost::system::error_code error;
};