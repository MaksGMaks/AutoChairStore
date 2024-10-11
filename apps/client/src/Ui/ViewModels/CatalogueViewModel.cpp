#include "CatalogueViewModel.hpp"

CatalogueViewModel::CatalogueViewModel(ProductsModel *model, QObject *parent)
    : IViewModel(model, parent), 
      m_products(model) {
}