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
    Common::Users user;
    user.id = "2";
    user.name = "Maks";
    user.surname = "Kozak";
    user.email = "test@gmail.com";
    user.password = "test1234";

    std::cout << "Test user to send:" << std::endl;
    std::cout << user.id << std::endl;
    std::cout << user.name << std::endl;
    std::cout << user.surname << std::endl;
    std::cout << user.email << std::endl;
    std::cout << user.password << std::endl;
    std::cout << "Test users to send ended" << std::endl;

    Common::Users user2;
    user2.id = "1";
    user2.name = "Misha";
    user2.surname = "Oleksjuk";
    user2.email = "test3@gmail.com";
    user2.password = "1234test";

    std::cout << "Test user2 to send:" << std::endl;
    std::cout << user2.id << std::endl;
    std::cout << user2.name << std::endl;
    std::cout << user2.surname << std::endl;
    std::cout << user2.email << std::endl;
    std::cout << user2.password << std::endl;
    std::cout << "Test users to send ended" << std::endl;

    Common::Dataset data1;

    data1["TABLE:"] = {Common::Users::TABLE_NAME};
    data1["COLUMNS"] = {Common::Users::NAME_KEY, Common::Users::SURNAME_KEY};
    data1[Common::Users::ID_KEY] = {user.id};
    data1[Common::Users::NAME_KEY] = {user.name};
    data1[Common::Users::SURNAME_KEY] = {user.surname};
    data1[Common::Users::EMAIL_KEY] = {user.email};
    data1[Common::Users::PASSWORD_KEY] = {user.password};

    Common::Dataset data2;
    data2["TABLE:"] = {Common::Users::TABLE_NAME};
    data2[Common::Users::ID_KEY] = {user2.id};
    data2[Common::Users::NAME_KEY] = {user2.name};
    data2[Common::Users::SURNAME_KEY] = {user2.surname};
    data2[Common::Users::EMAIL_KEY] = {user2.email};
    data2[Common::Users::PASSWORD_KEY] = {user2.password};

    Common::Dataset dataJ;
    dataJ["TABLE:"] = {Common::Users::TABLE_NAME};

    nlohmann::json user_json = Serializer::serialize(data1);
    json dataJson = Serializer::serialize(data1);
    dataJson["Request"] = std::to_string(static_cast<int>(Request::GETALL)); 
    std::string message = dataJson.dump() + "\n";
    boost::asio::write(socket, boost::asio::buffer(message), error);
    if (!error) {
        std::cout << "Client sent hello message!" << std::endl;
    } else {
        std::cout << "Send failed: " << error.message() << std::endl;
    }
}

void NetworkManager::readResponse() {
    boost::asio::streambuf receive_buffer;
    boost::asio::read_until(socket, receive_buffer, "\n", error);
    Common::Dataset serverUsers;
    if (error && error != boost::asio::error::eof) {
        std::cout << "Receive failed: " << error.message() << std::endl;
    } else {
        std::string data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        data.pop_back();
        auto jsonObj = nlohmann::json::parse(data);
        serverUsers = Serializer::deserialize(jsonObj);

        auto id_list = serverUsers[Common::Users::ID_KEY];
        auto name_list = serverUsers[Common::Users::NAME_KEY];
        auto surname_list = serverUsers[Common::Users::SURNAME_KEY];
        auto email_list = serverUsers[Common::Users::EMAIL_KEY];
        auto password_list = serverUsers[Common::Users::PASSWORD_KEY];

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
    
        
    }
}
