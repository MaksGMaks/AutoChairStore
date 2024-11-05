#include "BasketView.hpp"

BasketView::BasketView(BasketViewModel *viewModel, QWidget *parent)
    : IView(viewModel, parent)
    , m_basketVM(viewModel) {
    std::cout << "[BasketView::BasketView] constructor" << std::endl;
    setupUi();
    setupConnections();
}

void BasketView::onAddToBasketButtonClicked(const QString &id) {
    std::cout << "[BasketView::onAddToBasketButtonClicked] Add to basket button clicked" << std::endl;
    emit addToBasket(id);
}

void BasketView::onProductLoaded() {
    std::cout << "[BasketView::onProductLoaded] Product loaded" << std::endl;

}

void BasketView::setupConnections() {
    std::cout << "[BasketView::setupConnections] setupConnections" << std::endl;
}

void BasketView::setupUi() {
    std::cout << "[BasketView::setupUi] setupUi" << std::endl;
    m_paidMethodComboBox = new QComboBox();
    m_paidMethodComboBox->addItems({"Cash", "Card"});
    m_paidMethodComboBox->setEnabled(false);
    m_deliveryMethodComboBox = new QComboBox();
    m_deliveryMethodComboBox->addItems({"Nova poshta", "Ukr Poshta"});

    m_totalPriceLabel = new QLabel("Total price:");
    m_totalPriceValueLabel = new QLabel("");
    m_priceUnitLabel = new QLabel("");
    m_deliveryPriceLabel = new QLabel("Delivery price:");
    m_deliveryPriceValueLabel = new QLabel("");
    m_deliveryPriceUnitLabel = new QLabel("");
    m_adressLabel = new QLabel("Adress (deliver to home):");
    m_paymentMethodLabel = new QLabel("Payment method:");
    m_deliveryMethodLabel = new QLabel("Delivery method:");

    m_adressLineEdit = new QLineEdit();

    m_totalPriceLabel->setFixedSize(200, 40);
    m_totalPriceValueLabel->setFixedSize(200, 40);
    m_deliveryPriceLabel->setFixedSize(200, 40);
    m_deliveryPriceValueLabel->setFixedSize(200, 40);
    m_adressLabel->setFixedSize(200, 40);
    m_paymentMethodLabel->setFixedSize(200, 40);
    m_deliveryMethodLabel->setFixedSize(200, 40);

    m_adressLineEdit->setFixedSize(400, 40);

    QHBoxLayout *m_totalPriceLayout = new QHBoxLayout();
    m_totalPriceLayout->addWidget(m_totalPriceLabel);
    m_totalPriceLayout->addWidget(m_totalPriceValueLabel);
    m_totalPriceLayout->addWidget(m_priceUnitLabel);

    QHBoxLayout *m_deliveryPriceLayout = new QHBoxLayout();
    m_deliveryPriceLayout->addWidget(m_deliveryPriceLabel);
    m_deliveryPriceLayout->addWidget(m_deliveryPriceValueLabel);
    m_deliveryPriceLayout->addWidget(m_deliveryPriceUnitLabel);

    QHBoxLayout *m_adressLayout = new QHBoxLayout();
    m_adressLayout->addWidget(m_adressLabel);
    m_adressLayout->addWidget(m_adressLineEdit);

    QHBoxLayout *m_paymentMethodLayout = new QHBoxLayout();
    m_paymentMethodLayout->addWidget(m_paymentMethodLabel);
    m_paymentMethodLayout->addWidget(m_paidMethodComboBox);

    QHBoxLayout *m_deliveryMethodLayout = new QHBoxLayout();
    m_deliveryMethodLayout->addWidget(m_deliveryMethodLabel);
    m_deliveryMethodLayout->addWidget(m_deliveryMethodComboBox);

    m_buyButton = new QPushButton("Buy");
    m_cancelButton = new QPushButton("Cancel");

    m_ordersTable = new QTableWidget();
    m_ordersTable->setColumnCount(4);
    m_ordersTable->setHorizontalHeaderLabels({"id", "Product Name", "Price", "Unit"});
    m_ordersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_ordersTable->setColumnWidth(1, 424);
    m_ordersTable->setColumnWidth(2, 100);
    m_ordersTable->setColumnWidth(3, 100);

    for(int i = 0; i < m_ordersTable->columnCount(); i++) {
        m_ordersTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
    }
    m_ordersTable->setFixedWidth(626);
    m_ordersTable->setColumnHidden(0, true);

    QHBoxLayout *m_productsLayout = new QHBoxLayout();
    m_productsLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
    m_productsLayout->addWidget(m_ordersTable);
    m_productsLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));

    QVBoxLayout *m_ordersLayout = new QVBoxLayout();
    m_ordersLayout->addLayout(m_totalPriceLayout);
    m_ordersLayout->addLayout(m_deliveryPriceLayout);
    m_ordersLayout->addLayout(m_adressLayout);
    m_ordersLayout->addLayout(m_paymentMethodLayout);
    m_ordersLayout->addLayout(m_deliveryMethodLayout);
    m_ordersLayout->addWidget(m_buyButton);
    m_ordersLayout->addWidget(m_cancelButton);
    
    QHBoxLayout *m_compressOrderLayout = new QHBoxLayout();
    m_compressOrderLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
    m_compressOrderLayout->addLayout(m_ordersLayout);
    m_compressOrderLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));

    QVBoxLayout *m_mainLayout = new QVBoxLayout();
    m_mainLayout->addLayout(m_compressOrderLayout);
    m_mainLayout->addLayout(m_productsLayout);
    setLayout(m_mainLayout);
}