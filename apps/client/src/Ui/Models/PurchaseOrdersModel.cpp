#include "PurchaseOrdersModel.hpp"

PurchaseOrdersModel::PurchaseOrdersModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    connect(&m_apiManager, &ApiManager::purchaseOrdersFetched, this, &PurchaseOrdersModel::onPurchaseOrdersFetched);
    connect(&m_apiManager, &ApiManager::purchaseOrdersError, this, &PurchaseOrdersModel::onPurchaseOrdersError);
}

std::vector<Common::PurchaseOrders> PurchaseOrdersModel::purchaseOrders() const {
    return m_purchaseOrders;
}

void PurchaseOrdersModel::onFetchPurchaseOrders(const std::string &userId) {
    m_apiManager.fetchPurchaseOrders(userId);
}

void PurchaseOrdersModel::onPurchaseOrdersError(const std::string &message) {
    emit purchaseOrderError(message);
}

void PurchaseOrdersModel::onPurchaseOrdersFetched(const std::vector<Common::PurchaseOrders> &orders) {
    std::cout << "[PurchaseOrdersModel::onPurchaseOrdersFetched] Purchase orders fetched" << std::endl;
    m_purchaseOrders = orders;
    emit purchaseOrdersFetched();
}