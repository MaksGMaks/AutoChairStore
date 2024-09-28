#include "NetworkManager.hpp"

NetworkManager::NetworkManager()
    : socket(io_service)  // Initialize the socket with io_service
{
    // Connection
    try {
        socket.connect(bt_ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    } catch (const boost::system::system_error& e) {
        std::cerr << "Failed to connect: " << e.what() << std::endl;
    }
}

void NetworkManager::sendMessage() {
    
}

void NetworkManager::readResponse() {
    
}
