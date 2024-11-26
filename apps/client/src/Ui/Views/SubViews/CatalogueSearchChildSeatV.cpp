#include "CatalogueSearchChildSeatV.hpp"

CatalogueSearchChildSeatV::CatalogueSearchChildSeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void CatalogueSearchChildSeatV::addFilters(const QVector<displayData::ChildSeat> &products) {
    std::cout << "[CatalogueSearchChildSeatV::addFilters] Adding filters" << std::endl;
    m_brandListWidget->clear();
    m_ageListWidget->clear();
    m_weightListWidget->clear();
    m_heightListWidget->clear();
    m_safetyKeyListWidget->clear();
    m_fasteningListWidget->clear();
    m_drivewayListWidget->clear();

    QVector<QString> brands;
    QVector<QString> ages;
    QVector<QString> weights;
    QVector<QString> heights;
    QVector<QString> safetyKeys;
    QVector<QString> fastenings;
    QVector<QString> driveways;
    
    for(auto product : products) {
        if(!brands.contains(product.brand)) {
            brands.push_back(product.brand);
            QCheckBox *checkBox = new QCheckBox(product.brand);
            QListWidgetItem *item = new QListWidgetItem(m_brandListWidget);
            m_brandListWidget->setItemWidget(item, checkBox);
        }
        if(!ages.contains(product.age)) {
            ages.push_back(product.age);
            QCheckBox *checkBox = new QCheckBox(product.age);
            QListWidgetItem *item = new QListWidgetItem(m_ageListWidget);
            m_ageListWidget->setItemWidget(item, checkBox);
        }
        if(!weights.contains(product.weight)) {
            weights.push_back(product.weight);
            QCheckBox *checkBox = new QCheckBox(product.weight);
            QListWidgetItem *item = new QListWidgetItem(m_weightListWidget);
            m_weightListWidget->setItemWidget(item, checkBox);
        }
        if(!heights.contains(product.height)) {
            heights.push_back(product.height);
            QCheckBox *checkBox = new QCheckBox(product.height);
            QListWidgetItem *item = new QListWidgetItem(m_heightListWidget);
            m_heightListWidget->setItemWidget(item, checkBox);
        }
        if(!safetyKeys.contains(product.safetyKey)) {
            safetyKeys.push_back(product.safetyKey);
            QCheckBox *checkBox = new QCheckBox(product.safetyKey);
            QListWidgetItem *item = new QListWidgetItem(m_safetyKeyListWidget);
            m_safetyKeyListWidget->setItemWidget(item, checkBox);
        }
        if(!fastenings.contains(product.fastening)) {
            fastenings.push_back(product.fastening);
            QCheckBox *checkBox = new QCheckBox(product.fastening);
            QListWidgetItem *item = new QListWidgetItem(m_fasteningListWidget);
            m_fasteningListWidget->setItemWidget(item, checkBox);
        }
        if(!driveways.contains(product.driveway)) {
            driveways.push_back(product.driveway);
            QCheckBox *checkBox = new QCheckBox(product.driveway);
            QListWidgetItem *item = new QListWidgetItem(m_drivewayListWidget);
            m_drivewayListWidget->setItemWidget(item, checkBox);
        }
    }
}

void CatalogueSearchChildSeatV::onFilterButtonClicked() {
    QVector<QString> brands{};
    QVector<QString> ages{};
    QVector<QString> weights{};
    QVector<QString> heights{};
    QVector<QString> safetyKeys{};
    QVector<QString> fastenings{};
    QVector<QString> driveways{};

    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QListWidgetItem *item = m_brandListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            brands.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Brand: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_ageListWidget->count(); i++) {
        QListWidgetItem *item = m_ageListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_ageListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            ages.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Age: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_weightListWidget->count(); i++) {
        QListWidgetItem *item = m_weightListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_weightListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            weights.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Weight: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_heightListWidget->count(); i++) {
        QListWidgetItem *item = m_heightListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_heightListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            heights.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Height: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_safetyKeyListWidget->count(); i++) {
        QListWidgetItem *item = m_safetyKeyListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_safetyKeyListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            safetyKeys.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Safety key: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_fasteningListWidget->count(); i++) {
        QListWidgetItem *item = m_fasteningListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_fasteningListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            fastenings.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Fastening: " << checkBox->text().toStdString() << std::endl;
        }
    }

    for(int i = 0; i < m_drivewayListWidget->count(); i++) {
        QListWidgetItem *item = m_drivewayListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_drivewayListWidget->itemWidget(item));
        if(checkBox->isChecked()) {
            driveways.push_back(checkBox->text());
            std::cout << "[CatalogueSearchChildSeatV::setupConnections] Driveway: " << checkBox->text().toStdString() << std::endl;
        }
    }

    emit filterClicked(brands, ages, weights, heights, safetyKeys, fastenings, driveways);
}

