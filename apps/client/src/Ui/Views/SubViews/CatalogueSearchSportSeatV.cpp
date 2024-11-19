#include "CatalogueSearchSportSeatV.hpp"

CatalogueSearchSportSeatV::CatalogueSearchSportSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void CatalogueSearchSportSeatV::setupUI() {
    std::cout << "[CatalogueSearchSportSeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_shellTypeListWidget = new QListWidget();
    m_shellMaterialListWidget = new QListWidget();
    m_coverMaterialListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();

    m_brandListWidget->setFixedSize(200, 200);
    m_suitedForListWidget->setFixedSize(200, 200);
    m_shellTypeListWidget->setFixedSize(200, 200);
    m_shellMaterialListWidget->setFixedSize(200, 200);
    m_coverMaterialListWidget->setFixedSize(200, 200);
    m_colorListWidget->setFixedSize(200, 200);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_brandListWidget);
    m_layout->addWidget(m_suitedForListWidget);
    m_layout->addWidget(m_shellTypeListWidget);
    m_layout->addWidget(m_shellMaterialListWidget);
    m_layout->addWidget(m_coverMaterialListWidget);
    m_layout->addWidget(m_colorListWidget);
    setLayout(m_layout);
}