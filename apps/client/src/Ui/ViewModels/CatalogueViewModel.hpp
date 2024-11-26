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
    QVector<displayData::BaseSeat> baseSeats() const;
    QVector<displayData::ChildSeat> childSeats() const;
    QVector<displayData::SportSeat> sportSeats() const;
    QVector<displayData::LuxurySeat> luxurySeats() const;

signals:
    void modelFetchProducts();

    void productsFetched();
    void baseSeatsFetched();
    void childSeatsFetched();
    void sportSeatsFetched();
    void luxurySeatsFetched();

    void productsFiltered();

public slots:
    void onFetchProducts();

    void onGetBaseSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors, 
                                 const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &types);
    void onGetChildSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &ages, const QVector<QString> &weights, 
                                  const QVector<QString> &heights, const QVector<QString> &safetyKeys, const QVector<QString> &fastenings, 
                                  const QVector<QString> &driveways);
    void onGetSportSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors, const QVector<QString> &shellTypes,
                                  const QVector<QString> &shellMaterials, const QVector<QString> &coverMaterials, const QVector<QString> &colors);
    void onGetLuxurySeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors, const QVector<QString> &colors,
                                   const QVector<QString> &materials, const QVector<QString> &comforts, const QVector<QString> &customDesigns);

    void onClearSeats();

private slots:
    void onProductsFetched();
    void onBaseSeatsFetched();
    void onChildSeatsFetched();
    void onSportSeatsFetched();
    void onLuxurySeatsFetched();

private:
    ProductsModel *m_productsModel;
    PhotosModel *m_photosModel;

    QVector<displayData::Products> m_products;
    QVector<displayData::BaseSeat> m_baseSeats;
    QVector<displayData::ChildSeat> m_childSeats;
    QVector<displayData::SportSeat> m_sportSeats;
    QVector<displayData::LuxurySeat> m_luxurySeats;

    displayData::Products convertToDisplayData(const Common::Products &product);
    displayData::BaseSeat convertBaseSeatToDisplayData(const Common::BaseSeat &seat);
    displayData::ChildSeat convertChildSeatToDisplayData(const Common::ChildSeat &seat);
    displayData::SportSeat convertSportSeatToDisplayData(const Common::SportSeat &seat);
    displayData::LuxurySeat convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat);
};