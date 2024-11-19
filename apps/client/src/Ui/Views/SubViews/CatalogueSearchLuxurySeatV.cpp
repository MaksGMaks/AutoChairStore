#include "CatalogueSearchLuxurySeatV.hpp"

CatalogueSearchLuxurySeatV::CatalogueSearchLuxurySeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void CatalogueSearchLuxurySeatV::setupUI() {
    std::cout << "[CatalogueSearchLuxurySeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();
    m_materialListWidget = new QListWidget();
    m_comfortListWidget = new QListWidget();
    m_customDesignListWidget = new QListWidget();

    m_brandListWidget->setFixedSize(200, 200);
    m_suitedForListWidget->setFixedSize(200, 200);
    m_colorListWidget->setFixedSize(200, 200);
    m_materialListWidget->setFixedSize(200, 200);
    m_comfortListWidget->setFixedSize(200, 200);
    m_customDesignListWidget->setFixedSize(200, 200);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_brandListWidget);
    m_layout->addWidget(m_suitedForListWidget);
    m_layout->addWidget(m_colorListWidget);
    m_layout->addWidget(m_materialListWidget);
    m_layout->addWidget(m_comfortListWidget);
    m_layout->addWidget(m_customDesignListWidget);
    setLayout(m_layout);
}