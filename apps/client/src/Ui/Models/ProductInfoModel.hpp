#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class ProductInfoModel : public IModel {
    Q_OBJECT
public:
    explicit ProductInfoModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~ProductInfoModel() = default;

    QVector<Common::ProductInfo> productInfo() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::ProductInfo> m_productInfo;
};
