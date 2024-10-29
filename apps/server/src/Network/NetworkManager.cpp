#include "NetworkManager.hpp"


NetworkManager::NetworkManager(std::unique_ptr<DatabaseManager> dbMan) {
    dbManager = std::move(dbMan);
    testUserTable();
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

void NetworkManager::testUserTable() {
    std::cout << "NetworkManager is working!" << std::endl;
    Common::Request testAddUserRequest = Common::Request::ADD;
    Common::Dataset testAddUser;
    testAddUser["TABLE:"] = {Common::Users::TABLE_NAME};
    testAddUser[Common::Users::NAME_KEY] = {"John", "Michael"};
    testAddUser[Common::Users::SURNAME_KEY] = {"Doe", "Doe"};
    testAddUser[Common::Users::EMAIL_KEY] = {"test@gmail.com", "test2@gmail.com"};
    testAddUser[Common::Users::PASSWORD_KEY] = {"12345678", "12345678"};

    std::cout << "Adding user: " << testAddUser[Common::Users::NAME_KEY].front() << " " << testAddUser[Common::Users::SURNAME_KEY].front() << std::endl;
    dbManager->readRequest(testAddUserRequest, testAddUser);

    std::cout << "Result of adding: " << testAddUser["RESULT"].front() << std::endl;

    Common::Request testAddUserRequest2 = Common::Request::ADD;
    Common::Dataset testAddUser2;
    testAddUser2["TABLE:"] = {Common::Users::TABLE_NAME};
    testAddUser2[Common::Users::NAME_KEY] = {"Michael"};
    testAddUser2[Common::Users::SURNAME_KEY] = { "Doe"};
    testAddUser2[Common::Users::EMAIL_KEY] = {"test2@gmail.com"};
    testAddUser2[Common::Users::PASSWORD_KEY] = {"12345678"};

    std::cout << "Adding user: " << testAddUser2[Common::Users::NAME_KEY].front() << " " << testAddUser2[Common::Users::SURNAME_KEY].front() << std::endl;
    dbManager->readRequest(testAddUserRequest2, testAddUser2);

    std::cout << "Result of adding: " << testAddUser2["RESULT"].front() << std::endl;

    Common::Request testGetAllUsersRequest = Common::Request::GETALL;
    Common::Dataset testGetAllUsers;
    testGetAllUsers["TABLE:"] = {Common::Users::TABLE_NAME};
    dbManager->readRequest(testGetAllUsersRequest, testGetAllUsers);
    std::cout << "Users: " << std::endl;
    for(auto &user : testGetAllUsers) {
        for(auto &data : user.second) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }

    Common::Request testUpdateUserRequest = Common::Request::UPDATE;
    Common::Dataset testUpdateUser;
    testUpdateUser["TABLE:"] = {Common::Users::TABLE_NAME};
    testUpdateUser[Common::Users::ID_KEY] = {"2"};
    testUpdateUser[Common::Users::NAME_KEY] = {"James"};
    testUpdateUser[Common::Users::SURNAME_KEY] = {"Doe"};
    testUpdateUser[Common::Users::EMAIL_KEY] = {"test2@gmail.com"};
    testUpdateUser[Common::Users::PASSWORD_KEY] = {"87654321"};
    dbManager->readRequest(testUpdateUserRequest, testUpdateUser);

    std::cout << "Result of updating: " << testUpdateUser["RESULT"].front() << std::endl;

    Common::Request testDeleteUserRequest = Common::Request::DELETE;
    Common::Dataset testDeleteUser;
    testDeleteUser["TABLE:"] = {Common::Users::TABLE_NAME};
    testDeleteUser[Common::Users::ID_KEY] = {"1"};
    dbManager->readRequest(testDeleteUserRequest, testDeleteUser);

    std::cout << "Result of deleting: " << testDeleteUser["RESULT"].front() << std::endl;

    Common::Request testGetUserRequest = Common::Request::GET;
    Common::Dataset testGetUser;
    testGetUser["TABLE:"] = {Common::Users::TABLE_NAME};
    testGetUser["COLUMNS"] = {Common::Users::NAME_KEY, Common::Users::SURNAME_KEY};
    testGetUser[Common::Users::ID_KEY] = {"2"};
    dbManager->readRequest(testGetUserRequest, testGetUser);

    std::cout << "User: " << std::endl;
    for(auto &user : testGetUser) {
        for(auto &data : user.second) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }
}