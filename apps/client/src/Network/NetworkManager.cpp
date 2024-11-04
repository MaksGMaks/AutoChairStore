#include "NetworkManager.hpp"

NetworkManager::NetworkManager()
    : socket(io_service)  // Initialize the socket with io_service
{
    // Connection
    try {
        socket.connect(bt_ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080));
    } catch (const boost::system::system_error& e) {
        std::cerr << "Failed to connect: " << e.what() << std::endl;
    }
}

void NetworkManager::sendRequest(const Common::Dataset data, const Common::Request request) {
    nlohmann::json dataJson = Serializer::serialize(data);
    dataJson["Request"] = std::to_string(static_cast<int>(request)); 
    std::string message = dataJson.dump() + "\n";
    boost::asio::write(socket, boost::asio::buffer(message), error);
    if (!error) {
        std::cout << "Client sent request" << std::endl;
    } else {
        std::cout << "Send failed: " << error.message() << std::endl;
    }
}

Common::Dataset NetworkManager::readResponse() {
    boost::asio::streambuf receive_buffer;
    boost::asio::read_until(socket, receive_buffer, "\n", error);
    Common::Dataset serverData;
    if (error && error != boost::asio::error::eof) {
        std::cout << "Receive failed: " << error.message() << std::endl;
    } else {
        std::string data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        data.pop_back();
        auto jsonObj = nlohmann::json::parse(data);
        serverData = Serializer::deserialize(jsonObj);
    }
    return serverData;
}
