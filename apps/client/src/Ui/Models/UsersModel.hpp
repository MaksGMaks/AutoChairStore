#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class UsersModel : public IModel {
    Q_OBJECT
public:
    explicit UsersModel(ApiManager &apiManager, QObject *parent = nullptr);
    ~UsersModel();


private:
    ApiManager m_apiManager;
};