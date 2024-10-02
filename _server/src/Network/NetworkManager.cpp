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

    json jsonObj = readUs(socket_);

    Request request = static_cast<Request>(std::stoi(jsonObj.at("Request").get<std::string>()));

    Common::Dataset clientUsers = Serializer::deserialize(jsonObj);

    processJsonData(jsonObj);
    
    dbManager->readRequest(request, clientUsers);
    
    auto id_list = clientUsers[Common::Users::ID_KEY];
    auto name_list = clientUsers[Common::Users::NAME_KEY];
    auto surname_list = clientUsers[Common::Users::SURNAME_KEY];
    auto email_list = clientUsers[Common::Users::EMAIL_KEY];
    auto password_list = clientUsers[Common::Users::PASSWORD_KEY];

    std::cout << "Test users:" << std::endl;
        std::cout << "ID: ";
        for(auto element : id_list)
            std::cout << element + ", ";

        std::cout << "\nNAME: ";
        for(auto element : name_list)
            std::cout << element + ", ";

        std::cout << "\nSURNAME: ";
        for(auto element : surname_list)
            std::cout << element + ", ";

        std::cout << "\nEMAIL: ";
        for(auto element : email_list)
            std::cout << element + ", ";

        std::cout << "\nPASSWORD: ";
        for(auto element : password_list)
            std::cout << element + ", ";

        std::cout << "\nTest users ended" << std::endl;

    //write operation
    Common::Users user;
    user.id = "0";
    user.name = "Danylo";
    user.surname = "Plotskyh";
    user.email = "test2@gmail.com";
    user.password = "test4321";

    Common::Dataset data;

    data["TABLE:"] = {Common::Users::TABLE_NAME};
    data[Common::Users::ID_KEY] = {user.id};
    data[Common::Users::NAME_KEY] = {user.name};
    data[Common::Users::SURNAME_KEY] = {user.surname};
    data[Common::Users::EMAIL_KEY] = {user.email};
    data[Common::Users::PASSWORD_KEY] = {user.password};

    sendUs(socket_, clientUsers);
    std::cout << "Servent sent serverUsers to Client!" << std::endl;
}

json NetworkManager::readUs(bt_ip::tcp::socket & socket) {
    bt_ai::streambuf buf;
    
    bt_ai::read_until( socket, buf, "\n" );
    std::string data = bt_ai::buffer_cast<const char*>(buf.data());
    data.pop_back();
    json jsonObj = nlohmann::json::parse(data);
    return jsonObj;
}

std::string NetworkManager::read_(bt_ip::tcp::socket & socket) {
    bt_ai::streambuf buf;
    bt_ai::read_until( socket, buf, "\n" );
    std::string data = bt_ai::buffer_cast<const char*>(buf.data());
    return data;
}

void NetworkManager::send_(bt_ip::tcp::socket & socket, const std::string& message) {
    const std::string msg = message + "\n";
    bt_ai::write( socket, bt_ai::buffer(message) );
}

void NetworkManager::sendUs(bt_ip::tcp::socket & socket, const Common::Dataset user) {
    nlohmann::json user_json = Serializer::serialize(user); 
    std::string message = user_json.dump() + "\n";
    bt_ai::write( socket, bt_ai::buffer(message));
}

void NetworkManager::processJsonData(const json& jsonData) {
    for (auto it = jsonData.begin(); it != jsonData.end(); ++it) {
        std::cout << "Key: " << it.key() << std::endl;
        std::cout << "Value: " << it.value() << std::endl;
    }
}