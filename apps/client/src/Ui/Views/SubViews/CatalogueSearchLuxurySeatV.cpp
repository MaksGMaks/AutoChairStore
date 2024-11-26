#include "CatalogueSearchLuxurySeatV.hpp"

CatalogueSearchLuxurySeatV::CatalogueSearchLuxurySeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void CatalogueSearchLuxurySeatV::addFilters(const QVector<displayData::LuxurySeat> &products) {
    std::cout << "[CatalogueSearchLuxurySeatV::addFilters] Adding filters" << std::endl;
    m_brandListWidget->clear();
    m_suitedForListWidget->clear();
    m_colorListWidget->clear();
    m_materialListWidget->clear();
    m_comfortListWidget->clear();
    m_customDesignListWidget->clear();

    QVector<QString> brands;
    QVector<QString> suitedFors;
    QVector<QString> colors;
    QVector<QString> materials;
    QVector<QString> comforts;
    QVector<QString> customDesigns;

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
        if(!comforts.contains(product.comfortLevel)) {
            comforts.push_back(product.comfortLevel);
            QCheckBox *checkBox = new QCheckBox(product.comfortLevel);
            QListWidgetItem *item = new QListWidgetItem(m_comfortListWidget);
            m_comfortListWidget->setItemWidget(item, checkBox);
        }
        if(!customDesigns.contains(product.customDesign)) {
            customDesigns.push_back(product.customDesign);
            QCheckBox *checkBox = new QCheckBox(product.customDesign);
            QListWidgetItem *item = new QListWidgetItem(m_customDesignListWidget);
            m_customDesignListWidget->setItemWidget(item, checkBox);
        }
    }
}

void CatalogueSearchLuxurySeatV::onFilterButtonClicked() {
    QVector<QString> brands{};
    QVector<QString> suitedFors{};
    QVector<QString> colors{};
    QVector<QString> materials{};
    QVector<QString> comforts{};
    QVector<QString> customDesigns{};

    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(m_brandListWidget->item(i)));
        if(checkBox->isChecked()) {
            brands.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Brand: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_suitedForListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_suitedForListWidget->itemWidget(m_suitedForListWidget->item(i)));
        if(checkBox->isChecked()) {
            suitedFors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Suited for: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_colorListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_colorListWidget->itemWidget(m_colorListWidget->item(i)));
        if(checkBox->isChecked()) {
            colors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Color: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_materialListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_materialListWidget->itemWidget(m_materialListWidget->item(i)));
        if(checkBox->isChecked()) {
            materials.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Material: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_comfortListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_comfortListWidget->itemWidget(m_comfortListWidget->item(i)));
        if(checkBox->isChecked()) {
            comforts.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Comfort: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_customDesignListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_customDesignListWidget->itemWidget(m_customDesignListWidget->item(i)));
        if(checkBox->isChecked()) {
            customDesigns.push_back(checkBox->text());
            std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Custom design: " << checkBox->text().toStdString() << std::endl;
        }
    }

    emit filterClicked(brands, suitedFors, colors, materials, comforts, customDesigns);
}

void CatalogueSearchLuxurySeatV::onClearButtonClicked() {
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

    for(int i = 0; i < m_comfortListWidget->count(); i++) {
        QListWidgetItem *item = m_comfortListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_comfortListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_customDesignListWidget->count(); i++) {
        QListWidgetItem *item = m_customDesignListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_customDesignListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    emit clearClicked();
}

void CatalogueSearchLuxurySeatV::setupConnections() {
    std::cout << "[CatalogueSearchLuxurySeatV::setupConnections] Setting up connections" << std::endl;
    connect(m_filterButton, &QPushButton::clicked, this, &CatalogueSearchLuxurySeatV::onFilterButtonClicked);
    connect(m_clearButton, &QPushButton::clicked, this, &CatalogueSearchLuxurySeatV::onClearButtonClicked);
}

void CatalogueSearchLuxurySeatV::setupUI() {
    std::cout << "[CatalogueSearchLuxurySeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();
    m_materialListWidget = new QListWidget();
    m_comfortListWidget = new QListWidget();
    m_customDesignListWidget = new QListWidget();

    m_brandListWidget->setFixedWidth(200);
    m_suitedForListWidget->setFixedWidth(200);
    m_colorListWidget->setFixedWidth(200);
    m_materialListWidget->setFixedWidth(200);
    m_comfortListWidget->setFixedWidth(200);
    m_customDesignListWidget->setFixedWidth(200);

    m_brandListWidget->setMinimumHeight(50);
    m_suitedForListWidget->setMinimumHeight(50);
    m_colorListWidget->setMinimumHeight(50);
    m_materialListWidget->setMinimumHeight(50);
    m_comfortListWidget->setMinimumHeight(50);
    m_customDesignListWidget->setMinimumHeight(50);

    m_brandLabel = new QLabel("Brand");
    m_suitedForLabel = new QLabel("Suited for");
    m_colorLabel = new QLabel("Color");
    m_materialLabel = new QLabel("Material");
    m_comfortLabel = new QLabel("Comfort");
    m_customDesignLabel = new QLabel("Custom design");

    QFont font = m_brandLabel->font();
    font.setBold(true);
    font.setPointSize(12);

    m_brandLabel->setFont(font);
    m_suitedForLabel->setFont(font);
    m_colorLabel->setFont(font);
    m_materialLabel->setFont(font);
    m_comfortLabel->setFont(font);
    m_customDesignLabel->setFont(font);

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
    m_layout->addWidget(m_comfortLabel);
    m_layout->addWidget(m_comfortListWidget);
    m_layout->addWidget(m_customDesignLabel);
    m_layout->addWidget(m_customDesignListWidget);
    m_layout->addWidget(m_filterButton);
    m_layout->addWidget(m_clearButton);

    setLayout(m_layout);
}