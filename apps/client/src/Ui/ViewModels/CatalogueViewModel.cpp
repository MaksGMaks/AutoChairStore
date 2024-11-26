#include "CatalogueViewModel.hpp"

CatalogueViewModel::CatalogueViewModel(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent)
: IViewModel(parent)
, m_productsModel(productsModel)
, m_photosModel(photosModel) {
    connect(this, &CatalogueViewModel::modelFetchProducts, m_productsModel, &ProductsModel::fetchProducts);
    connect(m_productsModel, &ProductsModel::productsFetched, this, &CatalogueViewModel::onProductsFetched);
    connect(m_productsModel, &ProductsModel::baseSeatsFetched, this, &CatalogueViewModel::onBaseSeatsFetched);
    connect(m_productsModel, &ProductsModel::childSeatsFetched, this, &CatalogueViewModel::onChildSeatsFetched);
    connect(m_productsModel, &ProductsModel::sportSeatsFetched, this, &CatalogueViewModel::onSportSeatsFetched);
    connect(m_productsModel, &ProductsModel::luxurySeatsFetched, this, &CatalogueViewModel::onLuxurySeatsFetched);
}

QVector<displayData::Products> CatalogueViewModel::products() const {
    return m_products;
}

QVector<displayData::BaseSeat> CatalogueViewModel::baseSeats() const {
    return m_baseSeats;
}

QVector<displayData::ChildSeat> CatalogueViewModel::childSeats() const {
    return m_childSeats;
}

QVector<displayData::SportSeat> CatalogueViewModel::sportSeats() const {
    return m_sportSeats;
}

QVector<displayData::LuxurySeat> CatalogueViewModel::luxurySeats() const {
    return m_luxurySeats;
}

void CatalogueViewModel::onGetBaseSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors, 
const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &types) {
    m_baseSeats.clear();
    for(const auto &seat : m_productsModel->baseSeats()) {
        bool seatFound = true;
        if(!brands.empty()) {
            if(!brands.contains(QString::fromStdString(seat.brand))) {
                seatFound = false;
            }
        }
        if(!suitedFors.empty()) {
            if(!suitedFors.contains(QString::fromStdString(seat.suitableFor))) {
                seatFound = false;
            }
        }
        if(!colors.empty()) {
            if(!colors.contains(QString::fromStdString(seat.color))) {
                seatFound = false;
            }
        }
        if(!materials.empty()) {
            if(!materials.contains(QString::fromStdString(seat.material))) {
                seatFound = false;
            }
        }
        if(!types.empty()) {
            if(!types.contains(QString::fromStdString(seat.type))) {
                seatFound = false;
            }
        }
        if(seatFound) {
            m_baseSeats.push_back(convertBaseSeatToDisplayData(seat));
        }
    }
    m_products.clear();
    for(const auto &product : m_productsModel->products()) {
        if(product.productType == "1") {
            for(const auto &seat : m_baseSeats) {
                if(product.productTypeId == seat.id.toStdString()) {
                    m_products.push_back(convertToDisplayData(product));
                }
            }
        } else {
            m_products.push_back(convertToDisplayData(product));
        }
    }
    emit productsFiltered();
}

