#include <iostream>
#include "Network/NetworkManager.hpp"

int main() {
    std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>();

    Common::Dataset data;
    data["TABLE:"] = {Common::Users::TABLE_NAME};
    data[Common::Users::NAME_KEY] = {"John"};
    data[Common::Users::SURNAME_KEY] = {"Doe"};
    data[Common::Users::EMAIL_KEY] = {"test1"};
    data[Common::Users::PASSWORD_KEY] = {"12345678"};

    Common::Request request = Common::Request::ADD;
    network->sendRequest(data, request);

    Common::Dataset data2 = network->readResponse();

    for(auto &user : data2) {
        for(auto &data : user.second) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}