#include "ModelFactory.hpp"

ModelFactory::ModelFactory(ApiManager &api) : IModelFactory(), m_api(api) {}

PhotosModel* ModelFactory::getPhotosModel(QObject *parent) {
    return new PhotosModel(m_api, parent);
}

ProductsModel* ModelFactory::getProductsModel(QObject *parent) {
    return new ProductsModel(m_api, parent);
}

PurchaseOrdersModel* ModelFactory::getPurchaseOrdersModel(QObject *parent) {
    return new PurchaseOrdersModel(m_api, parent);
}

UsersModel* ModelFactory::getUserModel(QObject *parent) {
    return new UsersModel(m_api, parent);
}