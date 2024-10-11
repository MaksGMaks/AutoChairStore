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
    void userChanged();

    void loginSuccessfull();
    void loginFail();

    void registrationSuccessfull();
    void registrationFail();

public slots:
    void loginUser(const Common::Users &entity);
    void registerUser(const Common::Users &entity);

    void fetchUser(const std::string &id);
    void editUser(const Common::Users &entity);
    void deleteUser(const std::string &id);

private slots:
    void onUSerLogin();
    void onUserRegistered();
    void onUserUpdated();
    void onUserDeleted();
    void onUser(const Common::Users &entity);

private:
    ApiManager &m_apiManager;
    Common::Users m_users;
};