#include "AccountView.hpp"

AccountView::AccountView(std::unique_ptr<IViewModel> viewModel, QWidget *parent) 
    : IView(*viewModel, parent), m_accountVM(std::move(viewModel)) {
    std::cout << "[AccountView::AccountView] constructor" << std::endl;
    setupUI();
}

void AccountView::setupUI() {
    std::cout << "[AccountView::setupUI] Setting up UI" << std::endl;
    m_surnameLabel = std::make_unique<QLabel>("Surname: ", this);
    m_nameLabel = std::make_unique<QLabel>("Name: ", this);
    m_emailLabel = std::make_unique<QLabel>("Email: ", this);
    m_passwordLabel = std::make_unique<QLabel>("Password: ", this);
    
    m_editButton = std::make_unique<QPushButton>("Edit", this);
    m_saveButton = std::make_unique<QPushButton>("Save", this);

    m_surnameEdit = std::make_unique<QLineEdit>(this);
    m_nameEdit = std::make_unique<QLineEdit>(this);
    m_emailEdit = std::make_unique<QLineEdit>(this);
    m_passwordEdit = std::make_unique<QLineEdit>(this);

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

    connect(m_editButton.get(), &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Edit button clicked" << std::endl;
        m_surnameEdit->setReadOnly(false);
        m_nameEdit->setReadOnly(false);
        m_emailEdit->setReadOnly(false);
        
    });

    connect(m_saveButton.get(), &QPushButton::clicked, this, [this]() {
        std::cout << "[AccountView::setupUI] Save button clicked" << std::endl;

    });
    
    m_hLSpacer = std::make_unique<QSpacerItem>(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_hRSpacer = std::make_unique<QSpacerItem>(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_vUSpacer = std::make_unique<QSpacerItem>(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    m_vDSpacer = std::make_unique<QSpacerItem>(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

    m_profileLayout = std::make_unique<QVBoxLayout>();
    m_profileLayout->addItem(m_vUSpacer.get());
    m_profileLayout->addWidget(m_surnameLabel.get());
    m_profileLayout->addWidget(m_surnameEdit.get());
    m_profileLayout->addWidget(m_nameLabel.get());
    m_profileLayout->addWidget(m_nameEdit.get());
    m_profileLayout->addWidget(m_emailLabel.get());
    m_profileLayout->addWidget(m_emailEdit.get());
    m_profileLayout->addWidget(m_passwordLabel.get());
    m_profileLayout->addWidget(m_passwordEdit.get());
    m_profileLayout->addWidget(m_editButton.get());
    m_profileLayout->addWidget(m_saveButton.get());
    m_profileLayout->addItem(m_vDSpacer.get());

    m_profileWidgetLayout = std::make_unique<QHBoxLayout>();
    m_profileWidgetLayout->addItem(m_hLSpacer.get());
    m_profileWidgetLayout->addLayout(m_profileLayout.get());
    m_profileWidgetLayout->addItem(m_hRSpacer.get());

    m_profileWidget = std::make_unique<QWidget>(this);
    m_profileWidget->setLayout(m_profileWidgetLayout.get());

    m_ordersTable = std::make_unique<QTableWidget>(this);
    m_ordersTable->setColumnCount(3);
    m_ordersTable->setHorizontalHeaderLabels({"Order ID", "Date", "Total"});
    m_ordersTable->setGeometry(10, 10, 500, 300);

    m_mainLayout = std::make_unique<QHBoxLayout>();
    m_mainLayout->addWidget(m_profileWidget.get());
    m_mainLayout->addWidget(m_ordersTable.get());

    setLayout(m_mainLayout.get());
}