#pragma once
#include <memory>

#include "IFactory.hpp"
#include "Ui/Models/IModel.hpp"
#include "Ui/Models/UsersModel.hpp"

class ModelFactory : public IFactory {
public:
    explicit ModelFactory(ApiManager &api);
    ~ModelFactory() = default;
    std::unique_ptr<IModel> getUserModel(QObject *parent);

private:
    ApiManager &m_api;
};