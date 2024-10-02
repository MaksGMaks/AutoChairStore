#include <iostream>

#include "Database/DatabaseManager.hpp"
#include "Network/NetworkManager.hpp"


int main() {
      std::unique_ptr<ITableFactory> tableFactory = std::make_unique<ITableFactory>();
      std::unique_ptr<DatabaseManager> databaseManager = std::make_unique<DatabaseManager>(std::move(tableFactory)); 
      std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>(std::move(databaseManager));
      network->listen();

      return 0;
}
