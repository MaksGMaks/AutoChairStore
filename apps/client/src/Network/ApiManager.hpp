#pragma once

#include <QObject>
#include "NetworkManager.hpp"

class ApiManager : public QObject {
    Q_OBJECT
public:
    ApiManager(NetworkManager &NetworkManager);
    virtual ~ApiManager() = default;

    // Login and registration
    void loginUser(const Common::Users &entity);
    void registerUser(const Common::Users &entity);
    void sendCode(const std::string &email);

    //  Account
    void editUser(const Common::Users &entity);
    void emailChangeCode(const std::string &email);
    void changeCode(const std::string &email);
    void emailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code);
    void passwordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code);
    void deleteAccount(const std::string &email, const std::string &code);

signals:
    // Login and registration
    void loginRegistrationError(const QString &errorMessage);
    void userLoginSuccessfull();
    void codeSentSuccessfully();

    // Account
    void accountError(const QString &errorMessage);
    void userFetched(const Common::Users &entity);
    void emailCodeSentSuccessfully();
    void changeCodeSentSuccessfully();
    void emailChangedSuccessfully(const Common::Users &entity);
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

private:
    NetworkManager &m_networkManager;
};