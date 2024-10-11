#include "AccountView.hpp"

AccountView::AccountView(AccountViewModel *viewModel, QWidget *parent) 
    : IView(viewModel, parent), 
      m_accountVM(viewModel) {
    std::cout << "[AccountView::AccountView] constructor" << std::endl;
    setupUI();
    setupConnections();
}

void AccountView::setupConnections() {
    connect(m_editButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Edit button clicked" << std::endl;
        m_editButton->setFlat(!m_editButton->isFlat());
        if(m_editButton->isFlat()) {
            m_editButton->setText("Cancel");
            m_surnameEdit->setReadOnly(false);
            m_nameEdit->setReadOnly(false);
            m_saveButton->setEnabled(true);
        } else {
            m_editButton->setText("Edit");
            m_surnameEdit->setReadOnly(true);
            m_nameEdit->setReadOnly(true);
            m_saveButton->setEnabled(false);
        }
    });

    connect(m_saveButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Save button clicked" << std::endl;
        m_editButton->setFlat(false);
        m_editButton->setText("Edit");
        m_surnameEdit->setReadOnly(true);
        m_nameEdit->setReadOnly(true);
        m_saveButton->setEnabled(false);
    });

    connect(m_changeEmailButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Change email button clicked" << std::endl;
    });

    connect(m_changePasswordButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Change password button clicked" << std::endl;
    });

    connect(m_deleteAccountButton, &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Delete account button clicked" << std::endl;
    });
}

void AccountView::setupUI() {
    std::cout << "[AccountView::setupUI] Setting up UI" << std::endl;
    m_surnameLabel = new QLabel("Surname: ");
    m_nameLabel = new QLabel("Name: ");
    m_emailLabel = new QLabel("Email: ");
    // m_passwordLabel = new QLabel("Password: ");
    
    m_editButton = new QPushButton("Edit");
    m_saveButton = new QPushButton("Save");
    m_changeEmailButton = new QPushButton("Change email");
    m_changePasswordButton = new QPushButton("Change password");
    m_deleteAccountButton = new QPushButton("Delete account");

    m_surnameEdit = new QLineEdit(this);
    m_surnameEdit->setReadOnly(true);
    m_nameEdit = new QLineEdit(this);
    m_nameEdit->setReadOnly(true);
    m_emailEdit = new QLineEdit(this);
    m_emailEdit->setReadOnly(true);
    // m_passwordEdit = new QLineEdit(this);

    m_surnameLabel->setFixedSize(300, 40);
    m_nameLabel->setFixedSize(300, 40);
    m_emailLabel->setFixedSize(300, 40);
    // m_passwordLabel->setFixedSize(100, 30);

    m_editButton->setFixedSize(300, 50);
    m_saveButton->setFixedSize(300, 50);
    m_saveButton->setEnabled(false);
    m_changeEmailButton->setFixedSize(300, 50);
    m_changePasswordButton->setFixedSize(300, 50);
    m_deleteAccountButton->setFixedSize(300, 50);

    m_surnameEdit->setFixedSize(300, 40);
    m_nameEdit->setFixedSize(300, 40);
    m_emailEdit->setFixedSize(300, 40);
    // m_passwordEdit->setFixedSize(200, 30);
    
    m_hLSpacer = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_hRSpacer = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_vUSpacer = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    m_vMSpacer = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_vDSpacer = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

    m_hRTableSpacer = new QSpacerItem(60, 60, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_hLTableSpacer = new QSpacerItem(60, 60, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_vUTableSpacer = new QSpacerItem(60, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);
    m_vDTableSpacer = new QSpacerItem(60, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

    m_profileLayout = new QVBoxLayout();
    m_profileLayout->addItem(m_vUSpacer);
    m_profileLayout->addWidget(m_surnameLabel);
    m_profileLayout->addWidget(m_surnameEdit);
    m_profileLayout->addWidget(m_nameLabel);
    m_profileLayout->addWidget(m_nameEdit);
    m_profileLayout->addWidget(m_emailLabel);
    m_profileLayout->addWidget(m_emailEdit);
    // m_profileLayout->addWidget(m_passwordLabel);
    // m_profileLayout->addWidget(m_passwordEdit);
    m_profileLayout->addItem(m_vMSpacer);
    m_profileLayout->addWidget(m_editButton);
    m_profileLayout->addWidget(m_saveButton);
    m_profileLayout->addWidget(m_changeEmailButton);
    m_profileLayout->addWidget(m_changePasswordButton);
    m_profileLayout->addWidget(m_deleteAccountButton);
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

    m_ordersHLayout = new QHBoxLayout();
    m_ordersHLayout->addSpacerItem(m_hLTableSpacer);
    m_ordersHLayout->addWidget(m_ordersTable);
    m_ordersHLayout->addSpacerItem(m_hRTableSpacer);

    m_ordersVLayout = new QVBoxLayout();
    m_ordersVLayout->addItem(m_vUTableSpacer);
    m_ordersVLayout->addLayout(m_ordersHLayout);
    m_ordersVLayout->addItem(m_vDTableSpacer);

    m_ordersWidget = new QWidget(this);
    m_ordersWidget->setLayout(m_ordersVLayout);

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addWidget(m_profileWidget);
    m_mainLayout->addWidget(m_ordersWidget);

    setLayout(m_mainLayout);
}

