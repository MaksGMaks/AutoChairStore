#include "Menu.hpp"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void Menu::setupUI() {
    m_accountButton = new QPushButton("Account");
    m_purchaseBusketButton = new QPushButton("Purchase Busket");
    m_catalogButton = new QPushButton("Catalog");

    m_accountButton->setFixedSize(100, 30);
    m_purchaseBusketButton->setFixedSize(100, 30);
    m_catalogButton->setFixedSize(100, 30);

    connect(m_accountButton, &QPushButton::clicked, this, &Menu::onAccountButtonClicked);
    connect(m_purchaseBusketButton, &QPushButton::clicked, this, &Menu::onPurchaseBusketButtonClicked);
    connect(m_catalogButton, &QPushButton::clicked, this, &Menu::onCatalogButtonClicked);

    m_layout = new QHBoxLayout();
    
    m_layout->addWidget(m_accountButton);
    m_layout->addWidget(m_purchaseBusketButton);
    m_layout->addWidget(m_catalogButton);

    setLayout(m_layout);
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
