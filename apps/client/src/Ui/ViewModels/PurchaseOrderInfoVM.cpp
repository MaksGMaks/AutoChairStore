#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent) 
: IViewModel(parent)
, m_purchaseOrdersModel(ordersModel)
, m_productsModel(prodModel)
, m_photosModel(photoModel) {
    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrdersFetched, this, &PurchaseOrderInfoVM::onPurchaseOrdersFetched);
    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrderError, this, &PurchaseOrderInfoVM::onErrorOccurred);

    connect(m_productsModel, &ProductsModel::baseSeatLoadedSuccess, this, &PurchaseOrderInfoVM::onLoadBaseSeatSuccess);
    connect(m_productsModel, &ProductsModel::childSeatLoadedSuccess, this, &PurchaseOrderInfoVM::onLoadChildSeatSuccess);
    connect(m_productsModel, &ProductsModel::sportSeatLoadedSuccess, this, &PurchaseOrderInfoVM::onLoadSportSeatSuccess);
    connect(m_productsModel, &ProductsModel::luxurySeatLoadedSuccess, this, &PurchaseOrderInfoVM::onLoadLuxurySeatSuccess);
    connect(m_productsModel, &ProductsModel::productLoaded, this, &PurchaseOrderInfoVM::onProductLoaded);

    connect(this, &PurchaseOrderInfoVM::modelFetchPurchaseOrders, m_purchaseOrdersModel, &PurchaseOrdersModel::onFetchPurchaseOrders);
    connect(this, &PurchaseOrderInfoVM::modelCancelOrder, m_purchaseOrdersModel, &PurchaseOrdersModel::onCancelOrder);
    connect(this, &PurchaseOrderInfoVM::modelLoadSeat, m_productsModel, &ProductsModel::onLoadSeat);
    connect(this, &PurchaseOrderInfoVM::modelLoadProduct, m_productsModel, &ProductsModel::onLoadProduct);
    
}

QVector<displayData::PurchaseOrder> PurchaseOrderInfoVM::purchaseOrders() const {
    return m_purchaseOrders;
}

void PurchaseOrderInfoVM::onFetchPurchaseOrders(const QString &userId) {
    emit modelFetchPurchaseOrders(userId.toStdString());
}

void PurchaseOrderInfoVM::onLoadProduct(const QString &id) {
    emit modelLoadProduct(id.toStdString());
}

void PurchaseOrderInfoVM::onProductLoaded(const Common::Products &product) {
    std::cout << "[PurchaseOrderInfoVM::onProductLoaded] Product loaded" << std::endl;
    emit productLoaded(convertProductToDisplayData(product));
}

void PurchaseOrderInfoVM::onPurchaseOrdersFetched() {
    std::cout << "[PurchaseOrderInfoVM::onPurchaseOrdersFetched] Purchase orders fetched" << std::endl;
    m_purchaseOrders.clear();
    for(const auto &order : m_purchaseOrdersModel->purchaseOrders()) {
        m_purchaseOrders.push_back(convertPurchaseOrderToDisplayData(order));
    }
    emit purchaseOrdersFetched();
}

void PurchaseOrderInfoVM::onCancelOrder(const QString &id) {
    emit modelCancelOrder(id.toStdString());
}

void PurchaseOrderInfoVM::onLoadSeat(const QString &id) {
    emit modelLoadSeat(id.toStdString());
}

void PurchaseOrderInfoVM::onLoadBaseSeatSuccess(const Common::BaseSeat &seat) {
    emit baseSeatLoadedSuccess(convertBaseSeatToDisplayData(seat));
}

void PurchaseOrderInfoVM::onLoadChildSeatSuccess(const Common::ChildSeat &seat) {
    emit childSeatLoadedSuccess(convertChildSeatToDisplayData(seat));
}

void PurchaseOrderInfoVM::onLoadSportSeatSuccess(const Common::SportSeat &seat) {
    emit sportSeatLoadedSuccess(convertSportSeatToDisplayData(seat));
}

void PurchaseOrderInfoVM::onLoadLuxurySeatSuccess(const Common::LuxurySeat &seat) {
    emit luxurySeatLoadedSuccess(convertLuxurySeatToDisplayData(seat));
}

void PurchaseOrderInfoVM::onCancelOrderSuccess() {
    //emit cancelOrderSuccess();
}

displayData::Products PurchaseOrderInfoVM::convertProductToDisplayData(const Common::Products &product) {
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

displayData::PurchaseOrder PurchaseOrderInfoVM::convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order) {
    displayData::PurchaseOrder data;
    data.id = QString::fromStdString(order.id);
    data.userId = QString::fromStdString(order.userId);
    data.productId = QString::fromStdString(order.productId);
    data.productName = QString::fromStdString(m_productsModel->getNameById(order.productId));
    data.paidType = QString::fromStdString(order.paidType);
    data.date = QString::fromStdString(order.deliveryDate);
    data.destination = QString::fromStdString(order.destination);
    data.packageId = QString::fromStdString(order.packageId);
    data.status = QString::fromStdString(order.status);

    return data;
}

displayData::BaseSeat PurchaseOrderInfoVM::convertBaseSeatToDisplayData(const Common::BaseSeat &seat) {
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

displayData::ChildSeat PurchaseOrderInfoVM::convertChildSeatToDisplayData(const Common::ChildSeat &seat) {
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

displayData::SportSeat PurchaseOrderInfoVM::convertSportSeatToDisplayData(const Common::SportSeat &seat) {
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

displayData::LuxurySeat PurchaseOrderInfoVM::convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat) {
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