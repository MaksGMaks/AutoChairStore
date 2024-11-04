#include "CatalogueViewModel.hpp"

CatalogueViewModel::CatalogueViewModel(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent)
: IViewModel(parent)
, m_productsModel(productsModel)
, m_photosModel(photosModel) {
    connect(this, &CatalogueViewModel::modelFetchProducts, m_productsModel, &ProductsModel::fetchProducts);
    connect(m_productsModel, &ProductsModel::productsFetched, this, &CatalogueViewModel::onProductsFetched);
}

QVector<displayData::Products> CatalogueViewModel::products() const {
    return m_products;
}

void CatalogueViewModel::onFetchProducts() {
    emit modelFetchProducts();
}

void CatalogueViewModel::onProductsFetched() {
    m_products.clear();

    for(const auto &product : m_productsModel->products()) {
        m_products.push_back(convertToDisplayData(product));
    }
    emit productsFetched();
}

displayData::Products CatalogueViewModel::convertToDisplayData(const Common::Products &product) {
    displayData::Products data;
    data.id = QString::fromStdString(product.id);
    data.name = QString::fromStdString(product.productName);
    data.type = QString::fromStdString(product.productType);
    data.photo = QString::fromStdString(m_photosModel->getPhotoById(product.productType, product.productTypeId));
    data.price = QString::fromStdString(product.price);
    data.priceUnit = QString::fromStdString(product.priceUnit);
    data.discount = QString::fromStdString(product.discount);
    data.hasDiscount = QString::fromStdString(product.hasDiscount);

    return data;
}