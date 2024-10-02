#include "UsersModel.hpp"

UsersModel::UsersModel(ApiManager &apiManager, QObject *parent) : IModel(parent), m_apiManager(apiManager)
{
}

UsersModel::~UsersModel()
{
}
