#include <iostream>

#include "Database/DatabaseManager.hpp"
#include "Network/NetworkManager.hpp"


int main() {
      DatabaseManager *databaseManager = new DatabaseManager();

      NetworkManager *network = new NetworkManager(databaseManager);
      network->listen();

      return 0;
}
