#pragma once

#include "IModelFactory.hpp"

class ModelFactory : public IModelFactory {
public:
    explicit ModelFactory(ApiManager &api);
    ~ModelFactory() = default;
    
    PhotosModel *getPhotosModel(QObject *parent = nullptr) override;
    ProductsModel *getProductsModel(QObject *parent = nullptr) override;
    PurchaseOrdersModel *getPurchaseOrdersModel(QObject *parent = nullptr) override;
    UsersModel *getUserModel(QObject *parent = nullptr) override;

private:
    ApiManager &m_api;
};