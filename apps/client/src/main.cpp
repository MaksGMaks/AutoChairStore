#include <iostream>
#include "Network/NetworkManager.hpp"

int main() {
    std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>();

    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::Users::TABLE_NAME};
    data[Common::COLUMN_KEY] = {Common::Users::EMAIL_KEY};
    data[Common::Users::EMAIL_KEY] = {"test2"};

    Common::Request request = Common::Request::GETSPECIAL;
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