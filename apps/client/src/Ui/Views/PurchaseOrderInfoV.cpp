#include "PurchaseOrderInfoV.hpp"

PurchaseOrderInfoV::PurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent) 
: IView(viewModel, parent) 
, m_purchaseOrderVM(viewModel) {
    std::cout << "[PurchaseOrderInfoV::PurchaseOrderInfoV] constructor" << std::endl;
    setupProductInfo();
    setupUi();
    setupConnections();
}

void PurchaseOrderInfoV::setupConnections() {
    std::cout << "[PurchaseOrderInfoV::setupConnections] setupConnections" << std::endl;
    connect(m_cancelOrderButton, &QPushButton::clicked, this, &PurchaseOrderInfoV::onCancelOrderButtonClicked);
    connect(m_backButton, &QPushButton::clicked, this, &PurchaseOrderInfoV::onBackButtonClicked);

    connect(this, &PurchaseOrderInfoV::vmCancelOrder, m_purchaseOrderVM, &PurchaseOrderInfoVM::onCancelOrder);
    connect(this, &PurchaseOrderInfoV::vmLoadSeat, m_purchaseOrderVM, &PurchaseOrderInfoVM::onLoadSeat);
    connect(this, &PurchaseOrderInfoV::vmLoadProduct, m_purchaseOrderVM, &PurchaseOrderInfoVM::onLoadProduct);

    connect(m_purchaseOrderVM, &PurchaseOrderInfoVM::baseSeatLoadedSuccess, this, &PurchaseOrderInfoV::onBaseSeatLoaded);
    connect(m_purchaseOrderVM, &PurchaseOrderInfoVM::childSeatLoadedSuccess, this, &PurchaseOrderInfoV::onChildSeatLoaded);
    connect(m_purchaseOrderVM, &PurchaseOrderInfoVM::sportSeatLoadedSuccess, this, &PurchaseOrderInfoV::onSportSeatLoaded);
    connect(m_purchaseOrderVM, &PurchaseOrderInfoVM::luxurySeatLoadedSuccess, this, &PurchaseOrderInfoV::onLuxurySeatLoaded);

    connect(m_purchaseOrderVM, &PurchaseOrderInfoVM::productLoaded, this, &PurchaseOrderInfoV::onProductLoaded);
}

void PurchaseOrderInfoV::onLoadOrder(const QString &id) {
    std::cout << "[PurchaseOrderInfoV::onLoadOrder] onLoadOrder" << std::endl;
    displayData::PurchaseOrder order;
    for(const auto &o : m_purchaseOrderVM->purchaseOrders()) {
        if(o.id == id) {
            order = o;
            break;
        }
    }
    orderId = order.id;
    m_titleLabel->setText(order.productName);
    m_packageIdLineEdit->setText(order.packageId);
    m_paidInfoLineEdit->setText(order.paidType);
    m_destinationLineEdit->setText(order.destination);
    m_dateLineEdit->setText(order.date);
    m_statusLineEdit->setText(order.status);
    if(order.status == "Canceled" || order.status == "Delivered") {
        m_cancelOrderButton->setEnabled(false);
    } else {
        m_cancelOrderButton->setEnabled(true);
    }

    emit vmLoadSeat(order.productId);
    emit vmLoadProduct(order.productId);
}

void PurchaseOrderInfoV::onCancelOrderButtonClicked() {
    std::cout << "[PurchaseOrderInfoV::onCancelOrderButtonClicked] Cancel order button clicked" << std::endl;
    emit vmCancelOrder(orderId);
}

void PurchaseOrderInfoV::onBackButtonClicked() {
    std::cout << "[PurchaseOrderInfoV::onBackButtonClicked] Back button clicked" << std::endl;
    emit goBack();
}

