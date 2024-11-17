#include <iostream>
#include <fstream>

#include "Database/DatabaseManager.hpp"
#include "Network/NetworkManager.hpp"
#include "Network/EmailSender.hpp"

int main() {
      std::unique_ptr<EmailSender> emailSender = nullptr;
      std::filesystem::path outputFile = std::filesystem::current_path() / "emailSettings.txt";
      std::ifstream file(outputFile);
      if(!file.is_open()) {
            std::cerr << "Email settings \'emailSettings.txt\' file not found" << std::endl;
            return -1;
      }
      std::string serverLine, portLine, from_emailLine, usernameLine, passwordLine;
      std::string server, port, from_email, username, password;
      std::getline(file, serverLine);
      std::getline(file, portLine);
      std::getline(file, from_emailLine);
      std::getline(file, usernameLine);
      std::getline(file, passwordLine);
      if(serverLine.empty() || portLine.empty() || from_emailLine.empty() || usernameLine.empty() || passwordLine.empty()) {
            std::cerr << "Email settings are not set" << std::endl;
            return -1;
      }
      else {
            server = serverLine.substr(serverLine.find("Server: ") + 8);
            port = portLine.substr(portLine.find("Port: ") + 6);
            from_email = from_emailLine.substr(from_emailLine.find("From email: ") + 12);
            username = usernameLine.substr(usernameLine.find("Username: ") + 10);
            password = passwordLine.substr(passwordLine.find("Password: ") + 10);
            if(server.empty() || port.empty() || from_email.empty() || username.empty() || password.empty()) {
                  std::cerr << "Email settings are not set" << std::endl;
                  return -1;
            }
            try {
                  emailSender = std::make_unique<EmailSender>(server, port, from_email, username, password);
            } catch (const std::exception& e) {
                  std::cerr << "Exception: " << e.what() << std::endl;
            }
      }
      try {
            emailSender->sendEmail("kozakmaksym12@gmail.com", "Test", "Test");
      } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
      }

      TableFactory tableFactory;
      std::unique_ptr<DatabaseManager> databaseManager = std::make_unique<DatabaseManager>(tableFactory); 
      std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>(std::move(databaseManager));
      network->listen();

      return 0;

}
