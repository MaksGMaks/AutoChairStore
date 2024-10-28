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
    void loginRegistrationError(const std::string &errorMessage);

    void userLoginSuccessfull();
    void userRegisteredSuccessfully();
    void codeSentSuccessfully();

    // Account
    void accountError(const std::string &errorMessage);

    void fetchUser();
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

public slots:
    // Login and registration
    void onLoginUser(const Common::Users &entity);
    void onRegisterUser(const Common::Users &entity, const std::string &code);
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
    void onLoginRegistrationError(const std::string &errorMessage);
    void onLoginUserSuccessfull(const Common::Users &entity);
    void onRegisterUserSuccessfull(const Common::Users &entity);

    // Account
    void onAccountError(const std::string &errorMessage);
    void onUserFetched(const Common::Users &entity);
    void onEmailChangedSuccessfully(const Common::Users &entity);
    void onPasswordChangedSuccessfully();
    void onDeleteAccountSuccessfull();

private:
    ApiManager &m_apiManager;
    Common::Users m_users;
};