void PurchaseOrderInfoV::onBaseSeatLoaded(const displayData::BaseSeat &seat) {
    std::cout << "[PurchaseOrderInfoV::onBaseSeatLoaded] Base seat loaded" << std::endl;
    m_baseSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentWidget(m_baseSeatPage);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void PurchaseOrderInfoV::onProductLoaded(const displayData::Products &product) {
    std::cout << "[PurchaseOrderInfoV::onProductLoaded] Product loaded" << std::endl;
    m_titleLabel->setText(product.name);
    m_priceLabel->setText("");
    m_discountLabel->setText("");
    int price = product.price.toInt();
    if(product.hasDiscount == "TRUE") {
        std::cout << "[PurchaseOrderInfoV::onProductLoaded] Product has discount" << std::endl;
        m_priceLabel->setText(product.price);
        m_discountLabel->setText("-" + product.discount + "%");
        price = product.price.toInt() - (product.discount.toInt() * (product.price.toInt() / 100));
    }
    m_unitPriceLabel->setText(product.priceUnit);
    m_totalPriceLabel->setText(QString::number(price));
}

void PurchaseOrderInfoV::onChildSeatLoaded(const displayData::ChildSeat &seat) {
    std::cout << "[PurchaseOrderInfoV::onChildSeatLoaded] Child seat loaded" << std::endl;
    m_childSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentWidget(m_childSeatPage);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void PurchaseOrderInfoV::onSportSeatLoaded(const displayData::SportSeat &seat) {
    std::cout << "[PurchaseOrderInfoV::onSportSeatLoaded] Sport seat loaded" << std::endl;
    m_sportSeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentWidget(m_sportSeatPage);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void PurchaseOrderInfoV::onLuxurySeatLoaded(const displayData::LuxurySeat &seat) {
    std::cout << "[PurchaseOrderInfoV::onLuxurySeatLoaded] Luxery seat loaded" << std::endl;
    m_luxerySeatPage->loadSeat(seat);
    m_stackedWidget->setCurrentWidget(m_luxerySeatPage);

    QImage m_productImage = QImage();
    m_productImage.loadFromData(QByteArray::fromHex(seat.image.toUtf8()));
    m_imageLabel->setPixmap(QPixmap::fromImage(m_productImage).scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);
}

void PurchaseOrderInfoV::onCancelOrder() {
    std::cout << "[PurchaseOrderInfoV::onCancelOrder] Cancel order" << std::endl;
    //m_purchaseOrderVM->modelCancelOrder(orderId.toStdString());
}

void PurchaseOrderInfoV::onGoBack() {
    std::cout << "[PurchaseOrderInfoV::onGoBack] Go back" << std::endl;
    emit goBack();
}

void PurchaseOrderInfoV::setupUi() {
    std::cout << "[PurchaseOrderInfoV::setupUi] setupUi" << std::endl;
    m_spacer = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_titleLabel = new QLabel("Purchase Order Info");
    m_priceFont = m_titleLabel->font();
    m_priceFont.setPointSize(20);
    m_priceFont.setBold(true);
    m_titleLabel->setFont(m_priceFont);
    
    m_packageIdLabel = new QLabel("Package ID:");
    m_paidInfoLabel = new QLabel("Paid Info:");
    m_destinationLabel = new QLabel("Destination:");
    m_dateLabel = new QLabel("Date:");
    m_statusLabel = new QLabel("Status:");

    m_packageIdLineEdit = new QLineEdit();
    m_packageIdLineEdit->setReadOnly(true);
    m_paidInfoLineEdit = new QLineEdit();
    m_paidInfoLineEdit->setReadOnly(true);
    m_destinationLineEdit = new QLineEdit();
    m_destinationLineEdit->setReadOnly(true);
    m_dateLineEdit = new QLineEdit();
    m_dateLineEdit->setReadOnly(true);
    m_statusLineEdit = new QLineEdit();
    m_statusLineEdit->setReadOnly(true);

    m_packageIdLabel->setFixedSize(100, 40);
    m_paidInfoLabel->setFixedSize(100, 40);
    m_destinationLabel->setFixedSize(100, 40);
    m_dateLabel->setFixedSize(100, 40);
    m_statusLabel->setFixedSize(100, 40);

    m_packageIdLineEdit->setFixedSize(300, 40);
    m_paidInfoLineEdit->setFixedSize(300, 40);
    m_destinationLineEdit->setFixedSize(300, 40);
    m_dateLineEdit->setFixedSize(300, 40);
    m_statusLineEdit->setFixedSize(300, 40);

    m_backButton = new QPushButton("Back");
    m_cancelOrderButton = new QPushButton("Cancel Order");
    
    m_titleLayout = new QHBoxLayout();
    m_titleLayout->addWidget(m_backButton);
    m_titleLayout->addWidget(m_titleLabel);

    m_packageIdLayout = new QHBoxLayout();
    m_packageIdLayout->addWidget(m_packageIdLabel);
    m_packageIdLayout->addWidget(m_packageIdLineEdit);

    m_paidInfoLayout = new QHBoxLayout();
    m_paidInfoLayout->addWidget(m_paidInfoLabel);
    m_paidInfoLayout->addWidget(m_paidInfoLineEdit);

    m_destinationLayout = new QHBoxLayout();
    m_destinationLayout->addWidget(m_destinationLabel);
    m_destinationLayout->addWidget(m_destinationLineEdit);

    m_dateLayout = new QHBoxLayout();
    m_dateLayout->addWidget(m_dateLabel);
    m_dateLayout->addWidget(m_dateLineEdit);

    m_statusLayout = new QHBoxLayout();
    m_statusLayout->addWidget(m_statusLabel);
    m_statusLayout->addWidget(m_statusLineEdit);

    m_leftHalfLayout = new QVBoxLayout();
    m_leftHalfLayout->addLayout(m_titleLayout);
    m_leftHalfLayout->addLayout(m_packageIdLayout);
    m_leftHalfLayout->addLayout(m_paidInfoLayout);
    m_leftHalfLayout->addLayout(m_statusLayout);

    m_rightHalfLayout = new QVBoxLayout();
    m_rightHalfLayout->addSpacerItem(m_spacer);
    m_rightHalfLayout->addLayout(m_destinationLayout);
    m_rightHalfLayout->addLayout(m_dateLayout);
    m_rightHalfLayout->addWidget(m_cancelOrderButton);

    m_purchaseOrderLayout = new QHBoxLayout();
    m_purchaseOrderLayout->addLayout(m_leftHalfLayout);
    m_purchaseOrderLayout->addLayout(m_rightHalfLayout);

    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_productInfoWidget);

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addLayout(m_purchaseOrderLayout);
    m_mainLayout->addWidget(m_scrollArea);    
    setLayout(m_mainLayout);
}

void PurchaseOrderInfoV::setupProductInfo() {
    std::cout << "[PurchaseOrderInfoV::setupProductInfo] setupProductInfo" << std::endl;
    m_baseSeatPage = new BaseSeatPage();
    m_childSeatPage = new ChildSeatPage();
    m_sportSeatPage = new SportSeatPage();
    m_luxerySeatPage = new LuxurySeatPage();

    m_vUSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_vDSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_hLSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_productInfoWidget = new QWidget();
    
    m_imageLabel = new QLabel();
    m_imageLabel->setFixedSize(600, 400);
    
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
    m_totalPriceLayout->addWidget(m_discountLabel);
    m_totalPriceLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_totalPriceLayout->addWidget(m_totalPriceLabel);
    m_totalPriceLayout->addWidget(m_unitPriceLabel);
    m_totalPriceLayout->addItem(m_hRSpacer);

    m_priceLayout = new QHBoxLayout();
    m_priceLayout->addItem(new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_priceLayout->addWidget(m_priceLabel);
    m_priceLayout->addItem(m_hRSpacer);

    m_priceInfoLayout = new QVBoxLayout();
    m_priceInfoLayout->addItem(m_vUSpacer);
    m_priceInfoLayout->addLayout(m_totalPriceLayout);
    m_priceInfoLayout->addLayout(m_priceLayout);
    m_priceInfoLayout->addItem(m_vDSpacer);

    m_productInfoLayout = new QHBoxLayout();
    m_productInfoLayout->addWidget(m_imageLabel);
    m_productInfoLayout->addLayout(m_priceInfoLayout);

    m_productInfoMainLayout = new QVBoxLayout();
    m_productInfoMainLayout->addLayout(m_productInfoLayout);
    m_productInfoMainLayout->addWidget(m_stackedWidget);

    m_productInfoWidget->setLayout(m_productInfoMainLayout);
}