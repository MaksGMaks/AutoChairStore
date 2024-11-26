#include "CatalogueSearchBaseSeatV.hpp"

CatalogueSearchBaseSeatV::CatalogueSearchBaseSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void CatalogueSearchBaseSeatV::addFilters(const QVector<displayData::BaseSeat> &products) {
    std::cout << "[CatalogueSearchBaseSeatV::addFilters] Adding filters" << std::endl;
    m_brandListWidget->clear();
    m_suitedForListWidget->clear();
    m_colorListWidget->clear();
    m_materialListWidget->clear();
    m_typeListWidget->clear();
    
    QVector<QString> brands;
    QVector<QString> suitedFors;
    QVector<QString> colors;
    QVector<QString> materials;
    QVector<QString> types;

    for(auto product : products) {
        if(!brands.contains(product.brand)) {
            brands.push_back(product.brand);
            QCheckBox *checkBox = new QCheckBox(product.brand);
            QListWidgetItem *item = new QListWidgetItem(m_brandListWidget);
            m_brandListWidget->setItemWidget(item, checkBox);
        }
        if(!suitedFors.contains(product.suitableFor)) {
            suitedFors.push_back(product.suitableFor);
            QCheckBox *checkBox = new QCheckBox(product.suitableFor);
            QListWidgetItem *item = new QListWidgetItem(m_suitedForListWidget);
            m_suitedForListWidget->setItemWidget(item, checkBox);
        }
        if(!colors.contains(product.color)) {
            colors.push_back(product.color);
            QCheckBox *checkBox = new QCheckBox(product.color);
            QListWidgetItem *item = new QListWidgetItem(m_colorListWidget);
            m_colorListWidget->setItemWidget(item, checkBox);
        }
        if(!materials.contains(product.material)) {
            materials.push_back(product.material);
            QCheckBox *checkBox = new QCheckBox(product.material);
            QListWidgetItem *item = new QListWidgetItem(m_materialListWidget);
            m_materialListWidget->setItemWidget(item, checkBox);
        }
        if(!types.contains(product.type)) {
            types.push_back(product.type);
            QCheckBox *checkBox = new QCheckBox(product.type);
            QListWidgetItem *item = new QListWidgetItem(m_typeListWidget);
            m_typeListWidget->setItemWidget(item, checkBox);
        }
    }
}

void CatalogueSearchBaseSeatV::onFilterButtonClicked() {
    QVector<QString> brands;
    QVector<QString> suitedFors;
    QVector<QString> colors;
    QVector<QString> materials;
    QVector<QString> types;

    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QListWidgetItem *item = m_brandListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            brands.push_back(checkBox->text());
            std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Brand: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_suitedForListWidget->count(); i++) {
        QListWidgetItem *item = m_suitedForListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_suitedForListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            suitedFors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Suited for: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_colorListWidget->count(); i++) {
        QListWidgetItem *item = m_colorListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_colorListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            colors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Color: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_materialListWidget->count(); i++) {
        QListWidgetItem *item = m_materialListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_materialListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            materials.push_back(checkBox->text());
            std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Material: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_typeListWidget->count(); i++) {
        QListWidgetItem *item = m_typeListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_typeListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            types.push_back(checkBox->text());
            std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Type: " << checkBox->text().toStdString() << std::endl;
        }
    }

    emit filterClicked(brands, suitedFors, colors, materials, types);
}

void CatalogueSearchBaseSeatV::onClearButtonClicked() {
    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QListWidgetItem *item = m_brandListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_suitedForListWidget->count(); i++) {
        QListWidgetItem *item = m_suitedForListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_suitedForListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_colorListWidget->count(); i++) {
        QListWidgetItem *item = m_colorListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_colorListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_materialListWidget->count(); i++) {
        QListWidgetItem *item = m_materialListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_materialListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_typeListWidget->count(); i++) {
        QListWidgetItem *item = m_typeListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_typeListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    emit clearClicked();
}

void CatalogueSearchBaseSeatV::setupConnections() {
    std::cout << "[CatalogueSearchBaseSeatV::setupConnections] Setting up connections" << std::endl;
    connect(m_filterButton, &QPushButton::clicked, this, &CatalogueSearchBaseSeatV::onFilterButtonClicked);
    connect(m_clearButton, &QPushButton::clicked, this, &CatalogueSearchBaseSeatV::onClearButtonClicked);
}

void CatalogueSearchBaseSeatV::setupUI() {
    std::cout << "[CatalogueSearchBaseSeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();
    m_materialListWidget = new QListWidget();
    m_typeListWidget = new QListWidget();

    m_brandListWidget->setFixedWidth(200);
    m_suitedForListWidget->setFixedWidth(200);
    m_colorListWidget->setFixedWidth(200);
    m_materialListWidget->setFixedWidth(200);
    m_typeListWidget->setFixedWidth(200);

    m_brandListWidget->setMinimumHeight(50);
    m_suitedForListWidget->setMinimumHeight(50);
    m_colorListWidget->setMinimumHeight(50);
    m_materialListWidget->setMinimumHeight(50);
    m_typeListWidget->setMinimumHeight(50);

    m_brandLabel = new QLabel("Brand");
    m_suitedForLabel = new QLabel("Suited for");
    m_colorLabel = new QLabel("Color");
    m_materialLabel = new QLabel("Material");
    m_typeLabel = new QLabel("Type");

    QFont font = m_brandLabel->font();
    font.setBold(true);
    font.setPointSize(12);
    m_brandLabel->setFont(font);
    m_suitedForLabel->setFont(font);
    m_colorLabel->setFont(font);
    m_materialLabel->setFont(font);
    m_typeLabel->setFont(font);

    m_filterButton = new QPushButton("Filter");
    m_clearButton = new QPushButton("Clear");

    m_filterButton->setFixedWidth(200);
    m_filterButton->setMinimumHeight(25);

    m_clearButton->setFixedWidth(200);
    m_clearButton->setMinimumHeight(25);

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
    m_layout->addWidget(m_filterButton);
    m_layout->addWidget(m_clearButton);
    
    setLayout(m_layout);
}