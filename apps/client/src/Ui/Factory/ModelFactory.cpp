#include "ModelFactory.hpp"

ModelFactory::ModelFactory(ApiManager &api) : IFactory(), m_api(api) {}

QSharedPointer<IModel> ModelFactory::getUserModel(QObject *parent) {
    QSharedPointer<IModel> model = QSharedPointer<UsersModel>::create(m_api, parent);
    return model;
}

