#include "ApiManager.hpp"

ApiManager::ApiManager(NetworkManager &networkManager) : m_networkManager(networkManager) {

}

void ApiManager::loginUser(const Common::Users &entity) {
    std::cout << "[ApiManager::loginUser] Logging in user" << std::endl;
    Common::Users user = entity;
}

void ApiManager::registerUser(const Common::Users &entity) {
    std::cout << "[ApiManager::registerUser] Registering user" << std::endl;
    Common::Users user = entity;
}

void ApiManager::sendCode(const std::string &email) {
    std::cout << "[ApiManager::sendCode] Sending code to email: " << email << std::endl;
}

void ApiManager::editUser(const Common::Users &entity) {
    std::cout << "[ApiManager::editUser] Editing user" << std::endl;
    Common::Users user = entity;
}

void ApiManager::emailChangeCode(const std::string &email) {
    std::cout << "[ApiManager::emailChangeCode] Sending email change code to email: " << email << std::endl;
}

void ApiManager::changeCode(const std::string &email) {
    std::cout << "[ApiManager::changeCode] Sending password change code to email: " << email << std::endl;
}

void ApiManager::emailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code) {
    std::cout << "[ApiManager::emailChange] Changing email" << std::endl;
    std::string oldEmail_ = oldEmail;
    std::string newEmail_ = newEmail;
    std::string code_ = code;
}

void ApiManager::passwordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code) {
    std::cout << "[ApiManager::passwordChange] Changing password" << std::endl;
    std::string email_ = email;
    std::string oldPassword_ = oldPassword;
    std::string newPassword_ = newPassword;
    std::string code_ = code;
}

void ApiManager::deleteAccount(const std::string &email, const std::string &code) {
    std::cout << "[ApiManager::deleteAccount] Deleting account" << std::endl;
    std::string email_ = email;
    std::string code_ = code;
}

