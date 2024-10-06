#include "UsersModel.hpp"

UsersModel::UsersModel(ApiManager &apiManager, QObject *parent) 
    : IModel(parent), m_apiManager(apiManager) {
}


void UsersModel::addUser(const Common::Users &entity) {
    Common::Users user = entity;
}

void UsersModel::fetchUser() {

}

void UsersModel::editUser(const Common::Users &entity) {
    Common::Users user = entity;
}

void UsersModel::deleteUser(const std::string &id) {
    std::string userId = id;
}


void UsersModel::onUserAdded() {

}

void UsersModel::onUserUpdated() {

}

void UsersModel::onUserDeleted() {

}

void UsersModel::onUser(const Common::Users &entity) {
    Common::Users user = entity;
}