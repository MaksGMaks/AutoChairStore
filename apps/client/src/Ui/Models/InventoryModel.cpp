#include "InventoryModel.hpp"

InventoryModel::InventoryModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    
}

QVector<Common::Inventory> InventoryModel::inventory() const {
    return m_inventory;
}