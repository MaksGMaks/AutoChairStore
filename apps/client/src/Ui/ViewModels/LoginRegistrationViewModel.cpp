#include "LoginRegistrationViewModel.hpp"

LoginRegistrationViewModel::LoginRegistrationViewModel(UsersModel *model, QObject *parent)
    : IViewModel(model, parent), 
      m_users(model) {
    connect(m_users, &UsersModel::loginSuccessfull, this,
            &LoginRegistrationViewModel::onUserLogin);
    connect(m_users, &UsersModel::loginFail, this,
            &LoginRegistrationViewModel::onUserLoginFailed);
    
    connect(m_users, &UsersModel::registrationSuccessfull, this,
            &LoginRegistrationViewModel::onUserRegistered);
    connect(m_users, &UsersModel::registrationFail, this,
            &LoginRegistrationViewModel::onUserRegisterationFailed);
    
    connect(m_users, &UsersModel::errorOccurred, this,
            &LoginRegistrationViewModel::errorOccurred);
}

displayData::Users LoginRegistrationViewModel::user() const {
    return m_usersData;
}

void LoginRegistrationViewModel::onUserLogin() {
    emit loginSuccessfull();
}

void LoginRegistrationViewModel::onUserLoginFailed() {
    emit loginFail();
}

void LoginRegistrationViewModel::onUserRegistered() {
    emit registrationSuccessfull();
}

void LoginRegistrationViewModel::onUserRegisterationFailed() {
    emit registrationFail();
}

displayData::Users LoginRegistrationViewModel::convertToDisplayData(const Common::Users &entity) {
    displayData::Users data;
    data.id = QString::fromStdString(entity.id);
    data.name = QString::fromStdString(entity.name);
    data.surname = QString::fromStdString(entity.surname);
    data.email = QString::fromStdString(entity.email);
    data.password = QString::fromStdString(entity.password);

    return data;
}

Common::Users LoginRegistrationViewModel::convertToEntity(const displayData::Users &entity) {
    Common::Users data;
    data.id = entity.id.toStdString();
    data.email = entity.email.toStdString();
    data.password = entity.password.toStdString();
    data.name = entity.name.toStdString();
    data.surname = entity.surname.toStdString();

    return data;
}