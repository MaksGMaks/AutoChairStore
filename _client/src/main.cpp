#include <iostream>
#include "Network/NetworkManager.hpp"

int main() {
    std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>();
    return 0;
}