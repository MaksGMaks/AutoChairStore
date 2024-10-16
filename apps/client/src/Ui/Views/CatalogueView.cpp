#include "CatalogueView.hpp"

CatalogueView::CatalogueView(IViewModel *viewModel, QWidget *parent) 
: IView(viewModel, parent), 
m_productsVM(viewModel) {
    std::cout << "[CatalogueView::CatalogueView] constructor" << std::endl;
    setupUI();
}

void CatalogueView::getProductList(const QVector<displayData::Products> &products) {
    std::cout << "[CatalogueView::getProductList] Getting product list" << std::endl;
    int count = 0;
    QVector<displayData::Products> products_copy;
    for(auto product : products) {
        count++;
        products_copy.push_back(product);
        if(count == 4) {
            count = 0;
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
            products_copy.clear();
        }

    }
}

void CatalogueView::setupUI() {
    std::cout << "[CatalogueView::setupUI] Setting up UI" << std::endl;
    m_catalogueMenu = new CatalogueMenuSV(this);
    m_catalogueMenu->setFixedHeight(50);

    test_utils test;

    m_product1 = new CatalogueProductSV(test.productName1, test.price1, test.priceUnit, test.image1);
    m_product2 = new CatalogueProductSV(test.productName2, test.price2, test.priceUnit, test.image2);
    m_product3 = new CatalogueProductSV(test.productName1, test.price1, test.priceUnit, test.image1);
    m_product4 = new CatalogueProductSV(test.productName2, test.price2, test.priceUnit, test.image2);
    m_product5 = new CatalogueProductSV(test.productName1, test.price1, test.priceUnit, test.image1);
    m_product6 = new CatalogueProductSV(test.productName2, test.price2, test.priceUnit, test.image2);
    m_product7 = new CatalogueProductSV(test.productName1, test.price1, test.priceUnit, test.image1);
    m_product8 = new CatalogueProductSV(test.productName2, test.price2, test.priceUnit, test.image2);
    m_product9 = new CatalogueProductSV(test.productName1, test.price1, test.priceUnit, test.image1);
    m_product10 = new CatalogueProductSV(test.productName2, test.price2, test.priceUnit, test.image2);
    
    m_product1->setFixedSize(190, 300);
    m_product2->setFixedSize(190, 300);
    m_product3->setFixedSize(190, 300);
    m_product4->setFixedSize(190, 300);
    m_product5->setFixedSize(190, 300);
    m_product6->setFixedSize(190, 300);
    m_product7->setFixedSize(190, 300);
    m_product8->setFixedSize(190, 300);
    m_product9->setFixedSize(190, 300);
    m_product10->setFixedSize(190, 300);

    m_productLine1 = new QHBoxLayout();
    m_productLine1->addWidget(m_product1);
    m_productLine1->addWidget(m_product2);
    m_productLine1->addWidget(m_product3);
    m_productLine1->addWidget(m_product4);

    m_productLine2 = new QHBoxLayout();
    m_productLine2->addWidget(m_product5);
    m_productLine2->addWidget(m_product6);
    m_productLine2->addWidget(m_product7);
    m_productLine2->addWidget(m_product8);

    m_productLine3 = new QHBoxLayout();
    m_productLine3->addWidget(m_product9);
    m_productLine3->addWidget(m_product10);

    QWidget *productLine1Widget = new QWidget(this);
    productLine1Widget->setLayout(m_productLine1);

    QListWidgetItem *productLine1Item = new QListWidgetItem();
    productLine1Item->setSizeHint(productLine1Widget->sizeHint());

    QWidget *productLine2Widget = new QWidget(this);
    productLine2Widget->setLayout(m_productLine2);

    QListWidgetItem *productLine2Item = new QListWidgetItem();
    productLine2Item->setSizeHint(productLine2Widget->sizeHint());

    QWidget *productLine3Widget = new QWidget(this);
    productLine3Widget->setLayout(m_productLine3);

    QListWidgetItem *productLine3Item = new QListWidgetItem();
    productLine3Item->setSizeHint(productLine3Widget->sizeHint());
    
    m_catalogueList = new QListWidget(this);

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