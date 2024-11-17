#include "NetworkManager.hpp"

NetworkManager::NetworkManager()
    : socket(io_service)  // Initialize the socket with io_service
{}

void NetworkManager::sendRequest(const Common::Dataset data, const Common::Request request) {
    try {
        socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080));
    } catch (const boost::system::system_error& e) {
        std::cerr << "Failed to connect: " << e.what() << std::endl;
    }
    nlohmann::json dataJson = Serializer::serialize(data);
    dataJson[Common::REQUEST_KEY] = std::to_string(static_cast<int>(request)); 
    std::string message = dataJson.dump() + "\nEND_REQUEST\n";
    boost::asio::write(socket, boost::asio::buffer(message), error);
    if (!error) {
        std::cout << "Client sent request" << std::endl;
    } else {
        std::cout << "Send failed: " << error.message() << std::endl;
    }
}

Common::Dataset NetworkManager::readResponse() {
    std::cout << "Client reading response" << std::endl;
    boost::asio::streambuf receive_buffer;
    boost::asio::read_until(socket, receive_buffer, "\nEND_RESPONCE\n", error);
    Common::Dataset serverData;
    if (error && error != boost::asio::error::eof) {
        std::cout << "Receive failed: " << error.message() << std::endl;
    } else {
        std::string data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        for(int i = 0; i < 13; i++)
            data.pop_back();
        auto jsonObj = nlohmann::json::parse(data);
        serverData = Serializer::deserialize(jsonObj);
    }
    std::cout << "Client received response" << std::endl;
    socket.close();
    std::cout << "Client closed connection" << std::endl;
    return serverData;
}
