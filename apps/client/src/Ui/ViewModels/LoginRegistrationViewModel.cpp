#include "LoginRegistrationViewModel.hpp"

LoginRegistrationViewModel::LoginRegistrationViewModel(UsersModel *model, QObject *parent)
: IViewModel(parent), 
m_users(model) {
    connect(m_users, &UsersModel::loginRegistrationError, this, &LoginRegistrationViewModel::onErrorOccurred);
    connect(m_users, &UsersModel::codeSentSuccessfully, this, &LoginRegistrationViewModel::onCodeSentSuccessfully);

    connect(this, &LoginRegistrationViewModel::modelLoginUser, m_users, &UsersModel::onLoginUser);
    connect(this, &LoginRegistrationViewModel::modelRegisterUser, m_users, &UsersModel::onRegisterUser);
    connect(this, &LoginRegistrationViewModel::modelSendCode, m_users, &UsersModel::onSendCode);
}

void LoginRegistrationViewModel::onLoginUser(const displayData::Users &entity) {
    emit modelLoginUser(convertToEntity(entity));
}

void LoginRegistrationViewModel::onRegisterUser(const displayData::Users &entity) {
    emit modelRegisterUser(convertToEntity(entity));
}

void LoginRegistrationViewModel::onSendCode(const QString &email) {
    emit modelSendCode(email.toStdString());
}

void LoginRegistrationViewModel::onCodeSentSuccessfully() {
    emit codeSentSuccessfully();
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