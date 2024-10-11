#include "ProductsModel.hpp"

ProductsModel::ProductsModel(ApiManager &apiManager, QObject *parent)
    : IModel(parent), 
      m_apiManager(apiManager) {
    
}

QVector<Common::Products> ProductsModel::products() const {
    return m_products;
}