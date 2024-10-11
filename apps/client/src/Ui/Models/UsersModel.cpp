#include "UsersModel.hpp"

UsersModel::UsersModel(ApiManager &apiManager, QObject *parent) 
    : IModel(parent), m_apiManager(apiManager) {
}

Common::Users UsersModel::user() const {
    return m_users;
}

void UsersModel::loginUser(const Common::Users &entity) {
    Common::Users user = entity;
}

void UsersModel::registerUser(const Common::Users &entity) {
    Common::Users user = entity;
}

void UsersModel::fetchUser(const std::string &id) {
    std::string userId = id;
}

void UsersModel::editUser(const Common::Users &entity) {
    Common::Users user = entity;
}

void UsersModel::deleteUser(const std::string &id) {
    std::string userId = id;
}

void UsersModel::onUSerLogin() {

}

void UsersModel::onUserRegistered() {

}

void UsersModel::onUserUpdated() {

}

void UsersModel::onUserDeleted() {

}

void UsersModel::onUser(const Common::Users &entity) {
    m_users = entity;
    emit userChanged();
}