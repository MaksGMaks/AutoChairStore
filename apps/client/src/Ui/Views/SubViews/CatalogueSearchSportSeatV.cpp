#include "CatalogueSearchSportSeatV.hpp"

CatalogueSearchSportSeatV::CatalogueSearchSportSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void CatalogueSearchSportSeatV::addFilters(const QVector<displayData::SportSeat> &products) {
    std::cout << "[CatalogueSearchSportSeatV::addFilters] Adding filters" << std::endl;
    m_brandListWidget->clear();
    m_suitedForListWidget->clear();
    m_shellTypeListWidget->clear();
    m_shellMaterialListWidget->clear();
    m_coverMaterialListWidget->clear();
    m_colorListWidget->clear();

    QVector<QString> brands;
    QVector<QString> suitedFors;
    QVector<QString> shellTypes;
    QVector<QString> shellMaterials;
    QVector<QString> coverMaterials;
    QVector<QString> colors;

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
        if(!shellTypes.contains(product.shellType)) {
            shellTypes.push_back(product.shellType);
            QCheckBox *checkBox = new QCheckBox(product.shellType);
            QListWidgetItem *item = new QListWidgetItem(m_shellTypeListWidget);
            m_shellTypeListWidget->setItemWidget(item, checkBox);
        }
        if(!shellMaterials.contains(product.shellMaterial)) {
            shellMaterials.push_back(product.shellMaterial);
            QCheckBox *checkBox = new QCheckBox(product.shellMaterial);
            QListWidgetItem *item = new QListWidgetItem(m_shellMaterialListWidget);
            m_shellMaterialListWidget->setItemWidget(item, checkBox);
        }
        if(!coverMaterials.contains(product.coverMaterial)) {
            coverMaterials.push_back(product.coverMaterial);
            QCheckBox *checkBox = new QCheckBox(product.coverMaterial);
            QListWidgetItem *item = new QListWidgetItem(m_coverMaterialListWidget);
            m_coverMaterialListWidget->setItemWidget(item, checkBox);
        }
        if(!colors.contains(product.color)) {
            colors.push_back(product.color);
            QCheckBox *checkBox = new QCheckBox(product.color);
            QListWidgetItem *item = new QListWidgetItem(m_colorListWidget);
            m_colorListWidget->setItemWidget(item, checkBox);
        }
    }
}

void CatalogueSearchSportSeatV::onFilterButtonClicked() {
    QVector<QString> brands{};
    QVector<QString> suitedFors{};
    QVector<QString> shellTypes{};
    QVector<QString> shellMaterials{};
    QVector<QString> coverMaterials{};
    QVector<QString> colors{};

    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(m_brandListWidget->item(i)));
        if(checkBox->isChecked()) {
            brands.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Brand: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_suitedForListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_suitedForListWidget->itemWidget(m_suitedForListWidget->item(i)));
        if(checkBox->isChecked()) {
            suitedFors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Suited for: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_shellTypeListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_shellTypeListWidget->itemWidget(m_shellTypeListWidget->item(i)));
        if(checkBox->isChecked()) {
            shellTypes.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Shell type: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_shellMaterialListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_shellMaterialListWidget->itemWidget(m_shellMaterialListWidget->item(i)));
        if(checkBox->isChecked()) {
            shellMaterials.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Shell material: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_coverMaterialListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_coverMaterialListWidget->itemWidget(m_coverMaterialListWidget->item(i)));
        if(checkBox->isChecked()) {
            coverMaterials.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Cover material: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_colorListWidget->count(); i++) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_colorListWidget->itemWidget(m_colorListWidget->item(i)));
        if(checkBox->isChecked()) {
            colors.push_back(checkBox->text());
            std::cout << "[CatalogueSearchSportSeatV::setupConnections] Color: " << checkBox->text().toStdString() << std::endl;
        }
    }

    emit filterClicked(brands, suitedFors, shellTypes, shellMaterials, coverMaterials, colors);
}

void CatalogueSearchSportSeatV::onClearButtonClicked() {
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

    for(int i = 0; i < m_shellTypeListWidget->count(); i++) {
        QListWidgetItem *item = m_shellTypeListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_shellTypeListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_shellMaterialListWidget->count(); i++) {
        QListWidgetItem *item = m_shellMaterialListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_shellMaterialListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_coverMaterialListWidget->count(); i++) {
        QListWidgetItem *item = m_coverMaterialListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_coverMaterialListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_colorListWidget->count(); i++) {
        QListWidgetItem *item = m_colorListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_colorListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    emit clearClicked();
}

void CatalogueSearchSportSeatV::setupConnections() {
    std::cout << "[CatalogueSearchSportSeatV::setupConnections] Setting up connections" << std::endl;
    connect(m_filterButton, &QPushButton::clicked, this, &CatalogueSearchSportSeatV::onFilterButtonClicked);
    connect(m_clearButton, &QPushButton::clicked, this, &CatalogueSearchSportSeatV::onClearButtonClicked);
}

void CatalogueSearchSportSeatV::setupUI() {
    std::cout << "[CatalogueSearchSportSeatV::setupUI] Setting up UI" << std::endl;
    m_brandListWidget = new QListWidget();
    m_suitedForListWidget = new QListWidget();
    m_shellTypeListWidget = new QListWidget();
    m_shellMaterialListWidget = new QListWidget();
    m_coverMaterialListWidget = new QListWidget();
    m_colorListWidget = new QListWidget();

    m_brandListWidget->setFixedWidth(200);
    m_suitedForListWidget->setFixedWidth(200);
    m_shellTypeListWidget->setFixedWidth(200);
    m_shellMaterialListWidget->setFixedWidth(200);
    m_coverMaterialListWidget->setFixedWidth(200);
    m_colorListWidget->setFixedWidth(200);

    m_brandListWidget->setMinimumHeight(50);
    m_suitedForListWidget->setMinimumHeight(50);
    m_shellTypeListWidget->setMinimumHeight(50);
    m_shellMaterialListWidget->setMinimumHeight(50);
    m_coverMaterialListWidget->setMinimumHeight(50);
    m_colorListWidget->setMinimumHeight(50);

    m_brandLabel = new QLabel("Brand");
    m_suitedForLabel = new QLabel("Suited for");
    m_shellTypeLabel = new QLabel("Shell type");
    m_shellMaterialLabel = new QLabel("Shell material");
    m_coverMaterialLabel = new QLabel("Cover material");
    m_colorLabel = new QLabel("Color");

    QFont font = m_brandLabel->font();
    font.setBold(true);
    font.setPointSize(12);

    m_brandLabel->setFont(font);
    m_suitedForLabel->setFont(font);
    m_shellTypeLabel->setFont(font);
    m_shellMaterialLabel->setFont(font);
    m_coverMaterialLabel->setFont(font);
    m_colorLabel->setFont(font);

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
    m_layout->addWidget(m_shellTypeLabel);
    m_layout->addWidget(m_shellTypeListWidget);
    m_layout->addWidget(m_shellMaterialLabel);
    m_layout->addWidget(m_shellMaterialListWidget);
    m_layout->addWidget(m_coverMaterialLabel);
    m_layout->addWidget(m_coverMaterialListWidget);
    m_layout->addWidget(m_colorLabel);
    m_layout->addWidget(m_colorListWidget);
    m_layout->addWidget(m_filterButton);
    m_layout->addWidget(m_clearButton);

    setLayout(m_layout);
}