#include "ChildSeatPage.hpp"

ChildSeatPage::ChildSeatPage(QTabWidget *parent) : QTabWidget(parent) {
    setupUI();
}

void ChildSeatPage::loadSeat(const displayData::ChildSeat &seat) {
    m_descriptionEdit->setText(seat.description);
    m_brandEdit->setText(seat.brand);
    m_ageEdit->setText(seat.age);
    m_weightEdit->setText(seat.weight);
    m_heightEdit->setText(seat.height);
    m_safetyStandardEdit->setText(seat.safetyKey);
    m_fasteningEdit->setText(seat.fastening);
    m_drivewayEdit->setText(seat.driveway);
}

void ChildSeatPage::setupUI() {
    // Description
    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setReadOnly(true);

    // Parameters
    m_brandLabel = new QLabel("Brand", this);
    m_ageLabel = new QLabel("Age", this);
    m_weightLabel = new QLabel("Weight", this);
    m_heightLabel = new QLabel("Height", this);
    m_safetyStandardLabel = new QLabel("Safety Standard", this);
    m_fasteningLabel = new QLabel("Fastening", this);
    m_drivewayLabel = new QLabel("Driveway", this);

    // Lines
    m_brandEdit = new QLineEdit(this);
    m_brandEdit->setReadOnly(true);
    m_ageEdit = new QLineEdit(this);
    m_ageEdit->setReadOnly(true);
    m_weightEdit = new QLineEdit(this);
    m_weightEdit->setReadOnly(true);
    m_heightEdit = new QLineEdit(this);
    m_heightEdit->setReadOnly(true);
    m_safetyStandardEdit = new QLineEdit(this);
    m_safetyStandardEdit->setReadOnly(true);
    m_fasteningEdit = new QLineEdit(this);
    m_fasteningEdit->setReadOnly(true);
    m_drivewayEdit = new QLineEdit(this);
    m_drivewayEdit->setReadOnly(true);

    // Size
    m_brandLabel->setFixedSize(300, 40);
    m_ageLabel->setFixedSize(300, 40);
    m_weightLabel->setFixedSize(300, 40);
    m_heightLabel->setFixedSize(300, 40);
    m_safetyStandardLabel->setFixedSize(300, 40);
    m_fasteningLabel->setFixedSize(300, 40);
    m_drivewayLabel->setFixedSize(300, 40);

    m_brandEdit->setFixedSize(300, 40);
    m_ageEdit->setFixedSize(300, 40);
    m_weightEdit->setFixedSize(300, 40);
    m_heightEdit->setFixedSize(300, 40);
    m_safetyStandardEdit->setFixedSize(300, 40);
    m_fasteningEdit->setFixedSize(300, 40);
    m_drivewayEdit->setFixedSize(300, 40);

    // Layout
    m_brandLayout = new QHBoxLayout();
    m_brandLayout->addWidget(m_brandLabel);
    m_brandLayout->addWidget(m_brandEdit);

    m_ageLayout = new QHBoxLayout();
    m_ageLayout->addWidget(m_ageLabel);
    m_ageLayout->addWidget(m_ageEdit);

    m_weightLayout = new QHBoxLayout();
    m_weightLayout->addWidget(m_weightLabel);
    m_weightLayout->addWidget(m_weightEdit);

    m_heightLayout = new QHBoxLayout();
    m_heightLayout->addWidget(m_heightLabel);
    m_heightLayout->addWidget(m_heightEdit);

    m_safetyStandardLayout = new QHBoxLayout();
    m_safetyStandardLayout->addWidget(m_safetyStandardLabel);
    m_safetyStandardLayout->addWidget(m_safetyStandardEdit);

    m_fasteningLayout = new QHBoxLayout();
    m_fasteningLayout->addWidget(m_fasteningLabel);
    m_fasteningLayout->addWidget(m_fasteningEdit);

    m_drivewayLayout = new QHBoxLayout();
    m_drivewayLayout->addWidget(m_drivewayLabel);
    m_drivewayLayout->addWidget(m_drivewayEdit);

    m_parametersLayout = new QVBoxLayout();
    m_parametersLayout->addWidget(m_descriptionEdit);
    m_parametersLayout->addLayout(m_brandLayout);
    m_parametersLayout->addLayout(m_ageLayout);
    m_parametersLayout->addLayout(m_weightLayout);
    m_parametersLayout->addLayout(m_heightLayout);
    m_parametersLayout->addLayout(m_safetyStandardLayout);
    m_parametersLayout->addLayout(m_fasteningLayout);
    m_parametersLayout->addLayout(m_drivewayLayout);

    QWidget *parametersWidget = new QWidget(this);
    parametersWidget->setLayout(m_parametersLayout);

    addTab(m_descriptionEdit, "Description");
    addTab(parametersWidget, "Parameters");
}