#include "BaseSeatPage.hpp"

BaseSeatPage::BaseSeatPage(QTabWidget *parent)
: QTabWidget(parent) {
    setupUI();
}

void BaseSeatPage::loadSeat(const displayData::BaseSeat &seat) {
    m_descriptionEdit->setText(seat.description);
    m_brandEdit->setText(seat.brand);
    m_suitedForEdit->setText(seat.suitableFor);
    m_colorEdit->setText(seat.color);
    m_materialEdit->setText(seat.material);
    m_typeEdit->setText(seat.type);
}

void BaseSeatPage::setupUI() {
    // Description
    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setReadOnly(true);

    // Labels
    m_brandLabel = new QLabel("Brand: ");
    m_suitedForLabel = new QLabel("Suited for: ");
    m_colorLabel = new QLabel("Color: ");
    m_materialLabel = new QLabel("Material: ");
    m_typeLabel = new QLabel("Type: ");

    // Lines
    m_brandEdit = new QLineEdit();
    m_brandEdit->setReadOnly(true);
    m_suitedForEdit = new QLineEdit();
    m_suitedForEdit->setReadOnly(true);
    m_colorEdit = new QLineEdit();
    m_colorEdit->setReadOnly(true);
    m_materialEdit = new QLineEdit();
    m_materialEdit->setReadOnly(true);
    m_typeEdit = new QLineEdit();
    m_typeEdit->setReadOnly(true);

    // Size
    m_brandLabel->setFixedSize(300, 40);
    m_suitedForLabel->setFixedSize(300, 40);
    m_colorLabel->setFixedSize(300, 40);
    m_materialLabel->setFixedSize(300, 40);
    m_typeLabel->setFixedSize(300, 40);

    m_brandEdit->setFixedSize(300, 40);
    m_suitedForEdit->setFixedSize(300, 40);
    m_colorEdit->setFixedSize(300, 40);
    m_materialEdit->setFixedSize(300, 40);
    m_typeEdit->setFixedSize(300, 40);
    
    // Layouts
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

    m_typeLayout = new QHBoxLayout();
    m_typeLayout->addWidget(m_typeLabel);
    m_typeLayout->addWidget(m_typeEdit);

    m_parametersLayout = new QVBoxLayout();
    m_parametersLayout->addWidget(m_descriptionEdit);
    m_parametersLayout->addLayout(m_brandLayout);
    m_parametersLayout->addLayout(m_suitedForLayout);
    m_parametersLayout->addLayout(m_colorLayout);
    m_parametersLayout->addLayout(m_materialLayout);
    m_parametersLayout->addLayout(m_typeLayout);

    QWidget *parametersWidget = new QWidget();
    parametersWidget->setLayout(m_parametersLayout);

    addTab(m_descriptionEdit, "Description");
    addTab(parametersWidget, "Parameters");
}