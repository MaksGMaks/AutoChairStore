#include "Menu.hpp"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void Menu::setupUI() {
    m_accountButton = std::make_unique<QPushButton>("Account");
    m_purchaseBusketButton = std::make_unique<QPushButton>("Purchase Busket");
    m_catalogButton = std::make_unique<QPushButton>("Catalog");

    m_accountButton->setFixedSize(100, 30);
    m_purchaseBusketButton->setFixedSize(100, 30);
    m_catalogButton->setFixedSize(100, 30);

    connect(m_accountButton.get(), &QPushButton::clicked, this, &Menu::onAccountButtonClicked);
    connect(m_purchaseBusketButton.get(), &QPushButton::clicked, this, &Menu::onPurchaseBusketButtonClicked);
    connect(m_catalogButton.get(), &QPushButton::clicked, this, &Menu::onCatalogButtonClicked);

    m_layout = std::make_unique<QHBoxLayout>();
    
    m_layout->addWidget(m_accountButton.get());
    m_layout->addWidget(m_purchaseBusketButton.get());
    m_layout->addWidget(m_catalogButton.get());

    setLayout(m_layout.release());
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
