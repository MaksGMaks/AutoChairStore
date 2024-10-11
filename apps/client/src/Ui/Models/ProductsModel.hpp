#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class ProductsModel : public IModel {
    Q_OBJECT
public:
    explicit ProductsModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~ProductsModel() = default;

    QVector<Common::Products> products() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::Products> m_products;
};