void CatalogueViewModel::onGetChildSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &ages,
const QVector<QString> &weights, const QVector<QString> &heights, const QVector<QString> &safetyKeys, const QVector<QString> &fastenings,
const QVector<QString> &driveways) {
    
    m_childSeats.clear();
    bool seatFound = true;
    for(const auto &seat : m_productsModel->childSeats()) {
        if(!brands.empty()) {
            if(!brands.contains(QString::fromStdString(seat.brand))) {
                seatFound = false;
            }
        }
        if(!ages.empty()) {
            if(!ages.contains(QString::fromStdString(seat.age))) {
                seatFound = false;
            }
        }
        if(!weights.empty()) {
            if(!weights.contains(QString::fromStdString(seat.weight))) {
                seatFound = false;
            }
        }
        if(!heights.empty()) {
            if(!heights.contains(QString::fromStdString(seat.height))) {
                seatFound = false;
            }
        }
        if(!safetyKeys.empty()) {
            if(!safetyKeys.contains(QString::fromStdString(seat.safetyKey))) {
                seatFound = false;
            }
        }
        if(!fastenings.empty()) {
            if(!fastenings.contains(QString::fromStdString(seat.fastening))) {
                seatFound = false;
            }
        }
        if(!driveways.empty()) {
            if(!driveways.contains(QString::fromStdString(seat.driveway))) {
                seatFound = false;
            }
        }
        if(seatFound) {
            m_childSeats.push_back(convertChildSeatToDisplayData(seat));
        }
    }

    m_products.clear();
    for(const auto &product : m_productsModel->products()) {
        if(product.productType == "2") {
            for(const auto &seat : m_childSeats) {
                if(product.productTypeId == seat.id.toStdString()) {
                    m_products.push_back(convertToDisplayData(product));
                }
            }
        } else {
            m_products.push_back(convertToDisplayData(product));
        }
    }
    emit productsFiltered();
}

void CatalogueViewModel::onGetSportSeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors,
const QVector<QString> &shellTypes, const QVector<QString> &shellMaterials, const QVector<QString> &coverMaterials,
const QVector<QString> &colors) {
    m_sportSeats.clear();
    bool seatFound = true;
    for(const auto &seat : m_productsModel->sportSeats()) {
        if(!brands.empty()) {
            if(!brands.contains(QString::fromStdString(seat.brand))) {
                seatFound = false;
            }
        }
        if(!suitedFors.empty()) {
            if(!suitedFors.contains(QString::fromStdString(seat.suitableFor))) {
                seatFound = false;
            }
        }
        if(!shellTypes.empty()) {
            if(!shellTypes.contains(QString::fromStdString(seat.shellType))) {
                seatFound = false;
            }
        }
        if(!shellMaterials.empty()) {
            if(!shellMaterials.contains(QString::fromStdString(seat.shellMaterial))) {
                seatFound = false;
            }
        }
        if(!coverMaterials.empty()) {
            if(!coverMaterials.contains(QString::fromStdString(seat.coverMaterial))) {
                seatFound = false;
            }
        }
        if(!colors.empty()) {
            if(!colors.contains(QString::fromStdString(seat.color))) {
                seatFound = false;
            }
        }
        if(seatFound) {
            m_sportSeats.push_back(convertSportSeatToDisplayData(seat));
        }
    }

    m_products.clear();
    for(const auto &product : m_productsModel->products()) {
        if(product.productType == "3") {
            for(const auto &seat : m_sportSeats) {
                if(product.productTypeId == seat.id.toStdString()) {
                    m_products.push_back(convertToDisplayData(product));
                }
            }
        } else {
            m_products.push_back(convertToDisplayData(product));
        }
    }
    emit productsFiltered();
}

void CatalogueViewModel::onGetLuxurySeatsByFilters(const QVector<QString> &brands, const QVector<QString> &suitedFors,
const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &comforts, const QVector<QString> &customDesigns) {
    m_luxurySeats.clear();
    bool seatFound = true;
    for(const auto &seat : m_productsModel->luxurySeats()) {
        if(!brands.empty()) {
            if(!brands.contains(QString::fromStdString(seat.brand))) {
                seatFound = false;
            }
        }
        if(!suitedFors.empty()) {
            if(!suitedFors.contains(QString::fromStdString(seat.suitableFor))) {
                seatFound = false;
            }
        }
        if(!colors.empty()) {
            if(!colors.contains(QString::fromStdString(seat.color))) {
                seatFound = false;
            }
        }
        if(!materials.empty()) {
            if(!materials.contains(QString::fromStdString(seat.material))) {
                seatFound = false;
            }
        }
        if(!comforts.empty()) {
            if(!comforts.contains(QString::fromStdString(seat.comfortLevel))) {
                seatFound = false;
            }
        }
        if(!customDesigns.empty()) {
            if(!customDesigns.contains(QString::fromStdString(seat.customDesign))) {
                seatFound = false;
            }
        }
        if(seatFound) {
            m_luxurySeats.push_back(convertLuxurySeatToDisplayData(seat));
        }
    }

    m_products.clear();
    for(const auto &product : m_productsModel->products()) {
        if(product.productType == "4") {
            for(const auto &seat : m_luxurySeats) {
                if(product.productTypeId == seat.id.toStdString()) {
                    m_products.push_back(convertToDisplayData(product));
                }
            }
        } else {
            m_products.push_back(convertToDisplayData(product));
        }
    }
    emit productsFiltered();
}

