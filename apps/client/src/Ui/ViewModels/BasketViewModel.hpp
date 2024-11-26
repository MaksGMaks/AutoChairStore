#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"
#include "Ui/Models/UsersModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class BasketViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit BasketViewModel(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, UsersModel *usrModel, QObject *parent = nullptr);
    ~BasketViewModel() = default;

    QVector<displayData::Products> productsInBasket() const;

signals:
    void modelAddToBasket(const std::string &id);
    void modelCreateOrder(const std::vector<Common::PurchaseOrders> &entity);
    void addedToBasket();
    void orderCreated();

public slots:
    void onAddToBasket(const QString &id);
    void onCreateOrder(const displayData::PurchaseOrder &order);
    void onRemoveFromBasket(const QString &id);

private slots:
    void onAddedToBasket(const Common::Products &product);
    void onOrderCreated();

private:
    ProductsModel *m_productsModel;
    PurchaseOrdersModel *m_purchaseOrdersModel;
    UsersModel *m_userModel;

    QVector<displayData::Products> m_productsInBasket;

    displayData::Products convertToDisplayData(const Common::Products &product);
    
    displayData::PurchaseOrder convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order);
    Common::PurchaseOrders convertDisplayDataToPurchaseOrder(const displayData::PurchaseOrder &order);

};