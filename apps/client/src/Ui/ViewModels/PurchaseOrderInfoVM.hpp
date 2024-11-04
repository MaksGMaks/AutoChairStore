#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PhotosModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class PurchaseOrderInfoVM : public IViewModel {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoVM(PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent = nullptr);
    virtual ~PurchaseOrderInfoVM() = default;

    QVector<displayData::PurchaseOrder> purchaseOrders() const;

signals:
    void modelFetchPurchaseOrders(const std::string &userId);
    void modelCancelOrder(const std::string &id);
    void modelLoadSeat(const std::string &id);
    void modelLoadProduct(const std::string &id);
    void productLoaded(const displayData::Products &product);
    void baseSeatLoadedSuccess(const displayData::BaseSeat &seat);
    void childSeatLoadedSuccess(const displayData::ChildSeat &seat);
    void sportSeatLoadedSuccess(const displayData::SportSeat &seat);
    void luxurySeatLoadedSuccess(const displayData::LuxurySeat &seat);
    void purchaseOrdersFetched();
    

public slots:
    void onFetchPurchaseOrders(const QString &userId);
    void onCancelOrder(const QString &id);
    void onLoadSeat(const QString &id);
    void onLoadProduct(const QString &id);

private slots:
    void onPurchaseOrdersFetched();
    void onCancelOrderSuccess();
    void onProductLoaded(const Common::Products &product);
    void onLoadBaseSeatSuccess(const Common::BaseSeat &seat);
    void onLoadChildSeatSuccess(const Common::ChildSeat &seat);
    void onLoadSportSeatSuccess(const Common::SportSeat &seat);
    void onLoadLuxurySeatSuccess(const Common::LuxurySeat &seat);

private:
    PurchaseOrdersModel *m_purchaseOrdersModel;
    ProductsModel *m_productsModel;
    PhotosModel *m_photosModel;

    QVector<displayData::PurchaseOrder> m_purchaseOrders;

    displayData::PurchaseOrder convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order);

    displayData::Products convertProductToDisplayData(const Common::Products &product);

    displayData::BaseSeat convertBaseSeatToDisplayData(const Common::BaseSeat &seat);
    displayData::ChildSeat convertChildSeatToDisplayData(const Common::ChildSeat &seat);
    displayData::SportSeat convertSportSeatToDisplayData(const Common::SportSeat &seat);
    displayData::LuxurySeat convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat);
};