#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

#include "../../_common/src/Repositories.hpp"
#include "../../_common/src/StructureSerializer.hpp"

namespace bt_ai = boost::asio;
namespace bt_ip = bt_ai::ip;

class NetworkManager {
public:
    NetworkManager();
    void sendMessage();
    void readResponse();

private:
    boost::asio::io_service io_service;
    bt_ip::tcp::socket socket;
    boost::system::error_code error;
};