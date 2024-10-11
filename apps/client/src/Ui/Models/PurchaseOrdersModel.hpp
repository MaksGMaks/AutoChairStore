#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class PurchaseOrdersModel : public IModel {
    Q_OBJECT
public:
    explicit PurchaseOrdersModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~PurchaseOrdersModel() = default;

    QVector<Common::PurchaseOrders> purchaseOrders() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::PurchaseOrders> m_purchaseOrders;
};