#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class InventoryModel : public IModel {
    Q_OBJECT
public:
    explicit InventoryModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~InventoryModel() = default;

    QVector<Common::Inventory> inventory() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::Inventory> m_inventory;
};