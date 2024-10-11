#include "ProductInfoModel.hpp"

ProductInfoModel::ProductInfoModel(ApiManager &apiManager, QObject *parent) 
    : IModel(parent), 
      m_apiManager(apiManager) {
}

QVector<Common::ProductInfo> ProductInfoModel::productInfo() const {
    return m_productInfo;
}