#include <iostream>

#include "Database/DatabaseManager.hpp"
#include "Network/NetworkManager.hpp"


int main() {
      TableFactory tableFactory;
      std::unique_ptr<DatabaseManager> databaseManager = std::make_unique<DatabaseManager>(tableFactory); 
      std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>(std::move(databaseManager));
      network->listen();

      return 0;
}
