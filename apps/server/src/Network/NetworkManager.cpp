#include "NetworkManager.hpp"


NetworkManager::NetworkManager(std::unique_ptr<DatabaseManager> dbMan) {
    dbManager = std::move(dbMan);
}

NetworkManager::~NetworkManager() {

}

void NetworkManager::listen() {
    //listen for new connection
    bt_ip::tcp::acceptor acceptor_(io_service, bt_ip::tcp::endpoint(bt_ip::tcp::v4(), 1234 ));
    
    //socket creation 
    bt_ip::tcp::socket socket_(io_service);
    
    //waiting for connection
    acceptor_.accept(socket_);

    nlohmann::json jsonObj = read(socket_);

    Common::Request request = static_cast<Common::Request>(std::stoi(jsonObj.at("Request").get<std::string>()));

    Common::Dataset clientUsers = Serializer::deserialize(jsonObj);
    
    dbManager->readRequest(request, clientUsers);

    send(socket_, clientUsers);
    std::cout << "Servent sent serverUsers to Client!" << std::endl;
}

nlohmann::json NetworkManager::read(bt_ip::tcp::socket & socket) {
    bt_ai::streambuf buf;
    
    bt_ai::read_until( socket, buf, "\n" );
    std::string data = bt_ai::buffer_cast<const char*>(buf.data());
    data.pop_back();
    nlohmann::json jsonObj = nlohmann::json::parse(data);
    return jsonObj;
}

void NetworkManager::send(bt_ip::tcp::socket & socket, const Common::Dataset user) {
    nlohmann::json user_json = Serializer::serialize(user); 
    std::string message = user_json.dump() + "\n";
    bt_ai::write( socket, bt_ai::buffer(message));
}
