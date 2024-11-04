#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PhotosModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class ProductPageViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit ProductPageViewModel(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent = nullptr);
    virtual ~ProductPageViewModel() = default;

    QVector<displayData::Products> products() const;

public slots:
    void onLoadSeat(const QString &id);

signals:
    void modelLoadSeat(const std::string &id);
    
    void baseSeatLoadedSuccess(const displayData::BaseSeat &seat);
    void childSeatLoadedSuccess(const displayData::ChildSeat &seat);
    void sportSeatLoadedSuccess(const displayData::SportSeat &seat);
    void luxurySeatLoadedSuccess(const displayData::LuxurySeat &seat);

private slots:
    void onProductsFetched();

    void onLoadBaseSeatSuccess(const Common::BaseSeat &seat);
    void onLoadChildSeatSuccess(const Common::ChildSeat &seat);
    void onLoadSportSeatSuccess(const Common::SportSeat &seat);
    void onLoadLuxurySeatSuccess(const Common::LuxurySeat &seat);

private:
    ProductsModel *m_productsModel;
    PhotosModel *m_photosModel;

    QVector<displayData::Products> m_products;

    displayData::Products convertToDisplayData(const Common::Products &product);

    displayData::BaseSeat convertBaseSeatToDisplayData(const Common::BaseSeat &seat);
    displayData::ChildSeat convertChildSeatToDisplayData(const Common::ChildSeat &seat);
    displayData::SportSeat convertSportSeatToDisplayData(const Common::SportSeat &seat);
    displayData::LuxurySeat convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat);
};