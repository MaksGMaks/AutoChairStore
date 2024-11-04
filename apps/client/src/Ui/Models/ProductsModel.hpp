#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class ProductsModel : public IModel {
    Q_OBJECT
public:
    explicit ProductsModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~ProductsModel() = default;

    std::vector<Common::Products> products() const;

    std::vector<Common::BaseSeat> baseSeats() const;
    std::vector<Common::ChildSeat> childSeats() const;
    std::vector<Common::SportSeat> sportSeats() const;
    std::vector<Common::LuxurySeat> luxurySeats() const;

    std::string getNameById(const std::string &id);

    void fetchProducts();

signals:
    void errorOccurred(const std::string &errorMessage);

    void productsFetched();
    void baseSeatsFetched();
    void childSeatsFetched();
    void sportSeatsFetched();
    void luxurySeatsFetched();

    void productLoaded(const Common::Products &product);
    void baseSeatLoadedSuccess(const Common::BaseSeat &seat);
    void childSeatLoadedSuccess(const Common::ChildSeat &seat);
    void sportSeatLoadedSuccess(const Common::SportSeat &seat);
    void luxurySeatLoadedSuccess(const Common::LuxurySeat &seat);

    void addToBasketSuccess(const Common::Products &product);

public slots:
    void onFetchProducts();
    void onFetchBaseSeats();
    void onFetchChildSeats();
    void onFetchSportSeats();
    void onFetchLuxurySeats();

    void onLoadSeat(const std::string &id);
    void onLoadProduct(const std::string &id);

    void onAddToBasket(const std::string &id);

private slots:
    void onErrorOccurred(const std::string &errorMessage);

    void onProductsFetched(const std::vector<Common::Products> &products);
    void onBaseSeatsFetched(const std::vector<Common::BaseSeat> &baseSeats);
    void onChildSeatsFetched(const std::vector<Common::ChildSeat> &childSeats);
    void onSportSeatsFetched(const std::vector<Common::SportSeat> &sportSeats);
    void onLuxurySeatsFetched(const std::vector<Common::LuxurySeat> &luxurySeats);

private:
    ApiManager &m_apiManager;
    std::vector<Common::Products> m_products;

    std::vector<Common::BaseSeat> m_baseSeats;
    std::vector<Common::ChildSeat> m_childSeats;
    std::vector<Common::SportSeat> m_sportSeats;
    std::vector<Common::LuxurySeat> m_luxurySeats;
};
