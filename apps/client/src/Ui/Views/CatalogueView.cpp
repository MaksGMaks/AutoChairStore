#include "CatalogueView.hpp"

CatalogueView::CatalogueView(IViewModel *viewModel, QWidget *parent) 
: IView(viewModel, parent), 
m_productsVM(viewModel) {
    std::cout << "[CatalogueView::CatalogueView] constructor" << std::endl;
    setupUI();
    setupConnections();
    getProductList(m_products);
}

void CatalogueView::getProductList(const QVector<displayData::Products> &products) {
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
                CatalogueProductSV *productSV = new CatalogueProductSV(product.name, product.price, product.priceUnit, product.photo);
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
                productSV->setFixedSize(190, 300);
                productLine->addWidget(productSV);
            }
            QWidget *productLineWidget = new QWidget(this);
            productLineWidget->setLayout(productLine);
            QListWidgetItem *productLineItem = new QListWidgetItem();
            productLineItem->setSizeHint(productLineWidget->sizeHint());
            m_catalogueList->addItem(productLineItem);
            m_catalogueList->setItemWidget(productLineItem, productLineWidget);
            products_copy.clear();
        }
        if(product_ == products.last()) {
            QHBoxLayout *productLine = new QHBoxLayout();
            for(auto product : products_copy) {
                CatalogueProductSV *productSV = new CatalogueProductSV(product.name, product.price, product.priceUnit, product.photo);
                productSV->setFixedSize(190, 300);
                productLine->addWidget(productSV);
            }
            QWidget *productLineWidget = new QWidget(this);
            productLineWidget->setLayout(productLine);
            QListWidgetItem *productLineItem = new QListWidgetItem();
            productLineItem->setSizeHint(productLineWidget->sizeHint());
            m_catalogueList->addItem(productLineItem);
            m_catalogueList->setItemWidget(productLineItem, productLineWidget);
            products_copy.clear();
        }
    }
}

void CatalogueView::setupUI() {
    std::cout << "[CatalogueView::setupUI] Setting up UI" << std::endl;

    test_utils testUtils;

    displayData::Products product;
    product.name = testUtils.productName1;
    product.price = testUtils.price1;
    product.priceUnit = testUtils.priceUnit;
    product.photo = testUtils.image1;

    displayData::Products product2;
    product2.name = testUtils.productName2;
    product2.price = testUtils.price2;
    product2.priceUnit = testUtils.priceUnit;
    product2.photo = testUtils.image2;

    for(int i = 0; i < 10; i++) {
        if(i % 2 == 0) {
            product.id = QString::number(i);
            m_products.push_back(product);
        } else {
            product2.id = QString::number(i);
            m_products.push_back(product2);
        }
    }

    m_catalogueMenu = new CatalogueMenuSV(this);
    m_catalogueMenu->setFixedHeight(50);

    m_catalogueList = new QListWidget(this);
    m_catalogueList->setSelectionMode(QAbstractItemView::NoSelection);

    m_catalogueSearch = new CatalogueSearchSV(this);
    m_catalogueSearch->setFixedWidth(200);

    m_catalogueLayout = new QHBoxLayout();
    m_catalogueLayout->addWidget(m_catalogueSearch);
    m_catalogueLayout->addWidget(m_catalogueList);

    m_catalogueWidget = new QWidget();
    m_catalogueWidget->setLayout(m_catalogueLayout);

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_catalogueMenu);
    m_mainLayout->addWidget(m_catalogueWidget);

    setLayout(m_mainLayout);
}

void CatalogueView::setupConnections() {
    std::cout << "[CatalogueView::setupConnections] Setting up connections" << std::endl;
}