#include "ProductPageViewModel.hpp"

ProductPageViewModel::ProductPageViewModel(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent)
: IViewModel(parent)
, m_productsModel(productsModel)
, m_photosModel(photosModel) {
    connect(m_productsModel, &ProductsModel::productsFetched, this, &ProductPageViewModel::onProductsFetched);
    connect(m_productsModel, &ProductsModel::baseSeatLoadedSuccess, this, &ProductPageViewModel::onLoadBaseSeatSuccess);
    connect(m_productsModel, &ProductsModel::childSeatLoadedSuccess, this, &ProductPageViewModel::onLoadChildSeatSuccess);
    connect(m_productsModel, &ProductsModel::sportSeatLoadedSuccess, this, &ProductPageViewModel::onLoadSportSeatSuccess);
    connect(m_productsModel, &ProductsModel::luxurySeatLoadedSuccess, this, &ProductPageViewModel::onLoadLuxurySeatSuccess);

    connect(this, &ProductPageViewModel::modelLoadSeat, m_productsModel, &ProductsModel::onLoadSeat);
}

QVector<displayData::Products> ProductPageViewModel::products() const {
    return m_products;
}

void ProductPageViewModel::onProductsFetched() {
    m_products.clear();
    for (const auto &product : m_productsModel->products()) {
        m_products.push_back(convertToDisplayData(product));
    }
}

void ProductPageViewModel::onLoadSeat(const QString &id) {
    emit modelLoadSeat(id.toStdString());
}

void ProductPageViewModel::onLoadBaseSeatSuccess(const Common::BaseSeat &seat) {
    emit baseSeatLoadedSuccess(convertBaseSeatToDisplayData(seat));
}

void ProductPageViewModel::onLoadChildSeatSuccess(const Common::ChildSeat &seat) {
    emit childSeatLoadedSuccess(convertChildSeatToDisplayData(seat));
}

void ProductPageViewModel::onLoadSportSeatSuccess(const Common::SportSeat &seat) {
    emit sportSeatLoadedSuccess(convertSportSeatToDisplayData(seat));
}

void ProductPageViewModel::onLoadLuxurySeatSuccess(const Common::LuxurySeat &seat) {
    emit luxurySeatLoadedSuccess(convertLuxurySeatToDisplayData(seat));
}

displayData::Products ProductPageViewModel::convertToDisplayData(const Common::Products &product) {
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

displayData::BaseSeat ProductPageViewModel::convertBaseSeatToDisplayData(const Common::BaseSeat &seat) {
    displayData::BaseSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById("1", seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.color = QString::fromStdString(seat.color);
    data.material = QString::fromStdString(seat.material);
    data.type = QString::fromStdString(seat.type);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::ChildSeat ProductPageViewModel::convertChildSeatToDisplayData(const Common::ChildSeat &seat) {
    displayData::ChildSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById("2", seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.age = QString::fromStdString(seat.age);
    data.weight = QString::fromStdString(seat.weight);
    data.height = QString::fromStdString(seat.height);
    data.safetyKey = QString::fromStdString(seat.safetyKey);
    data.fastening = QString::fromStdString(seat.fastening);
    data.driveway = QString::fromStdString(seat.driveway);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::SportSeat ProductPageViewModel::convertSportSeatToDisplayData(const Common::SportSeat &seat) {
    displayData::SportSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById("3", seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.shellType = QString::fromStdString(seat.shellType);
    data.shellMaterial = QString::fromStdString(seat.shellMaterial);
    data.coverMaterial = QString::fromStdString(seat.coverMaterial);
    data.color = QString::fromStdString(seat.color);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::LuxurySeat ProductPageViewModel::convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat) {
    displayData::LuxurySeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById("4", seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.color = QString::fromStdString(seat.color);
    data.material = QString::fromStdString(seat.material);
    data.comfortLevel = QString::fromStdString(seat.comfortLevel);
    data.customDesign = QString::fromStdString(seat.customDesign);
    data.description = QString::fromStdString(seat.description);

    return data;
}