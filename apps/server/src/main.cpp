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
      std::string from_emailLine, usernameLine, passwordLine;
      std::string from_email, username, password;
      std::getline(file, from_emailLine);
      std::getline(file, usernameLine);
      std::getline(file, passwordLine);
      if(from_emailLine.empty() || usernameLine.empty() || passwordLine.empty()) {
            std::cerr << "Email settings are not set" << std::endl;
            return -1;
      }
      else {
            from_email = from_emailLine.substr(from_emailLine.find("From email: ") + 12);
            username = usernameLine.substr(usernameLine.find("Username: ") + 10);
            password = passwordLine.substr(passwordLine.find("Password: ") + 10);
            if(from_email.empty() || username.empty() || password.empty()) {
                  std::cerr << "Email settings are not set" << std::endl;
                  return -1;
            }
            emailSender = std::make_unique<EmailSender>(from_email, username, password);     
      }
            
      TableFactory tableFactory;
      std::unique_ptr<DatabaseManager> databaseManager = std::make_unique<DatabaseManager>(tableFactory, std::move(emailSender)); 
      std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>(std::move(databaseManager));
      network->listen();

      return 0;

}
