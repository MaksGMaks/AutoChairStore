#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PhotosModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class CatalogueViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit CatalogueViewModel(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent = nullptr);
    virtual ~CatalogueViewModel() = default;

    QVector<displayData::Products> products() const;

signals:
    void modelFetchProducts();
    void productsFetched();

public slots:
    void onFetchProducts();
    void onProductsFetched();

private:
    ProductsModel *m_productsModel;
    PhotosModel *m_photosModel;

    QVector<displayData::Products> m_products;

    displayData::Products convertToDisplayData(const Common::Products &product);
};