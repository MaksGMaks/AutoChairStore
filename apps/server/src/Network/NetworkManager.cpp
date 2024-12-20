#include "NetworkManager.hpp"

NetworkManager::NetworkManager(std::shared_ptr<DatabaseManager> dbMan)
: dbManager(std::move(dbMan))
, acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080)) {
    std::cout << "[NetworkManager::NetworkManager] constructor" << std::endl;
}

void NetworkManager::listen() {
    std::cout << "[NetworkManager::listen] listening" << std::endl;
    do_accept();
    io_service.run();
}

void NetworkManager::do_accept() {
    std::cout << "[NetworkManager::do_accept] accepting" << std::endl;
    while(true) {
        std::cout << "[NetworkManager::do_accept] accepting" << std::endl;
        auto socket = boost::asio::ip::tcp::socket(io_service);
        acceptor_.accept(socket);
        nlohmann::json jsonObj = read(socket);
        Common::Request request = static_cast<Common::Request>(std::stoi(jsonObj.at(Common::REQUEST_KEY).get<std::string>()));
        Common::Dataset clientUsers = Serializer::deserialize(jsonObj);
        dbManager->readRequest(request, clientUsers);
        send(socket, clientUsers);
    }
}

nlohmann::json NetworkManager::read(boost::asio::ip::tcp::socket &socket) {
    std::cout << "[NetworkManager::read] reading" << std::endl;
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\nEND_REQUEST\n");
    std::string data = boost::asio::buffer_cast<const char*>(buf.data());
    for(int i = 0; i < 12; i++)
        data.pop_back();
    nlohmann::json jsonObj = nlohmann::json::parse(data);
    return jsonObj;
}

void NetworkManager::send(boost::asio::ip::tcp::socket &socket, const Common::Dataset user) {
    std::cout << "[NetworkManager::send] sending" << std::endl;
    nlohmann::json user_json = Serializer::serialize(user);
    std::string message = user_json.dump() + "\nEND_RESPONCE\n";

    if(message.size() > 10000) {
        std::string patch = "";
        std::string fullMessage = message;
        size_t posit = 0;
        for(; posit < fullMessage.size() - (fullMessage.size() % 10000); posit += 10000) {
            patch = fullMessage.substr(posit, 10000);
            boost::asio::async_write(socket, boost::asio::buffer(patch), [](boost::system::error_code /*ec*/, std::size_t /*length*/) {});
        }
        patch = fullMessage.substr(posit, (fullMessage.size() - (posit * 10000)));
        boost::asio::async_write(socket, boost::asio::buffer(patch), [](boost::system::error_code /*ec*/, std::size_t /*length*/) {});
    } else {
        boost::asio::async_write(socket, boost::asio::buffer(message), [](boost::system::error_code /*ec*/, std::size_t /*length*/) {});
    }
}
