#pragma once

#include "IModelFactory.hpp"

class ModelFactory : public IModelFactory {
public:
    explicit ModelFactory(ApiManager &api);
    ~ModelFactory() = default;
    
    InventoryModel *getInventoryModel(QObject *parent = nullptr) override;
    PhotosModel *getPhotosModel(QObject *parent = nullptr) override;
    ProductInfoModel *getProductInfoModel(QObject *parent = nullptr) override;
    ProductsModel *getProductsModel(QObject *parent = nullptr) override;
    PurchaseOrdersModel *getPurchaseOrdersModel(QObject *parent = nullptr) override;
    SuppliersModel *getSuppliersModel(QObject *parent = nullptr) override;
    UsersModel *getUserModel(QObject *parent = nullptr) override;


private:
    ApiManager &m_api;
};