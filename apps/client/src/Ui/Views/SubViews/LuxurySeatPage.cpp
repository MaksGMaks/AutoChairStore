#include "LuxurySeatPage.hpp"

LuxurySeatPage::LuxurySeatPage(QTabWidget *parent) : QTabWidget(parent) {
    setupUI();
}

void LuxurySeatPage::loadSeat(const displayData::LuxurySeat &seat) {
    m_descriptionEdit->setText(seat.description);
    m_brandEdit->setText(seat.brand);
    m_suitedForEdit->setText(seat.suitableFor);
    m_colorEdit->setText(seat.color);
    m_materialEdit->setText(seat.material);
    m_comfortLevelEdit->setText(seat.comfortLevel);
    m_customDesignEdit->setText(seat.customDesign);
}

void LuxurySeatPage::setupUI() {
    // Description
    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setReadOnly(true);

    // Parameters
    m_brandLabel = new QLabel("Brand", this);
    m_suitedForLabel = new QLabel("Suited For", this);
    m_colorLabel = new QLabel("Color", this);
    m_materialLabel = new QLabel("Material", this);
    m_comfortLevelLabel = new QLabel("Comfort Level", this);
    m_customDesignLabel = new QLabel("Custom Design", this);

    // Lines
    m_brandEdit = new QLineEdit(this);
    m_brandEdit->setReadOnly(true);
    m_suitedForEdit = new QLineEdit(this);
    m_suitedForEdit->setReadOnly(true);
    m_colorEdit = new QLineEdit(this);
    m_colorEdit->setReadOnly(true);
    m_materialEdit = new QLineEdit(this);
    m_materialEdit->setReadOnly(true);
    m_comfortLevelEdit = new QLineEdit(this);
    m_comfortLevelEdit->setReadOnly(true);
    m_customDesignEdit = new QLineEdit(this);
    m_customDesignEdit->setReadOnly(true);

    // Size
    m_brandLabel->setFixedSize(300, 40);
    m_suitedForLabel->setFixedSize(300, 40);
    m_colorLabel->setFixedSize(300, 40);
    m_materialLabel->setFixedSize(300, 40);
    m_comfortLevelLabel->setFixedSize(300, 40);
    m_customDesignLabel->setFixedSize(300, 40);

    m_brandEdit->setFixedSize(300, 40);
    m_suitedForEdit->setFixedSize(300, 40);
    m_colorEdit->setFixedSize(300, 40);
    m_materialEdit->setFixedSize(300, 40);
    m_comfortLevelEdit->setFixedSize(300, 40);
    m_customDesignEdit->setFixedSize(300, 40);

    // Layout
    m_brandLayout = new QHBoxLayout();
    m_brandLayout->addWidget(m_brandLabel);
    m_brandLayout->addWidget(m_brandEdit);

    m_suitedForLayout = new QHBoxLayout();
    m_suitedForLayout->addWidget(m_suitedForLabel);
    m_suitedForLayout->addWidget(m_suitedForEdit);

    m_colorLayout = new QHBoxLayout();
    m_colorLayout->addWidget(m_colorLabel);
    m_colorLayout->addWidget(m_colorEdit);

    m_materialLayout = new QHBoxLayout();
    m_materialLayout->addWidget(m_materialLabel);
    m_materialLayout->addWidget(m_materialEdit);

    m_comfortLevelLayout = new QHBoxLayout();
    m_comfortLevelLayout->addWidget(m_comfortLevelLabel);
    m_comfortLevelLayout->addWidget(m_comfortLevelEdit);

    m_customDesignLayout = new QHBoxLayout();
    m_customDesignLayout->addWidget(m_customDesignLabel);
    m_customDesignLayout->addWidget(m_customDesignEdit);

    m_parametersLayout = new QVBoxLayout();
    m_parametersLayout->addLayout(m_brandLayout);
    m_parametersLayout->addLayout(m_suitedForLayout);
    m_parametersLayout->addLayout(m_colorLayout);
    m_parametersLayout->addLayout(m_materialLayout);
    m_parametersLayout->addLayout(m_comfortLevelLayout);
    m_parametersLayout->addLayout(m_customDesignLayout);

    QWidget *parametersWidget = new QWidget(this);
    parametersWidget->setLayout(m_parametersLayout);

    addTab(m_descriptionEdit, "Description");
    addTab(parametersWidget, "Parameters");
}