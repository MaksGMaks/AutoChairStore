#include "PurchaseOrdersModel.hpp"

PurchaseOrdersModel::PurchaseOrdersModel(ApiManager &apiManager, QObject *parent)
    : IModel(parent), 
      m_apiManager(apiManager) {
    
}

QVector<Common::PurchaseOrders> PurchaseOrdersModel::purchaseOrders() const {
    return m_purchaseOrders;
}