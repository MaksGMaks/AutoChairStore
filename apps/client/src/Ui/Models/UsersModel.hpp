#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class UsersModel : public IModel {
    Q_OBJECT
public:
    explicit UsersModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~UsersModel() = default;

    Common::Users user() const;

signals:
    // Login and registration
    void loginRegistrationError(const QString &errorMessage);

    void userLoginSuccessfull();
    void codeSentSuccessfully();

    // Account
    void accountError(const QString &errorMessage);

    void fetchUser();
    void emailCodeSentSuccessfully();
    void changeCodeSentSuccessfully();
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

public slots:
    // Login and registration
    void onLoginUser(const Common::Users &entity);
    void onRegisterUser(const Common::Users &entity);
    void onSendCode(const std::string &email);

    // Account
    void onEditUser(const Common::Users &entity);
    void onEmailChangeCode(const std::string &email);
    void onChangeCode(const std::string &email);
    void onEmailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code);
    void onPasswordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code);
    void onDeleteAccount(const std::string &email, const std::string &code);

private slots:
    // Login and registration
    void onLoginRegistrationError(const QString &errorMessage);
    void onLoginUserSuccessfull();
    void onRegisterUserSuccessfull();
    void onCodeSentSuccessfully();

    // Account
    void onAccountError(const QString &errorMessage);
    void onUserFetched(const Common::Users &entity);
    void onEmailCodeSentSuccessfully();
    void onChangeCodeSentSuccessfully();
    void onEmailChangedSuccessfully(const Common::Users &entity);
    void onPasswordChangedSuccessfully();
    void onDeleteAccountSuccessfull();

private:
    ApiManager &m_apiManager;
    Common::Users m_users;
};