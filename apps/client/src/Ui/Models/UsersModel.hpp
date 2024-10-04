#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class UsersModel : public IModel {
    Q_OBJECT
public:
    explicit UsersModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~UsersModel() = default;

signals:
    void userAdded();
    void userChanged();
    void userEdited();
    void userDeleted();

public slots:
    void addUser(const Common::Users &entity);
    void fetchUser();
    void editUser(const Common::Users &entity);
    void deleteUser(const std::string &id);

private slots:
    void onUserAdded();
    void onUserUpdated();
    void onUserDeleted();
    void onUserList(const std::vector<Common::Users> &users);

private:
    ApiManager &m_apiManager;
};