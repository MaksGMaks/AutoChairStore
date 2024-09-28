#include <iostream>
#include "Network/NetworkManager.hpp"

int main() {
    NetworkManager *network = new NetworkManager();
    network->sendMessage();
    network->readResponse();
    return 0;
}