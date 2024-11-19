#include "CatalogueSearchChildSeatV.hpp"

CatalogueSearchChildSeatV::CatalogueSearchChildSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void CatalogueSearchChildSeatV::setupUI() {
    std::cout << "[CatalogueSearchChildSeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_ageListWidget = new QListWidget();
    m_weightListWidget = new QListWidget();
    m_heightListWidget = new QListWidget();
    m_safetyKeyListWidget = new QListWidget();
    m_fasteningListWidget = new QListWidget();
    m_drivewayListWidget = new QListWidget();

    m_brandListWidget->setFixedSize(200, 200);
    m_ageListWidget->setFixedSize(200, 200);
    m_weightListWidget->setFixedSize(200, 200);
    m_heightListWidget->setFixedSize(200, 200);
    m_safetyKeyListWidget->setFixedSize(200, 200);
    m_fasteningListWidget->setFixedSize(200, 200);
    m_drivewayListWidget->setFixedSize(200, 200);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_brandListWidget);
    m_layout->addWidget(m_ageListWidget);
    m_layout->addWidget(m_weightListWidget);
    m_layout->addWidget(m_heightListWidget);
    m_layout->addWidget(m_safetyKeyListWidget);
    m_layout->addWidget(m_fasteningListWidget);
    m_layout->addWidget(m_drivewayListWidget);
    
    setLayout(m_layout);
}