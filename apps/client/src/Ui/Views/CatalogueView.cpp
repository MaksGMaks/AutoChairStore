#include "CatalogueView.hpp"

CatalogueView::CatalogueView(CatalogueViewModel *viewModel, QWidget *parent) 
: IView(viewModel, parent), 
m_productsVM(viewModel) {
    std::cout << "[CatalogueView::CatalogueView] constructor" << std::endl;
    setupUI();
    setupConnections();
}

void CatalogueView::onFilteredProducts() {
    std::cout << "[CatalogueView::onFilteredProducts] Filtered products" << std::endl;
    QVector<displayData::Products> products = m_productsVM->products();
    QVector<displayData::Products> baseSeats;
    QVector<displayData::Products> childSeats;
    QVector<displayData::Products> sportSeats;
    QVector<displayData::Products> luxurySeats;
    for(auto product : products) {
        if(product.type == "1")
            baseSeats.push_back(product);
        else if(product.type == "2")
            childSeats.push_back(product);
        else if(product.type == "3")
            sportSeats.push_back(product);
        else if(product.type == "4")
            luxurySeats.push_back(product);
    }

    m_baseSeatCatalogueList->clear();
    m_childSeatCatalogueList->clear();
    m_sportSeatCatalogueList->clear();
    m_luxurySeatCatalogueList->clear();
    
    getProductList(1, baseSeats);
    getProductList(2, childSeats);
    getProductList(3, sportSeats);
    getProductList(4, luxurySeats);

    onBaseSeatsFetched();
    onChildSeatsFetched();
    onSportSeatsFetched();
    onLuxurySeatsFetched();
}

void CatalogueView::onBaseSeatsCleared() {
    emit vmClearBaseSeats();
}

void CatalogueView::onChildSeatsCleared() {
    emit vmClearChildSeats();
}

void CatalogueView::onSportSeatsCleared() {
    emit vmClearSportSeats();
}

void CatalogueView::onLuxurySeatsCleared() {
    emit vmClearLuxurySeats();
}

void CatalogueView::openRefresh() {
    std::cout << "[CatalogueView::openRefresh] Opening refresh" << std::endl;
    fetchProducts();
    m_catalogueStackedWidget->setCurrentIndex(0);
}

void CatalogueView::fetchProducts() {
    std::cout << "[CatalogueView::fetchProducts] Fetching products" << std::endl;
    emit vmFetchProducts();
}

