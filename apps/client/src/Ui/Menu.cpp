#include "Menu.hpp"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void Menu::setupUI() {
    m_accountButton = QSharedPointer<QPushButton>::create("Account");
    m_purchaseBusketButton = QSharedPointer<QPushButton>::create("Purchase Busket");
    m_catalogButton = QSharedPointer<QPushButton>::create("Catalog");

    m_accountButton->setFixedSize(100, 30);
    m_purchaseBusketButton->setFixedSize(100, 30);
    m_catalogButton->setFixedSize(100, 30);

    connect(m_accountButton.get(), &QPushButton::clicked, this, &Menu::onAccountButtonClicked);
    connect(m_purchaseBusketButton.get(), &QPushButton::clicked, this, &Menu::onPurchaseBusketButtonClicked);
    connect(m_catalogButton.get(), &QPushButton::clicked, this, &Menu::onCatalogButtonClicked);

    m_layout = QSharedPointer<QHBoxLayout>::create();
    
    m_layout->addWidget(m_accountButton.get());
    m_layout->addWidget(m_purchaseBusketButton.get());
    m_layout->addWidget(m_catalogButton.get());

    setLayout(m_layout.get());
}

void Menu::onAccountButtonClicked() {
    std::cout << "[Menu::onAccountButtonClicked] Account button clicked" << std::endl;
    emit accountButtonClicked();
}

void Menu::onPurchaseBusketButtonClicked() {
    std::cout << "[Menu::onPurchaseBusketButtonClicked] Purchase busket button clicked" << std::endl;
    emit purchaseBusketButtonClicked();
}

void Menu::onCatalogButtonClicked() {
    std::cout << "[Menu::onCatalogButtonClicked] Catalog button clicked" << std::endl;
    emit catalogButtonClicked();
}
