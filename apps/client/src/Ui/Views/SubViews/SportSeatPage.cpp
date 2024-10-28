#include "SportSeatPage.hpp"

SportSeatPage::SportSeatPage(QTabWidget *parent) : QTabWidget(parent) {
    setupUI();
}

void SportSeatPage::loadSeat(const displayData::SportSeat &seat) {
    m_descriptionEdit->setText(seat.description);
    m_brandEdit->setText(seat.brand);
    m_suitedForEdit->setText(seat.suitableFor);
    m_shellTypeEdit->setText(seat.shellType);
    m_shellMaterialEdit->setText(seat.shellMaterial);
    m_coverMaterialEdit->setText(seat.coverMaterial);
    m_colorEdit->setText(seat.color);
}

void SportSeatPage::setupUI() {
    // Description
    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setReadOnly(true);

    // Parameters
    m_brandLabel = new QLabel("Brand", this);
    m_suitedForLabel = new QLabel("Suited For", this);
    m_shellTypeLabel = new QLabel("Shell Type", this);
    m_shellMaterialLabel = new QLabel("Shell Material", this);
    m_coverMaterialLabel = new QLabel("Cover Material", this);
    m_colorLabel = new QLabel("Color", this);

    // Lines
    m_brandEdit = new QLineEdit(this);
    m_brandEdit->setReadOnly(true);
    m_suitedForEdit = new QLineEdit(this);
    m_suitedForEdit->setReadOnly(true);
    m_shellTypeEdit = new QLineEdit(this);
    m_shellTypeEdit->setReadOnly(true);
    m_shellMaterialEdit = new QLineEdit(this);
    m_shellMaterialEdit->setReadOnly(true);
    m_coverMaterialEdit = new QLineEdit(this);
    m_coverMaterialEdit->setReadOnly(true);
    m_colorEdit = new QLineEdit(this);

    // Size
    m_brandLabel->setFixedSize(300, 40);
    m_suitedForLabel->setFixedSize(300, 40);
    m_shellTypeLabel->setFixedSize(300, 40);
    m_shellMaterialLabel->setFixedSize(300, 40);
    m_coverMaterialLabel->setFixedSize(300, 40);
    m_colorLabel->setFixedSize(300, 40);

    m_brandEdit->setFixedSize(300, 40);
    m_suitedForEdit->setFixedSize(300, 40);
    m_shellTypeEdit->setFixedSize(300, 40);
    m_shellMaterialEdit->setFixedSize(300, 40);
    m_coverMaterialEdit->setFixedSize(300, 40);
    m_colorEdit->setFixedSize(300, 40);

    // Layout
    m_brandLayout = new QHBoxLayout();
    m_brandLayout->addWidget(m_brandLabel);
    m_brandLayout->addWidget(m_brandEdit);

    m_suitedForLayout = new QHBoxLayout();
    m_suitedForLayout->addWidget(m_suitedForLabel);
    m_suitedForLayout->addWidget(m_suitedForEdit);

    m_shellTypeLayout = new QHBoxLayout();
    m_shellTypeLayout->addWidget(m_shellTypeLabel);
    m_shellTypeLayout->addWidget(m_shellTypeEdit);

    m_shellMaterialLayout = new QHBoxLayout();
    m_shellMaterialLayout->addWidget(m_shellMaterialLabel);
    m_shellMaterialLayout->addWidget(m_shellMaterialEdit);

    m_coverMaterialLayout = new QHBoxLayout();
    m_coverMaterialLayout->addWidget(m_coverMaterialLabel);
    m_coverMaterialLayout->addWidget(m_coverMaterialEdit);

    m_colorLayout = new QHBoxLayout();
    m_colorLayout->addWidget(m_colorLabel);
    m_colorLayout->addWidget(m_colorEdit);

    m_parametersLayout = new QVBoxLayout();
    m_parametersLayout->addWidget(m_descriptionEdit);
    m_parametersLayout->addLayout(m_brandLayout);
    m_parametersLayout->addLayout(m_suitedForLayout);
    m_parametersLayout->addLayout(m_shellTypeLayout);
    m_parametersLayout->addLayout(m_shellMaterialLayout);
    m_parametersLayout->addLayout(m_coverMaterialLayout);
    m_parametersLayout->addLayout(m_colorLayout);

    setLayout(m_parametersLayout);

    QWidget *parametersWidget = new QWidget();
    parametersWidget->setLayout(m_parametersLayout);

    addTab(m_descriptionEdit, "Description");
    addTab(parametersWidget, "Parameters");
}