void CatalogueView::setupConnections() {
    std::cout << "[CatalogueView::setupConnections] Setting up connections" << std::endl;
    connect(m_productsVM, &CatalogueViewModel::productsFetched, this, &CatalogueView::onProductsFetched);
    connect(m_productsVM, &CatalogueViewModel::baseSeatsFetched, this, &CatalogueView::onBaseSeatsFetched);
    connect(m_productsVM, &CatalogueViewModel::childSeatsFetched, this, &CatalogueView::onChildSeatsFetched);
    connect(m_productsVM, &CatalogueViewModel::sportSeatsFetched, this, &CatalogueView::onSportSeatsFetched);
    connect(m_productsVM, &CatalogueViewModel::luxurySeatsFetched, this, &CatalogueView::onLuxurySeatsFetched);

    connect(m_productsVM, &CatalogueViewModel::productsFiltered, this, &CatalogueView::onFilteredProducts);

    connect(m_baseSeatSearch, &CatalogueSearchBaseSeatV::filterClicked, this, [this](const QVector<QString> &brands, const QVector<QString> &suitedFors,
    const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &types) {
        std::cout << "[CatalogueView::setupConnections] Filtering base seats" << std::endl;
        emit vmGetBaseSeatsByFilters(brands, suitedFors, colors, materials, types);
    });

    connect(m_baseSeatSearch, &CatalogueSearchBaseSeatV::clearClicked, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Clearing base seats" << std::endl;
        emit vmClearBaseSeats();
    });

    connect(m_childSeatSearch, &CatalogueSearchChildSeatV::filterClicked, this, [this](const QVector<QString> &brands, const QVector<QString> &ages, const QVector<QString> &weights,
    const QVector<QString> &heights, const QVector<QString> &safetyKeys, const QVector<QString> &fastenings, const QVector<QString> &driveways) {
        std::cout << "[CatalogueView::setupConnections] Filtering child seats" << std::endl;
        emit vmGetChildSeatsByFilters(brands, ages, weights, heights, safetyKeys, fastenings, driveways);
    });

    connect(m_childSeatSearch, &CatalogueSearchChildSeatV::clearClicked, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Clearing child seats" << std::endl;
        emit vmClearChildSeats();
    });

    connect(m_sportSeatSearch, &CatalogueSearchSportSeatV::filterClicked, this, [this](const QVector<QString> &brands, const QVector<QString> &suitedFors, const QVector<QString> &shellTypes,
    const QVector<QString> &shellMaterials, const QVector<QString> &coverMaterials, const QVector<QString> &colors) {
        std::cout << "[CatalogueView::setupConnections] Filtering sport seats" << std::endl;
        emit vmGetSportSeatsByFilters(brands, suitedFors, shellTypes, shellMaterials, coverMaterials, colors);
    });

    connect(m_sportSeatSearch, &CatalogueSearchSportSeatV::clearClicked, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Clearing sport seats" << std::endl;
        emit vmClearSportSeats();
    });

    connect(m_luxurySeatSearch, &CatalogueSearchLuxurySeatV::filterClicked, this, [this](const QVector<QString> &brands, const QVector<QString> &suitedFors, const QVector<QString> &colors,
    const QVector<QString> &materials, const QVector<QString> &comforts, const QVector<QString> &customDesigns) {
        std::cout << "[CatalogueView::setupConnections] Filtering luxury seats" << std::endl;
        emit vmGetLuxurySeatsByFilters(brands, suitedFors, colors, materials, comforts, customDesigns);
    });

    connect(m_luxurySeatSearch, &CatalogueSearchLuxurySeatV::clearClicked, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Clearing luxury seats" << std::endl;
        emit vmClearLuxurySeats();
    });
    
    connect(this, &CatalogueView::vmFetchProducts, m_productsVM, &CatalogueViewModel::onFetchProducts);

    connect(this, &CatalogueView::vmGetBaseSeatsByFilters, m_productsVM, &CatalogueViewModel::onGetBaseSeatsByFilters);
    connect(this, &CatalogueView::vmGetChildSeatsByFilters, m_productsVM, &CatalogueViewModel::onGetChildSeatsByFilters);
    connect(this, &CatalogueView::vmGetSportSeatsByFilters, m_productsVM, &CatalogueViewModel::onGetSportSeatsByFilters);
    connect(this, &CatalogueView::vmGetLuxurySeatsByFilters, m_productsVM, &CatalogueViewModel::onGetLuxurySeatsByFilters);

    connect(this, &CatalogueView::vmClearBaseSeats, m_productsVM, &CatalogueViewModel::onClearSeats);
    connect(this, &CatalogueView::vmClearChildSeats, m_productsVM, &CatalogueViewModel::onClearSeats);
    connect(this, &CatalogueView::vmClearSportSeats, m_productsVM, &CatalogueViewModel::onClearSeats);
    connect(this, &CatalogueView::vmClearLuxurySeats, m_productsVM, &CatalogueViewModel::onClearSeats);

    connect(m_catalogueMenu, &CatalogueMenuSV::openBaseSeats, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Opening base seats" << std::endl;
        m_catalogueStackedWidget->setCurrentIndex(0);
        emit vmFetchProducts();
    });

    connect(m_catalogueMenu, &CatalogueMenuSV::openChildSeats, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Opening child seats" << std::endl;
        m_catalogueStackedWidget->setCurrentIndex(1);
        emit vmFetchProducts();
    });

    connect(m_catalogueMenu, &CatalogueMenuSV::openSportSeats, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Opening sport seats" << std::endl;
        m_catalogueStackedWidget->setCurrentIndex(2);
        emit vmFetchProducts();
    });

    connect(m_catalogueMenu, &CatalogueMenuSV::openLuxurySeats, this, [this]() {
        std::cout << "[CatalogueView::setupConnections] Opening luxury seats" << std::endl;
        m_catalogueStackedWidget->setCurrentIndex(3);
        emit vmFetchProducts();
    });
}

void CatalogueView::onProductsFetched() {
    std::cout << "[CatalogueView::onProductsFetched] Products fetched" << std::endl;
    QVector<displayData::Products> products = m_productsVM->products();
    QVector<displayData::Products> baseSeats;
    QVector<displayData::Products> childSeats;
    QVector<displayData::Products> sportSeats;
    QVector<displayData::Products> luxurySeats;
    for(auto product : products) {
        if(product.type == "1")
            baseSeats.push_back(product);
        else if(product.type == "2")
            childSeats.push_back(product);
        else if(product.type == "3")
            sportSeats.push_back(product);
        else if(product.type == "4")
            luxurySeats.push_back(product);
    }
    m_baseSeatCatalogueList->clear();
    m_childSeatCatalogueList->clear();
    m_sportSeatCatalogueList->clear();
    m_luxurySeatCatalogueList->clear();
    
    getProductList(1, baseSeats);
    getProductList(2, childSeats);
    getProductList(3, sportSeats);
    getProductList(4, luxurySeats);
}

