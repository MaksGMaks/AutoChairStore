#include "BasketViewModel.hpp"

BasketViewModel::BasketViewModel(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, QObject *parent)
: IViewModel(parent)
, m_productsModel(productsModel)
, m_purchaseOrdersModel(purchaseOrdersModel) {
    connect(this, &BasketViewModel::modelAddToBasket, m_productsModel, &ProductsModel::onAddToBasket);
    connect(this, &BasketViewModel::modelCreateOrder, m_purchaseOrdersModel, &PurchaseOrdersModel::onCreateOrder);

    connect(m_productsModel, &ProductsModel::addToBasketSuccess, this, &BasketViewModel::onAddedToBasket);
    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::orderCreated, this, &BasketViewModel::onOrderCreated);
}

QVector<displayData::Products> BasketViewModel::productsInBasket() const {
    return m_productsInBasket;
}

void BasketViewModel::onAddToBasket(const QString &id) {
    emit modelAddToBasket(id.toStdString());
}

void BasketViewModel::onCreateOrder(const displayData::PurchaseOrder &order) {
    emit modelCreateOrder(convertDisplayDataToPurchaseOrder(order));
}

void BasketViewModel::onAddedToBasket(const Common::Products &product) {
    m_productsInBasket.push_back(convertToDisplayData(product));
    emit addedToBasket(convertToDisplayData(product));
}

void BasketViewModel::onOrderCreated(const std::string &message) {
    emit orderCreated(QString::fromStdString(message));
}

void BasketViewModel::onRemoveFromBasket(const QString &id) {
    for(auto it = m_productsInBasket.begin(); it != m_productsInBasket.end(); ++it) {
        if(it->id == id) {
            m_productsInBasket.erase(it);
            break;
        }
    }
}

displayData::Products BasketViewModel::convertToDisplayData(const Common::Products &product) {
    displayData::Products data;
    data.id = QString::fromStdString(product.id);
    data.name = QString::fromStdString(product.productName);
    data.type = QString::fromStdString(product.productType);
    data.price = QString::fromStdString(product.price);
    data.priceUnit = QString::fromStdString(product.priceUnit);
    data.discount = QString::fromStdString(product.discount);
    data.hasDiscount = QString::fromStdString(product.hasDiscount);

    return data;
}

displayData::PurchaseOrder BasketViewModel::convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order) {
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

Common::PurchaseOrders BasketViewModel::convertDisplayDataToPurchaseOrder(const displayData::PurchaseOrder &order) {
    Common::PurchaseOrders data;
    data.id = order.id.toStdString();
    data.userId = order.userId.toStdString();
    data.productId = order.productId.toStdString();
    data.paidType = order.paidType.toStdString();
    data.destination = order.destination.toStdString();
    data.packageId = order.packageId.toStdString();
    data.deliveryDate = order.date.toStdString();
    data.status = order.status.toStdString();

    return data;
}