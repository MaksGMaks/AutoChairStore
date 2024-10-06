#include "ModelFactory.hpp"

ModelFactory::ModelFactory(ApiManager &api) : IFactory(), m_api(api) {}

IModel* ModelFactory::getUserModel(QObject *parent) {
    IModel *model = new UsersModel(m_api, parent);
    return model;
}