void CatalogueViewModel::onFetchProducts() {
    emit modelFetchProducts();
}

void CatalogueViewModel::onProductsFetched() {
    m_products.clear();

    for(const auto &product : m_productsModel->products()) {
        m_products.push_back(convertToDisplayData(product));
    }
    emit productsFetched();
}

void CatalogueViewModel::onClearSeats() {
    m_baseSeats.clear();
    for(const auto &baseSeat : m_productsModel->baseSeats()) {
        m_baseSeats.push_back(convertBaseSeatToDisplayData(baseSeat));
    }

    m_childSeats.clear();
    for(const auto &childSeat : m_productsModel->childSeats()) {
        m_childSeats.push_back(convertChildSeatToDisplayData(childSeat));
    }

    m_sportSeats.clear();
    for(const auto &sportSeat : m_productsModel->sportSeats()) {
        m_sportSeats.push_back(convertSportSeatToDisplayData(sportSeat));
    }

    m_luxurySeats.clear();
    for(const auto &luxurySeat : m_productsModel->luxurySeats()) {
        m_luxurySeats.push_back(convertLuxurySeatToDisplayData(luxurySeat));
    }
    
    m_products.clear();
    for(const auto &product : m_productsModel->products()) {
        m_products.push_back(convertToDisplayData(product));
    }
    emit productsFiltered();
}

void CatalogueViewModel::onBaseSeatsFetched() {
    m_baseSeats.clear();
    for(const auto &seat : m_productsModel->baseSeats()) {
        m_baseSeats.push_back(convertBaseSeatToDisplayData(seat));
    }
    emit baseSeatsFetched();
}

void CatalogueViewModel::onChildSeatsFetched() {
    m_childSeats.clear();
    for(const auto &seat : m_productsModel->childSeats()) {
        m_childSeats.push_back(convertChildSeatToDisplayData(seat));
    }
    emit childSeatsFetched();
}

void CatalogueViewModel::onSportSeatsFetched() {
    m_sportSeats.clear();
    for(const auto &seat : m_productsModel->sportSeats()) {
        m_sportSeats.push_back(convertSportSeatToDisplayData(seat));
    }
    emit sportSeatsFetched();
}

void CatalogueViewModel::onLuxurySeatsFetched() {
    m_luxurySeats.clear();
    for(const auto &seat : m_productsModel->luxurySeats()) {
        m_luxurySeats.push_back(convertLuxurySeatToDisplayData(seat));
    }
    emit luxurySeatsFetched();
}

displayData::Products CatalogueViewModel::convertToDisplayData(const Common::Products &product) {
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

displayData::BaseSeat CatalogueViewModel::convertBaseSeatToDisplayData(const Common::BaseSeat &seat) {
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

displayData::ChildSeat CatalogueViewModel::convertChildSeatToDisplayData(const Common::ChildSeat &seat) {
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

displayData::SportSeat CatalogueViewModel::convertSportSeatToDisplayData(const Common::SportSeat &seat) {
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

displayData::LuxurySeat CatalogueViewModel::convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat) {
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