void CatalogueView::onBaseSeatsFetched() {
    std::cout << "[CatalogueView::onBaseSeatsFetched] Base seats fetched" << std::endl;
    m_baseSeatSearch->addFilters(m_productsVM->baseSeats());
}

void CatalogueView::onChildSeatsFetched() {
    std::cout << "[CatalogueView::onChildSeatsFetched] Child seats fetched" << std::endl;
    m_childSeatSearch->addFilters(m_productsVM->childSeats());
}

void CatalogueView::onSportSeatsFetched() {
    std::cout << "[CatalogueView::onSportSeatsFetched] Sport seats fetched" << std::endl;
    m_sportSeatSearch->addFilters(m_productsVM->sportSeats());
}

void CatalogueView::onLuxurySeatsFetched() {
    std::cout << "[CatalogueView::onLuxurySeatsFetched] Luxury seats fetched" << std::endl;
    m_luxurySeatSearch->addFilters(m_productsVM->luxurySeats());
}

void CatalogueView::getProductList(const int &id, const QVector<displayData::Products> &products) {
    std::cout << "[CatalogueView::getProductList] Getting product list" << std::endl;
    int count = 0;
    QVector<displayData::Products> products_copy;
    for(auto product_ : products) {
        count++;
        products_copy.push_back(product_);
        if(count == 4) {
            count = 0;
            QHBoxLayout *productLine = new QHBoxLayout();
            for(auto product : products_copy) {
                CatalogueProductSV *productSV = new CatalogueProductSV(product.name, product.price, product.priceUnit, product.discount, product.hasDiscount, product.photo);
                connect(productSV, &CatalogueProductSV::openProductPage, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Opening page for product with id " << product.id.toStdString() << std::endl;
                    emit openProductPage(product.id);
                });
                connect(productSV, &CatalogueProductSV::addToBasketClicked, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Adding to basket product with id " << product.id.toStdString() << std::endl;
                    emit addToBasket(product.id);
                });
                connect(productSV, &CatalogueProductSV::buyClicked, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Buying product with id " << product.id.toStdString() << std::endl;
                    emit buyProduct(product.id);
                });
                productSV->setFixedSize(190, 320);
                productLine->addWidget(productSV);
            }
            QWidget *productLineWidget = new QWidget(this);
            productLineWidget->setLayout(productLine);
            QListWidgetItem *productLineItem = new QListWidgetItem();
            productLineItem->setSizeHint(productLineWidget->sizeHint());
            
            switch (id) {
            case 1:
                m_baseSeatCatalogueList->addItem(productLineItem);
                m_baseSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 2:
                m_childSeatCatalogueList->addItem(productLineItem);
                m_childSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 3:
                m_sportSeatCatalogueList->addItem(productLineItem);
                m_sportSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 4:
                m_luxurySeatCatalogueList->addItem(productLineItem);
                m_luxurySeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            default:
                break;
            }
            products_copy.clear();
        }
        if(product_ == products.last()) {
            QHBoxLayout *productLine = new QHBoxLayout();
            for(auto product : products_copy) {
                CatalogueProductSV *productSV = new CatalogueProductSV(product.name, product.price, product.priceUnit, product.discount, product.hasDiscount, product.photo);
                connect(productSV, &CatalogueProductSV::openProductPage, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Opening page for product with id " << product.id.toStdString() << std::endl;
                    emit openProductPage(product.id);
                });
                connect(productSV, &CatalogueProductSV::addToBasketClicked, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Adding to basket product with id " << product.id.toStdString() << std::endl;
                    emit addToBasket(product.id);
                });
                connect(productSV, &CatalogueProductSV::buyClicked, this, [this, product]() {
                    std::cout << "[CatalogueView::getProductList] Buying product with id " << product.id.toStdString() << std::endl;
                    emit buyProduct(product.id);
                });
                productSV->setFixedSize(190, 320);
                productLine->addWidget(productSV);
            }
            QWidget *productLineWidget = new QWidget(this);
            productLineWidget->setLayout(productLine);
            QListWidgetItem *productLineItem = new QListWidgetItem();
            productLineItem->setSizeHint(productLineWidget->sizeHint());
            switch (id) {
            case 1:
                m_baseSeatCatalogueList->addItem(productLineItem);
                m_baseSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 2:
                m_childSeatCatalogueList->addItem(productLineItem);
                m_childSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 3:
                m_sportSeatCatalogueList->addItem(productLineItem);
                m_sportSeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            case 4:
                m_luxurySeatCatalogueList->addItem(productLineItem);
                m_luxurySeatCatalogueList->setItemWidget(productLineItem, productLineWidget);
                break;
            default:
                break;
            }
            products_copy.clear();
        }
    }
}

