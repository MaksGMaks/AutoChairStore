#include "UsersModel.hpp"

UsersModel::UsersModel(ApiManager &apiManager, QObject *parent) 
: IModel(parent), m_apiManager(apiManager) {
    connect(&m_apiManager, &ApiManager::loginRegistrationError, this, &UsersModel::onLoginRegistrationError);
    connect(&m_apiManager, &ApiManager::userLoginSuccessfull, this, &UsersModel::onLoginUserSuccessfull);
    connect(&m_apiManager, &ApiManager::userRegisteredSuccessfully, this, &UsersModel::onRegisterUserSuccessfull);
    connect(&m_apiManager, &ApiManager::accountError, this, &UsersModel::onAccountError);
    connect(&m_apiManager, &ApiManager::userFetched, this, &UsersModel::onUserFetched);
    connect(&m_apiManager, &ApiManager::emailChangedSuccessfully, this, &UsersModel::onEmailChangedSuccessfully);
    connect(&m_apiManager, &ApiManager::passwordChangedSuccessfully, this, &UsersModel::onPasswordChangedSuccessfully);
    connect(&m_apiManager, &ApiManager::deleteAccountSuccessfully, this, &UsersModel::onDeleteAccountSuccessfull);
}

Common::Users UsersModel::user() const {
    return m_users;
}

void UsersModel::onLoginUser(const Common::Users &entity) {
    m_apiManager.loginUser(entity);
}

void UsersModel::onRegisterUser(const Common::Users &entity, const std::string &code) {
    m_apiManager.registerUser(entity, code);
}

void UsersModel::onSendCode(const std::string &email) {
    m_apiManager.sendCode(email);
}

void UsersModel::onEditUser(const Common::Users &entity) {
    m_apiManager.editUser(entity);
}

void UsersModel::onEmailChangeCode(const std::string &email) {
    m_apiManager.emailChangeCode(email);
}

void UsersModel::onChangeCode(const std::string &email) {
    m_apiManager.changeCode(email);
}

void UsersModel::onEmailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code) {
    m_apiManager.emailChange(oldEmail, newEmail, code);
}

void UsersModel::onPasswordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code) {
    m_apiManager.passwordChange(email, oldPassword, newPassword, code);
}

void UsersModel::onDeleteAccount(const std::string &email, const std::string &code) {
    m_apiManager.deleteAccount(email, code);
}

void UsersModel::onLoginRegistrationError(const std::string &errorMessage) {
    emit loginRegistrationError(errorMessage);
}

void UsersModel::onLoginUserSuccessfull(const Common::Users &entity) {
    m_users = entity;
    emit userLoginSuccessfull();
}

void UsersModel::onRegisterUserSuccessfull(const Common::Users &entity) {
    m_users = entity;
    emit userRegisteredSuccessfully();
}

void UsersModel::onAccountError(const std::string &errorMessage) {
    emit accountError(errorMessage);
}

void UsersModel::onUserFetched(const Common::Users &entity) {
    std::cout << "[UsersModel::onUserFetched] User fetched" << std::endl;
    m_users = entity;
    std::cout << "[UsersModel::onUserFetched] User name: " << m_users.name << std::endl;
    std::cout << "[UsersModel::onUserFetched] User surname: " << m_users.surname << std::endl;
    std::cout << "[UsersModel::onUserFetched] User email: " << m_users.email << std::endl;
    emit fetchUser();
}

void UsersModel::onEmailChangedSuccessfully(const Common::Users &entity) {
    m_users = entity;
    emit fetchUser();
}

void UsersModel::onPasswordChangedSuccessfully() {
    emit passwordChangedSuccessfully();
}

void UsersModel::onDeleteAccountSuccessfull() {
    emit deleteAccountSuccessfully();
}