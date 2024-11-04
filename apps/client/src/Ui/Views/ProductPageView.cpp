#include "ProductPageView.hpp"

ProductPageView::ProductPageView(ProductPageViewModel *viewModel, QWidget *parent)
    : IView(viewModel, parent)
    , m_productPageVM(viewModel) {
    std::cout << "[ProductPageView::ProductPageView] constructor" << std::endl;
    setupUi();
    setupConnections();
}

void ProductPageView::onLoadOrder(const QString &id) {
    std::cout << "[ProductPageView::onLoadOrder] Load order" << std::endl;
    productId = id;
    displayData::Products product;
    for(auto &p : m_productPageVM->products()) {
        if(p.id == id) {
            product = p;
            break;
        }
    }
    m_titleLabel->setText(product.name);
    m_priceLabel->setText("");
    m_discountLabel->setText("");
    int price = product.price.toInt();
    if(product.hasDiscount == "TRUE") {
        std::cout << "[ProductPageView::onLoadOrder] Product has discount" << std::endl;
        m_priceLabel->setText(product.price);
        m_discountLabel->setText("-" + product.discount + "%");
        price = product.price.toInt() - (product.discount.toInt() * (product.price.toInt() / 100));
    }
    m_unitPriceLabel->setText(product.priceUnit);
    m_totalPriceLabel->setText(QString::number(price));
    emit vmLoadSeat(product.id);
}

void ProductPageView::onBaseSeatLoadedSuccess(const displayData::BaseSeat &seat) {
    std::cout << "[ProductPageView::onBaseSeatLoadedSuccess] Base seat loaded" << std::endl;
    m_baseSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentIndex(0);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void ProductPageView::onChildSeatLoadedSuccess(const displayData::ChildSeat &seat) {
    std::cout << "[ProductPageView::onChildSeatLoadedSuccess] Child seat loaded" << std::endl;
    m_childSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentIndex(1);
    
    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void ProductPageView::onSportSeatLoadedSuccess(const displayData::SportSeat &seat) {
    std::cout << "[ProductPageView::onSportSeatLoadedSuccess] Sport seat loaded" << std::endl;
    m_sportSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentIndex(2);
    
    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void ProductPageView::onLuxurySeatLoadedSuccess(const displayData::LuxurySeat &seat) {
    std::cout << "[ProductPageView::onLuxurySeatLoadedSuccess] Luxury seat loaded" << std::endl;
    m_luxerySeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentIndex(3);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void ProductPageView::onBackButtonClicked() {
    std::cout << "[ProductPageView::onBackButtonClicked] Back button clicked" << std::endl;
    emit goBack();
}

void ProductPageView::onBuyButtonClicked() {
    std::cout << "[ProductPageView::onBuyButtonClicked] Buy button clicked" << std::endl;
    emit buyProduct(productId);
}

void ProductPageView::onAddToCartButtonClicked() {
    std::cout << "[ProductPageView::onAddToCartButtonClicked] Add to cart button clicked" << std::endl;
    emit addToCart(productId);
}

void ProductPageView::setupConnections() {
    std::cout << "[ProductPageView::setupConnections] setupConnections" << std::endl;
    connect(m_backButton, &QPushButton::clicked, this, &ProductPageView::onBackButtonClicked);
    connect(m_buyButton, &QPushButton::clicked, this, &ProductPageView::onBuyButtonClicked);
    connect(m_addToCartButton, &QPushButton::clicked, this, &ProductPageView::onAddToCartButtonClicked);

    connect(m_productPageVM, &ProductPageViewModel::baseSeatLoadedSuccess, this, &ProductPageView::onBaseSeatLoadedSuccess);
    connect(m_productPageVM, &ProductPageViewModel::childSeatLoadedSuccess, this, &ProductPageView::onChildSeatLoadedSuccess);
    connect(m_productPageVM, &ProductPageViewModel::sportSeatLoadedSuccess, this, &ProductPageView::onSportSeatLoadedSuccess);
    connect(m_productPageVM, &ProductPageViewModel::luxurySeatLoadedSuccess, this, &ProductPageView::onLuxurySeatLoadedSuccess);

    connect(this, &ProductPageView::vmLoadSeat, m_productPageVM, &ProductPageViewModel::onLoadSeat);
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
    
    m_titleLabel = new QLabel("");
    m_priceFont = m_titleLabel->font();
    m_priceFont.setPointSize(28);
    m_priceFont.setBold(true);
    m_titleLabel->setFont(m_priceFont);

    m_discountLabel = new QLabel("");
    m_totalPriceLabel = new QLabel("");
    m_unitPriceLabel = new QLabel("");
    m_priceLabel = new QLabel("");

    m_priceFont = m_priceLabel->font();
    m_priceFont.setPointSize(18);
    m_priceFont.setBold(true);
    m_discountLabel->setFont(m_priceFont);
    m_totalPriceLabel->setFont(m_priceFont);
    m_unitPriceLabel->setFont(m_priceFont);
    m_priceFont.setPointSize(10);
    m_priceFont.setStrikeOut(true);
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