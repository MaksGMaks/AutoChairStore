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
    QVector<displayData::Products> products = m_basketVM->productsInBasket();
    m_ordersTable->clearContents();
    m_ordersTable->setRowCount(products.size());
    int row = 0;
    int totalPrice = 0;
    for(auto &product : products) {
        m_ordersTable->setItem(row, 0, new QTableWidgetItem(product.id));
        m_ordersTable->setItem(row, 1, new QTableWidgetItem(product.name));
        int price = product.price.toInt();
        if(product.hasDiscount == "TRUE") {
            price = product.price.toInt() - (product.discount.toInt() * (product.price.toInt() / 100));
        }
        m_ordersTable->setItem(row, 2, new QTableWidgetItem(QString::number(price)));
        totalPrice += price;
        m_ordersTable->setItem(row, 3, new QTableWidgetItem(product.priceUnit));
        row++;
    }
    m_ordersTable->setColumnHidden(0, true);
    m_totalPriceValueLabel->setText(QString::number(totalPrice + (100 * products.size())));
    m_deliveryPriceValueLabel->setText(QString::number(100 * products.size()));
}

void BasketView::onBuyButtonClicked() {
    std::cout << "[BasketView::onBuyButtonClicked] Buy button clicked" << std::endl;
    if(m_basketVM->productsInBasket().empty()) {
        m_errorMessageBox->showErrorMessage("Basket is empty");
        return;
    }
    if(m_adressLineEdit->text().isEmpty()) {
        m_errorMessageBox->showErrorMessage("Adress is empty");
        return;
    }
    displayData::PurchaseOrder order;
    order.paidType = m_paidMethodComboBox->currentText();
    order.deliveryType = m_deliveryMethodComboBox->currentText();
    order.destination = m_adressLineEdit->text();
    emit createOrder(order);
}

void BasketView::onOrderCreated() {
    std::cout << "[BasketView::onOrderCreated] Order created" << std::endl;
    m_basketVM->productsInBasket().clear();
    m_ordersTable->clearContents();
    m_totalPriceValueLabel->clear();
    m_deliveryPriceValueLabel->clear();
    m_adressLineEdit->clear();
    m_successMessageBox->showInformationMessage("Success!", "Your order has been created");
}

void BasketView::onCanceledButtonClicked() {
    std::cout << "[BasketView::onCanceledButtonClicked] Cancel button clicked" << std::endl;
    m_ordersTable->clearContents();
    m_totalPriceValueLabel->clear();
    m_deliveryPriceValueLabel->clear();
    m_adressLineEdit->clear();
}

void BasketView::onRemoveButtonClicked() {
    std::cout << "[BasketView::onRemoveButtonClicked] Remove button clicked" << std::endl;
    int row = m_ordersTable->currentRow();
    QString id = m_ordersTable->item(row, 0)->text();
    m_basketVM->onRemoveFromBasket(id);
}

void BasketView::setupConnections() {
    std::cout << "[BasketView::setupConnections] setupConnections" << std::endl;
    connect(m_basketVM, &BasketViewModel::addedToBasket, this, &BasketView::onProductLoaded);
    connect(m_basketVM, &BasketViewModel::orderCreated, this, &BasketView::onOrderCreated);

    connect(this, &BasketView::createOrder, m_basketVM, &BasketViewModel::onCreateOrder);
    connect(this, &BasketView::addToBasket, m_basketVM, &BasketViewModel::onAddToBasket);

    connect(m_buyButton, &QPushButton::clicked, this, &BasketView::onBuyButtonClicked);
    connect(m_ordersTable, &QTableWidget::cellDoubleClicked, this, &BasketView::onRemoveButtonClicked);
}

void BasketView::setupUi() {
    std::cout << "[BasketView::setupUi] setupUi" << std::endl;
    m_errorMessageBox = new MessageBox();
    m_successMessageBox = new MessageBox();

    m_paidMethodComboBox = new QComboBox();
    m_paidMethodComboBox->addItems({"Cash", "Card"});
    m_paidMethodComboBox->setEnabled(false);
    m_deliveryMethodComboBox = new QComboBox();
    m_deliveryMethodComboBox->addItems({"Nova poshta", "Ukr Poshta"});

    m_totalPriceLabel = new QLabel("Total price(inc. del):");
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
    m_ordersTable->verticalHeader()->setVisible(false);
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