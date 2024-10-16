#include "UsersModel.hpp"

UsersModel::UsersModel(ApiManager &apiManager, QObject *parent) 
: IModel(parent), m_apiManager(apiManager) {
    connect(&m_apiManager, &ApiManager::loginRegistrationError, this, &UsersModel::onLoginRegistrationError);
    connect(&m_apiManager, &ApiManager::userLoginSuccessfull, this, &UsersModel::onLoginUserSuccessfull);
    connect(&m_apiManager, &ApiManager::codeSentSuccessfully, this, &UsersModel::onCodeSentSuccessfully);
    connect(&m_apiManager, &ApiManager::accountError, this, &UsersModel::onAccountError);
    connect(&m_apiManager, &ApiManager::userFetched, this, &UsersModel::onUserFetched);
    connect(&m_apiManager, &ApiManager::emailCodeSentSuccessfully, this, &UsersModel::onEmailCodeSentSuccessfully);
    connect(&m_apiManager, &ApiManager::changeCodeSentSuccessfully, this, &UsersModel::onChangeCodeSentSuccessfully);
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

void UsersModel::onRegisterUser(const Common::Users &entity) {
    m_apiManager.registerUser(entity);
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

void UsersModel::onLoginRegistrationError(const QString &errorMessage) {
    emit loginRegistrationError(errorMessage);
}

void UsersModel::onLoginUserSuccessfull() {
    emit userLoginSuccessfull();
}

void UsersModel::onRegisterUserSuccessfull() {
    emit userLoginSuccessfull();
}

void UsersModel::onCodeSentSuccessfully() {
    emit codeSentSuccessfully();
}

void UsersModel::onAccountError(const QString &errorMessage) {
    emit accountError(errorMessage);
}

void UsersModel::onUserFetched(const Common::Users &entity) {
    m_users = entity;
    emit fetchUser();
}

void UsersModel::onEmailCodeSentSuccessfully() {
    emit emailCodeSentSuccessfully();
}

void UsersModel::onChangeCodeSentSuccessfully() {
    emit changeCodeSentSuccessfully();
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