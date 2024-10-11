#include "SuppliersModel.hpp"

SuppliersModel::SuppliersModel(ApiManager &apiManager, QObject *parent)
    : IModel(parent), 
      m_apiManager(apiManager) {
    
}

QVector<Common::Suppliers> SuppliersModel::suppliers() const {
    return m_suppliers;
}
