#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class BasketViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit BasketViewModel(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, QObject *parent = nullptr);
    ~BasketViewModel() = default;

    QVector<displayData::Products> productsInBasket() const;

signals:
    void modelAddToBasket(const std::string &id);
    void modelCreateOrder(const Common::PurchaseOrders &order);
    void addedToBasket(const displayData::Products &product);
    void orderCreated(const QString &message);

public slots:
    void onAddToBasket(const QString &id);
    void onCreateOrder(const displayData::PurchaseOrder &order);
    void onRemoveFromBasket(const QString &id);

private slots:
    void onAddedToBasket(const Common::Products &product);
    void onOrderCreated(const std::string &message);

private:
    ProductsModel *m_productsModel;
    PurchaseOrdersModel *m_purchaseOrdersModel;

    QVector<displayData::Products> m_productsInBasket;

    displayData::Products convertToDisplayData(const Common::Products &product);
    
    displayData::PurchaseOrder convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order);
    Common::PurchaseOrders convertDisplayDataToPurchaseOrder(const displayData::PurchaseOrder &order);

};