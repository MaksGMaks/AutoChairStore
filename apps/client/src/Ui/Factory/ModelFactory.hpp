#pragma once
#include <QSharedPointer>

#include "IFactory.hpp"
#include "Ui/Models/IModel.hpp"
#include "Ui/Models/UsersModel.hpp"

class ModelFactory : public IFactory {
public:
    explicit ModelFactory(ApiManager &api);
    ~ModelFactory() = default;
    IModel *getUserModel(QObject *parent);

private:
    ApiManager &m_api;
};