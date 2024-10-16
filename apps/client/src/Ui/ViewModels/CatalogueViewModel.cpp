#include "CatalogueViewModel.hpp"

CatalogueViewModel::CatalogueViewModel(ProductsModel *model, QObject *parent)
: IViewModel(parent), 
m_products(model) {
}