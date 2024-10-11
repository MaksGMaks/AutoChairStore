#include "Menu.hpp"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void Menu::setupUI() {
    m_accountButton = new QPushButton("Account");
    m_purchaseBusketButton = new QPushButton("Purchase Busket");
    m_catalogButton = new QPushButton("Catalog");

    m_accountButton->setFixedSize(200, 40);
    m_purchaseBusketButton->setFixedSize(200, 40);
    m_catalogButton->setFixedSize(200, 40);

    connect(m_accountButton, &QPushButton::clicked, this, &Menu::onAccountButtonClicked);
    connect(m_purchaseBusketButton, &QPushButton::clicked, this, &Menu::onPurchaseBusketButtonClicked);
    connect(m_catalogButton, &QPushButton::clicked, this, &Menu::onCatalogButtonClicked);

    m_accountIcon = QIcon(":/icons/account.png");
    m_purchaseBusketIcon = QIcon(":/icons/shopping_basket.png");
    m_catalogIcon = QIcon(":/icons/catalogue.png");

    m_accountButton->setIcon(m_accountIcon);
    m_purchaseBusketButton->setIcon(m_purchaseBusketIcon);
    m_catalogButton->setIcon(m_catalogIcon);

    QSize iconSize(35, 35);
    m_accountButton->setIconSize(iconSize);
    m_purchaseBusketButton->setIconSize(iconSize);
    m_catalogButton->setIconSize(iconSize);

    m_layout = new QHBoxLayout();
    
    m_layout->addWidget(m_catalogButton);
    m_layout->addWidget(m_purchaseBusketButton);
    m_layout->addWidget(m_accountButton);

    setLayout(m_layout);
}

void Menu::onAccountButtonClicked() {
    std::cout << "[Menu::onAccountButtonClicked] Account button clicked" << std::endl;
    emit accountButtonClicked();
}

void Menu::onPurchaseBusketButtonClicked() {
    std::cout << "[Menu::onPurchaseBusketButtonClicked] Purchase busket button clicked" << std::endl;
    emit Menu::purchaseBusketButtonClicked();
}

void Menu::onCatalogButtonClicked() {
    std::cout << "[Menu::onCatalogButtonClicked] Catalog button clicked" << std::endl;
    emit Menu::catalogButtonClicked();
}
