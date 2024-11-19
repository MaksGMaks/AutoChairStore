#include "CatalogueSearchBaseSeatV.hpp"

CatalogueSearchBaseSeatV::CatalogueSearchBaseSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void CatalogueSearchBaseSeatV::addFilters(const QVector<displayData::BaseSeat> &products) {
    std::cout << "[CatalogueSearchBaseSeatV::addFilters] Adding filters" << std::endl;
    for(auto product : products) {
        QCheckBox *checkBox = new QCheckBox(product.brand);
        QListWidgetItem *item = new QListWidgetItem(m_brandListWidget);
        m_brandListWidget->setItemWidget(item, checkBox);

        QCheckBox *checkBox2 = new QCheckBox(product.suitableFor);
        QListWidgetItem *item2 = new QListWidgetItem(m_suitedForListWidget);
        m_suitedForListWidget->setItemWidget(item2, checkBox2);

        QCheckBox *checkBox3 = new QCheckBox(product.color);
        QListWidgetItem *item3 = new QListWidgetItem(m_colorListWidget);
        m_colorListWidget->setItemWidget(item3, checkBox3);

        QCheckBox *checkBox4 = new QCheckBox(product.material);
        QListWidgetItem *item4 = new QListWidgetItem(m_materialListWidget);
        m_materialListWidget->setItemWidget(item4, checkBox4);

        QCheckBox *checkBox5 = new QCheckBox(product.type);
        QListWidgetItem *item5 = new QListWidgetItem(m_typeListWidget);
        m_typeListWidget->setItemWidget(item5, checkBox5);
    }
}

void CatalogueSearchBaseSeatV::setupUI() {
    std::cout << "[CatalogueSearchBaseSeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();
    m_materialListWidget = new QListWidget();
    m_typeListWidget = new QListWidget();

    m_brandListWidget->setFixedSize(200, 200);
    m_suitedForListWidget->setFixedSize(200, 200);
    m_colorListWidget->setFixedSize(200, 200);
    m_materialListWidget->setFixedSize(200, 200);
    m_typeListWidget->setFixedSize(200, 200);

    m_brandLabel = new QLabel("Brand");
    m_suitedForLabel = new QLabel("Suited for");
    m_colorLabel = new QLabel("Color");
    m_materialLabel = new QLabel("Material");
    m_typeLabel = new QLabel("Type");

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_brandLabel);
    m_layout->addWidget(m_brandListWidget);
    m_layout->addWidget(m_suitedForLabel);
    m_layout->addWidget(m_suitedForListWidget);
    m_layout->addWidget(m_colorLabel);
    m_layout->addWidget(m_colorListWidget);
    m_layout->addWidget(m_materialLabel);
    m_layout->addWidget(m_materialListWidget);
    m_layout->addWidget(m_typeLabel);
    m_layout->addWidget(m_typeListWidget);
    
    setLayout(m_layout);
}