#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class PurchaseOrdersModel : public IModel {
    Q_OBJECT
public:
    explicit PurchaseOrdersModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~PurchaseOrdersModel() = default;

    std::vector<Common::PurchaseOrders> purchaseOrders() const;

signals:
    void purchaseOrderError(const std::string &message);
    void purchaseOrdersFetched();

public slots:
    void onFetchPurchaseOrders(const std::string &userId);

private slots:
    void onPurchaseOrdersFetched(const std::vector<Common::PurchaseOrders> &orders);
    void onPurchaseOrdersError(const std::string &message);

private:
    ApiManager &m_apiManager;
    std::vector<Common::PurchaseOrders> m_purchaseOrders;
};