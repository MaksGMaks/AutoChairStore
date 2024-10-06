#include "AccountView.hpp"

AccountView::AccountView(IViewModel *viewModel, QWidget *parent) 
    : IView(viewModel, parent), m_accountVM(viewModel) {
    std::cout << "[AccountView::AccountView] constructor" << std::endl;
    setupUI();
}

void AccountView::setupUI() {
    std::cout << "[AccountView::setupUI] Setting up UI" << std::endl;
    m_surnameLabel = new QLabel("Surname: ", this);
    m_nameLabel = new QLabel("Name: ", this);
    m_emailLabel = new QLabel("Email: ", this);
    m_passwordLabel = new QLabel("Password: ", this);
    
    m_editButton = new QPushButton("Edit", this);
    m_saveButton = new QPushButton("Save", this);

    m_surnameEdit = new QLineEdit(this);
    m_nameEdit = new QLineEdit(this);
    m_emailEdit = new QLineEdit(this);
    m_passwordEdit = new QLineEdit(this);

    m_surnameLabel->setGeometry(10, 10, 100, 30);
    m_nameLabel->setGeometry(10, 10, 100, 30);
    m_emailLabel->setGeometry(10, 50, 100, 30);
    m_passwordLabel->setGeometry(10, 90, 100, 30);
    m_editButton->setGeometry(10, 130, 100, 30);
    m_saveButton->setGeometry(10, 170, 100, 30);

    m_surnameEdit->setGeometry(120, 10, 200, 30);
    m_nameEdit->setGeometry(120, 10, 200, 30);
    m_emailEdit->setGeometry(120, 50, 200, 30);
    m_passwordEdit->setGeometry(120, 90, 200, 30);

    connect(m_editButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Edit button clicked" << std::endl;
        m_surnameEdit->setReadOnly(false);
        m_nameEdit->setReadOnly(false);
        m_emailEdit->setReadOnly(false);
        
    });

    connect(m_saveButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Save button clicked" << std::endl;

    });
    
    m_hLSpacer = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_hRSpacer = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_vUSpacer = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    m_vDSpacer = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

    m_profileLayout = new QVBoxLayout();
    m_profileLayout->addItem(m_vUSpacer);
    m_profileLayout->addWidget(m_surnameLabel);
    m_profileLayout->addWidget(m_surnameEdit);
    m_profileLayout->addWidget(m_nameLabel);
    m_profileLayout->addWidget(m_nameEdit);
    m_profileLayout->addWidget(m_emailLabel);
    m_profileLayout->addWidget(m_emailEdit);
    m_profileLayout->addWidget(m_passwordLabel);
    m_profileLayout->addWidget(m_passwordEdit);
    m_profileLayout->addWidget(m_editButton);
    m_profileLayout->addWidget(m_saveButton);
    m_profileLayout->addItem(m_vDSpacer);

    m_profileWidgetLayout = new QHBoxLayout();
    m_profileWidgetLayout->addItem(m_hLSpacer);
    m_profileWidgetLayout->addLayout(m_profileLayout);
    m_profileWidgetLayout->addItem(m_hRSpacer);

    m_profileWidget = new QWidget(this);
    m_profileWidget->setLayout(m_profileWidgetLayout);

    m_ordersTable = new QTableWidget(this);
    m_ordersTable->setColumnCount(3);
    m_ordersTable->setHorizontalHeaderLabels({"Order ID", "Date", "Total"});
    m_ordersTable->setGeometry(10, 10, 500, 300);

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addWidget(m_profileWidget);
    m_mainLayout->addWidget(m_ordersTable);

    setLayout(m_mainLayout);
}