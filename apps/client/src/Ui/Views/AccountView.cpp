#include "AccountView.hpp"

AccountView::AccountView(QSharedPointer<IViewModel> viewModel, QWidget *parent) 
    : IView(*viewModel, parent), m_accountVM(std::move(viewModel)) {
    std::cout << "[AccountView::AccountView] constructor" << std::endl;
    setupUI();
}

void AccountView::setupUI() {
    std::cout << "[AccountView::setupUI] Setting up UI" << std::endl;
    m_surnameLabel = QSharedPointer<QLabel>::create("Surname: ", this);
    m_nameLabel = QSharedPointer<QLabel>::create("Name: ", this);
    m_emailLabel = QSharedPointer<QLabel>::create("Email: ", this);
    m_passwordLabel = QSharedPointer<QLabel>::create("Password: ", this);
    
    m_editButton = QSharedPointer<QPushButton>::create("Edit", this);
    m_saveButton = QSharedPointer<QPushButton>::create("Save", this);

    m_surnameEdit = QSharedPointer<QLineEdit>::create(this);
    m_nameEdit = QSharedPointer<QLineEdit>::create(this);
    m_emailEdit = QSharedPointer<QLineEdit>::create(this);
    m_passwordEdit = QSharedPointer<QLineEdit>::create(this);

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
    
    m_hLSpacer = QSharedPointer<QSpacerItem>::create(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_hRSpacer = QSharedPointer<QSpacerItem>::create(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);
    m_vUSpacer = QSharedPointer<QSpacerItem>::create(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    m_vDSpacer = QSharedPointer<QSpacerItem>::create(30, 30, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

    m_profileLayout = QSharedPointer<QVBoxLayout>::create();
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

    m_profileWidgetLayout = QSharedPointer<QHBoxLayout>::create();
    m_profileWidgetLayout->addItem(m_hLSpacer.get());
    m_profileWidgetLayout->addLayout(m_profileLayout.get());
    m_profileWidgetLayout->addItem(m_hRSpacer.get());

    m_profileWidget = QSharedPointer<QWidget>::create(this);
    m_profileWidget->setLayout(m_profileWidgetLayout.get());

    m_ordersTable = QSharedPointer<QTableWidget>::create(this);
    m_ordersTable->setColumnCount(3);
    m_ordersTable->setHorizontalHeaderLabels({"Order ID", "Date", "Total"});
    m_ordersTable->setGeometry(10, 10, 500, 300);

    m_mainLayout = QSharedPointer<QHBoxLayout>::create();
    m_mainLayout->addWidget(m_profileWidget.get());
    m_mainLayout->addWidget(m_ordersTable.get());

    setLayout(m_mainLayout.get());
}