void CatalogueSearchChildSeatV::onClearButtonClicked() {
    for(int i = 0; i < m_brandListWidget->count(); i++) {
        QListWidgetItem *item = m_brandListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_brandListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_ageListWidget->count(); i++) {
        QListWidgetItem *item = m_ageListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_ageListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_weightListWidget->count(); i++) {
        QListWidgetItem *item = m_weightListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_weightListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_heightListWidget->count(); i++) {
        QListWidgetItem *item = m_heightListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_heightListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_safetyKeyListWidget->count(); i++) {
        QListWidgetItem *item = m_safetyKeyListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_safetyKeyListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_fasteningListWidget->count(); i++) {
        QListWidgetItem *item = m_fasteningListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_fasteningListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    for(int i = 0; i < m_drivewayListWidget->count(); i++) {
        QListWidgetItem *item = m_drivewayListWidget->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(m_drivewayListWidget->itemWidget(item));
        checkBox->setChecked(false);
    }

    emit clearClicked();
}

void CatalogueSearchChildSeatV::setupConnections() {
    std::cout << "[CatalogueSearchChildSeatV::setupConnections] Setting up connections" << std::endl;
    connect(m_filterButton, &QPushButton::clicked, this, &CatalogueSearchChildSeatV::onFilterButtonClicked);
    connect(m_clearButton, &QPushButton::clicked, this, &CatalogueSearchChildSeatV::onClearButtonClicked);
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

    m_brandListWidget->setFixedWidth(200);
    m_ageListWidget->setFixedWidth(200);
    m_weightListWidget->setFixedWidth(200);
    m_heightListWidget->setFixedWidth(200);
    m_safetyKeyListWidget->setFixedWidth(200);
    m_fasteningListWidget->setFixedWidth(200);
    m_drivewayListWidget->setFixedWidth(200);

    m_brandListWidget->setMinimumHeight(50);
    m_ageListWidget->setMinimumHeight(50);
    m_weightListWidget->setMinimumHeight(50);
    m_heightListWidget->setMinimumHeight(50);
    m_safetyKeyListWidget->setMinimumHeight(50);
    m_fasteningListWidget->setMinimumHeight(50);
    m_drivewayListWidget->setMinimumHeight(50);

    m_brandLabel = new QLabel("Brand");
    m_ageLabel = new QLabel("Age");
    m_weightLabel = new QLabel("Weight");
    m_heightLabel = new QLabel("Height");
    m_safetyKeyLabel = new QLabel("Safety key");
    m_fasteningLabel = new QLabel("Fastening");
    m_drivewayLabel = new QLabel("Driveway");

    QFont font = m_brandLabel->font();
    font.setBold(true);
    font.setPointSize(12);

    m_brandLabel->setFont(font);
    m_ageLabel->setFont(font);
    m_weightLabel->setFont(font);
    m_heightLabel->setFont(font);
    m_safetyKeyLabel->setFont(font);
    m_fasteningLabel->setFont(font);
    m_drivewayLabel->setFont(font);

    m_filterButton = new QPushButton("Filter");
    m_clearButton = new QPushButton("Clear");

    m_filterButton->setFixedWidth(200);
    m_filterButton->setMinimumHeight(25);

    m_clearButton->setFixedWidth(200);
    m_clearButton->setMinimumHeight(25);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_brandLabel);
    m_layout->addWidget(m_brandListWidget);
    m_layout->addWidget(m_ageLabel);
    m_layout->addWidget(m_ageListWidget);
    m_layout->addWidget(m_weightLabel);
    m_layout->addWidget(m_weightListWidget);
    m_layout->addWidget(m_heightLabel);
    m_layout->addWidget(m_heightListWidget);
    m_layout->addWidget(m_safetyKeyLabel);
    m_layout->addWidget(m_safetyKeyListWidget);
    m_layout->addWidget(m_fasteningLabel);
    m_layout->addWidget(m_fasteningListWidget);
    m_layout->addWidget(m_drivewayLabel);
    m_layout->addWidget(m_drivewayListWidget);
    m_layout->addWidget(m_filterButton);
    m_layout->addWidget(m_clearButton);
    
    setLayout(m_layout);
}