void CatalogueView::setupUI() {
    std::cout << "[CatalogueView::setupUI] Setting up UI" << std::endl;

    m_catalogueMenu = new CatalogueMenuSV();
    m_catalogueMenu->setFixedHeight(50);

    m_catalogueStackedWidget = new QStackedWidget();

    m_baseSeatCatalogueList = new QListWidget();
    m_baseSeatCatalogueList->setSelectionMode(QAbstractItemView::NoSelection);

    m_childSeatCatalogueList = new QListWidget();
    m_childSeatCatalogueList->setSelectionMode(QAbstractItemView::NoSelection);

    m_sportSeatCatalogueList = new QListWidget();
    m_sportSeatCatalogueList->setSelectionMode(QAbstractItemView::NoSelection);

    m_luxurySeatCatalogueList = new QListWidget();
    m_luxurySeatCatalogueList->setSelectionMode(QAbstractItemView::NoSelection);

    m_baseSeatSearch = new CatalogueSearchBaseSeatV();
    m_baseSeatSearch->setFixedWidth(200);
    m_baseSeatSearch->setMinimumHeight(500);

    m_baseSeatLayout = new QHBoxLayout();
    m_baseSeatLayout->addWidget(m_baseSeatSearch);
    m_baseSeatLayout->addWidget(m_baseSeatCatalogueList);

    m_baseSeatWidget = new QWidget();
    m_baseSeatWidget->setLayout(m_baseSeatLayout);

    m_childSeatSearch = new CatalogueSearchChildSeatV();
    m_childSeatSearch->setFixedWidth(200);
    m_childSeatSearch->setMinimumHeight(500);
    
    m_childSeatLayout = new QHBoxLayout();
    m_childSeatLayout->addWidget(m_childSeatSearch);
    m_childSeatLayout->addWidget(m_childSeatCatalogueList);

    m_childSeatWidget = new QWidget();
    m_childSeatWidget->setLayout(m_childSeatLayout);

    m_sportSeatSearch = new CatalogueSearchSportSeatV();
    m_sportSeatSearch->setFixedWidth(200);
    m_sportSeatSearch->setMinimumHeight(500);

    m_sportSeatLayout = new QHBoxLayout();
    m_sportSeatLayout->addWidget(m_sportSeatSearch);
    m_sportSeatLayout->addWidget(m_sportSeatCatalogueList);

    m_sportSeatWidget = new QWidget();
    m_sportSeatWidget->setLayout(m_sportSeatLayout);

    m_luxurySeatSearch = new CatalogueSearchLuxurySeatV();
    m_luxurySeatSearch->setFixedWidth(200);
    m_luxurySeatSearch->setMinimumHeight(500);

    m_luxurySeatLayout = new QHBoxLayout();
    m_luxurySeatLayout->addWidget(m_luxurySeatSearch);
    m_luxurySeatLayout->addWidget(m_luxurySeatCatalogueList);

    m_luxurySeatWidget = new QWidget();
    m_luxurySeatWidget->setLayout(m_luxurySeatLayout);

    std::cout << "[CatalogueView::setupUI] Adding widgets to stacked widget" << std::endl;

    m_catalogueStackedWidget->addWidget(m_baseSeatWidget);
    m_catalogueStackedWidget->addWidget(m_childSeatWidget);
    m_catalogueStackedWidget->addWidget(m_sportSeatWidget);
    m_catalogueStackedWidget->addWidget(m_luxurySeatWidget);
    std::cout << "[CatalogueView::setupUI] Luxury seat widget added" << std::endl;

    std::cout << "[CatalogueView::setupUI] Setting up layouts" << std::endl;

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_catalogueMenu);
    m_mainLayout->addWidget(m_catalogueStackedWidget);

    setLayout(m_mainLayout);
    std::cout << "[CatalogueView::setupUI] UI set up" << std::endl;
}