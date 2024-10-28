#include "ProductPageView.hpp"

ProductPageView::ProductPageView(CatalogueViewModel *viewModel, QWidget *parent)
    : IView(viewModel, parent)
    , m_productPageVM(viewModel) {
    std::cout << "[ProductPageView::ProductPageView] constructor" << std::endl;
    setupUi();
}

void ProductPageView::onLoadOrder(const QString &id) {
    std::cout << "[ProductPageView::onLoadOrder] Load order" << std::endl;
    productId = id;
    //m_productPageVM->onLoadOrder(id);
}

void ProductPageView::setupConnections() {
    std::cout << "[ProductPageView::setupConnections] setupConnections" << std::endl;
}

void ProductPageView::setupUi() {
    std::cout << "[ProductPageView::setupUi] setupUi" << std::endl;
    m_baseSeatPage = new BaseSeatPage();
    m_childSeatPage = new ChildSeatPage();
    m_sportSeatPage = new SportSeatPage();
    m_luxerySeatPage = new LuxurySeatPage();

    m_vUSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_vDSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_hLSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    QWidget *m_productInfoWidget = new QWidget();

    m_backButton = new QPushButton("Back");
    m_backButton->setFixedSize(80, 60);
    m_buyButton = new QPushButton("Buy");
    m_addToCartButton = new QPushButton("Add to cart");
    
    m_imageLabel = new QLabel();
    m_imageLabel->setFixedSize(600, 400);
    
    m_titleLabel = new QLabel("Product name");
    m_priceFont = m_titleLabel->font();
    m_priceFont.setPointSize(28);
    m_priceFont.setBold(true);
    m_titleLabel->setFont(m_priceFont);

    m_discountLabel = new QLabel("25%");
    m_totalPriceLabel = new QLabel("3000");
    m_unitPriceLabel = new QLabel("грн");
    m_priceLabel = new QLabel("4000");

    m_priceFont = m_priceLabel->font();
    m_priceFont.setPointSize(18);
    m_priceFont.setBold(true);
    m_discountLabel->setFont(m_priceFont);
    m_totalPriceLabel->setFont(m_priceFont);
    m_unitPriceLabel->setFont(m_priceFont);
    m_priceFont.setPointSize(10);
    m_priceLabel->setFont(m_priceFont);

    m_stackedWidget = new QStackedWidget();
    m_stackedWidget->addWidget(m_baseSeatPage);
    m_stackedWidget->addWidget(m_childSeatPage);
    m_stackedWidget->addWidget(m_sportSeatPage);
    m_stackedWidget->addWidget(m_luxerySeatPage);

    m_totalPriceLayout = new QHBoxLayout();
    m_totalPriceLayout->addItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_totalPriceLayout->addWidget(m_discountLabel);
    m_totalPriceLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_totalPriceLayout->addWidget(m_totalPriceLabel);
    m_totalPriceLayout->addWidget(m_unitPriceLabel);
    m_totalPriceLayout->addItem(m_hRSpacer);

    m_priceLayout = new QHBoxLayout();
    m_priceLayout->addItem(new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_priceLayout->addWidget(m_priceLabel);
    m_priceLayout->addItem(m_hRSpacer);

    QHBoxLayout *shopButtonsLayout = new QHBoxLayout();
    shopButtonsLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    shopButtonsLayout->addWidget(m_buyButton);
    shopButtonsLayout->addWidget(m_addToCartButton);
    shopButtonsLayout->addSpacerItem(m_hRSpacer);

    m_priceInfoLayout = new QVBoxLayout();
    m_priceInfoLayout->addItem(m_vUSpacer);
    m_priceInfoLayout->addWidget(m_titleLabel);
    m_priceInfoLayout->addLayout(m_totalPriceLayout);
    m_priceInfoLayout->addLayout(m_priceLayout);
    m_priceInfoLayout->addLayout(shopButtonsLayout);
    m_priceInfoLayout->addItem(m_vDSpacer);

    QVBoxLayout *m_backButtonLayout = new QVBoxLayout();
    m_backButtonLayout->addWidget(m_backButton);
    m_backButtonLayout->addSpacerItem(m_vDSpacer);

    m_productInfoLayout = new QHBoxLayout();
    m_productInfoLayout->addLayout(m_backButtonLayout);
    m_productInfoLayout->addWidget(m_imageLabel);
    m_productInfoLayout->addLayout(m_priceInfoLayout);

    m_productInfoMainLayout = new QVBoxLayout();
    m_productInfoMainLayout->addLayout(m_productInfoLayout);
    m_productInfoMainLayout->addWidget(m_stackedWidget);

    m_productInfoWidget->setLayout(m_productInfoMainLayout);

    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidget(m_productInfoWidget);
    m_scrollArea->setWidgetResizable(true);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_scrollArea);
    setLayout(mainLayout);
}