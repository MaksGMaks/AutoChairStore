#include "ModelFactory.hpp"

ModelFactory::ModelFactory(ApiManager &api) : IFactory(), m_api(api) {}

std::unique_ptr<IModel> ModelFactory::getUserModel(QObject *parent) {
    std::unique_ptr<IModel> model = std::make_unique<UsersModel>(m_api, parent);
    return model;
}

