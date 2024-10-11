#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/ProductsModel.hpp"

class CatalogueViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit CatalogueViewModel(ProductsModel *model, QObject *parent = nullptr);
    virtual ~CatalogueViewModel() = default;

private:
    ProductsModel *m_products;
    
};