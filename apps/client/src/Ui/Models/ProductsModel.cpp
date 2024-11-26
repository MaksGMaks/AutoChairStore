#include "ProductsModel.hpp"

ProductsModel::ProductsModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    connect(&m_apiManager, &ApiManager::productsFetched, this, &ProductsModel::onProductsFetched);
    connect(&m_apiManager, &ApiManager::baseSeatsFetched, this, &ProductsModel::onBaseSeatsFetched);
    connect(&m_apiManager, &ApiManager::childSeatsFetched, this, &ProductsModel::onChildSeatsFetched);
    connect(&m_apiManager, &ApiManager::sportSeatsFetched, this, &ProductsModel::onSportSeatsFetched);
    connect(&m_apiManager, &ApiManager::luxurySeatsFetched, this, &ProductsModel::onLuxurySeatsFetched);
    connect(&m_apiManager, &ApiManager::productsError, this, &ProductsModel::onErrorOccurred);
    
}

std::vector<Common::Products> ProductsModel::products() const {
    return m_products;
}

std::vector<Common::BaseSeat> ProductsModel::baseSeats() const {
    return m_baseSeats;
}

std::vector<Common::ChildSeat> ProductsModel::childSeats() const {
    return m_childSeats;
}

std::vector<Common::SportSeat> ProductsModel::sportSeats() const {
    return m_sportSeats;
}

std::vector<Common::LuxurySeat> ProductsModel::luxurySeats() const {
    return m_luxurySeats;
}

void ProductsModel::fetchProducts() {
    m_apiManager.fetchBaseSeats();
    m_apiManager.fetchChildSeats();
    m_apiManager.fetchSportSeats();
    m_apiManager.fetchLuxurySeats();
    m_apiManager.fetchProducts();
}

std::string ProductsModel::getNameById(const std::string &id) {
    for(auto product : m_products) {
        if(product.id == id) {
            return product.productName;
        }
    }
    return "";
}

void ProductsModel::onProductsFetched(const std::vector<Common::Products> &products) {
    m_products = products;
    emit productsFetched();
}

void ProductsModel::onBaseSeatsFetched(const std::vector<Common::BaseSeat> &baseSeats) {
    m_baseSeats = baseSeats;
    emit baseSeatsFetched();
}

void ProductsModel::onChildSeatsFetched(const std::vector<Common::ChildSeat> &childSeats) {
    m_childSeats = childSeats;
    emit childSeatsFetched();
}

void ProductsModel::onSportSeatsFetched(const std::vector<Common::SportSeat> &sportSeats) {
    m_sportSeats = sportSeats;
    emit sportSeatsFetched();
}

void ProductsModel::onLuxurySeatsFetched(const std::vector<Common::LuxurySeat> &luxurySeats) {
    m_luxurySeats = luxurySeats;
    emit luxurySeatsFetched();
}

void ProductsModel::onFetchProducts() {
    m_apiManager.fetchProducts();
}

void ProductsModel::onFetchBaseSeats() {
    m_apiManager.fetchBaseSeats();
}

void ProductsModel::onFetchChildSeats() {
    m_apiManager.fetchChildSeats();
}

void ProductsModel::onFetchSportSeats() {
    m_apiManager.fetchSportSeats();
}

void ProductsModel::onFetchLuxurySeats() {
    m_apiManager.fetchLuxurySeats();
}

void ProductsModel::onErrorOccurred(const std::string &errorMessage) {
    emit errorOccurred(errorMessage);
}

void ProductsModel::onLoadSeat(const std::string &id) {
    for(auto product : m_products) {
        if(product.id == id) {
            switch(std::stoi(product.productType)) {
                case 1:
                    for(auto seat : m_baseSeats) {
                        if(seat.id == product.productTypeId) {
                            emit baseSeatLoadedSuccess(seat);
                            break;
                        }
                    }
                    break;
                case 2:
                    for(auto seat : m_childSeats) {
                        if(seat.id == product.productTypeId) {
                            emit childSeatLoadedSuccess(seat);
                            break;
                        }
                    }
                    break;
                case 3:
                    for(auto seat : m_sportSeats) {
                        if(seat.id == product.productTypeId) {
                            emit sportSeatLoadedSuccess(seat);
                            break;
                        }
                    }
                    break;
                case 4:
                    for(auto seat : m_luxurySeats) {
                        if(seat.id == product.productTypeId) {
                            emit luxurySeatLoadedSuccess(seat);
                            break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void ProductsModel::onLoadProduct(const std::string &id) {
    for(auto product : m_products) {
        if(product.id == id) {
            emit productLoaded(product);
            break;
        }
    }
}

void ProductsModel::onAddToBasket(const std::string &id) {
    for(auto product : m_products) {
        if(product.id == id) {
            emit addToBasketSuccess(product);
            break;
        }
    }
}