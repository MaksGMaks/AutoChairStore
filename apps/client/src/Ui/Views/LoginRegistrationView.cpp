#include "LoginRegistrationView.hpp"

LoginRegistrationView::LoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent) 
    : IView(viewModel, parent),
      m_loginRegistrationVM(viewModel) {
    std::cout << "[LoginRegistrationView::LoginRegistrationView] Constructor" << std::endl;
    setupUI();
    setupConnection();
}

void LoginRegistrationView::setupUI() {
    std::cout << "[LoginRegistrationView::setupUI] Setting up UI" << std::endl;

    m_lHSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_rHSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_vUSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_vDSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    setupLoginWidget();
    setupRegistrationWidget();
    
    m_stackedWidget = new QStackedWidget();
    m_stackedWidget->addWidget(m_loginWidget);
    m_stackedWidget->addWidget(m_registrationWidget);
    m_stackedWidget->setFixedSize(400, 400);

    m_pageLayout = new QHBoxLayout();
    m_pageLayout->addItem(m_lHSpacer);
    m_pageLayout->addWidget(m_stackedWidget);
    m_pageLayout->addItem(m_rHSpacer);

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addItem(m_vUSpacer);
    m_mainLayout->addLayout(m_pageLayout);
    m_mainLayout->addItem(m_vDSpacer);
    setLayout(m_mainLayout);
}

void LoginRegistrationView::setupConnection() {
    std::cout << "[LoginRegistrationView::setupConnection] Setting up connections" << std::endl;
    connect(m_loginButton, &QPushButton::clicked, this, &LoginRegistrationView::onLoginButtonClicked);
    connect(m_registrationLinkButton, &QPushButton::clicked, this, &LoginRegistrationView::onRegistrationLinkButtonClicked);
    connect(m_createAccountButton, &QPushButton::clicked, this, &LoginRegistrationView::onCreateAccountButtonClicked);
    connect(m_loginLinkButton, &QPushButton::clicked, this, &LoginRegistrationView::onLoginLinkButtonClicked);

    connect(m_unsavedDataLoginMessage, &MessageBox::approveButtonClicked, this, &LoginRegistrationView::approveRegistrationLinkButtonClicked);
    connect(m_unsavedDataRegistrationMessage, &MessageBox::approveButtonClicked, this, &LoginRegistrationView::approveLoginLinkButtonClicked);

    connect(m_loginRegistrationVM, &LoginRegistrationViewModel::loginSuccessfull, this, &LoginRegistrationView::onUserLogin);
    connect(m_loginRegistrationVM, &LoginRegistrationViewModel::loginFail, this, &LoginRegistrationView::onUserLoginFailed);
    connect(m_loginRegistrationVM, &LoginRegistrationViewModel::registrationSuccessfull, this, &LoginRegistrationView::onUserRegistered);
    connect(m_loginRegistrationVM, &LoginRegistrationViewModel::registrationFail, this, &LoginRegistrationView::onUserRegisterationFailed);

    connect(this, &LoginRegistrationView::loginUser, m_loginRegistrationVM, &LoginRegistrationViewModel::onLoginUser);
    connect(this, &LoginRegistrationView::registerUser, m_loginRegistrationVM, &LoginRegistrationViewModel::onRegisterUser);
}

void LoginRegistrationView::onLoginButtonClicked() {
    std::cout << "[LoginRegistrationView::onLoginButtonClicked] Login button clicked" << std::endl;
    displayData::Users user;
    if(m_emailLineEdit->text().isEmpty() || m_passwordLineEdit->text().isEmpty()) {
        std::cout << "[LoginRegistrationView::onLoginButtonClicked] Email or password is empty" << std::endl;
        m_emptyLoginError->showErrorMessage("Email or password is empty");
        return;
    }
    
    user.email = m_emailLineEdit->text();
    user.password = m_passwordLineEdit->text();
    emit loginUser(user);
}

void LoginRegistrationView::onRegistrationLinkButtonClicked() {
    std::cout << "[LoginRegistrationView::onRegistrationLinkButtonClicked] Registration link button clicked" << std::endl;
    if(m_emailLineEdit->text().isEmpty() && m_passwordLineEdit->text().isEmpty()) {
        m_stackedWidget->setCurrentWidget(m_registrationWidget);
        return;
    }
    m_unsavedDataLoginMessage->showMessageBox("Unsaved data", "Input data will be cleared", "Leave", "Stay", QMessageBox::Warning);
}

void LoginRegistrationView::approveRegistrationLinkButtonClicked() {
    std::cout << "[LoginRegistrationView::approveRegistrationLinkButtonClicked] Approve registration link button clicked" << std::endl;
    m_emailLineEdit->clear();
    m_passwordLineEdit->clear();
    m_stackedWidget->setCurrentWidget(m_registrationWidget);
}

void LoginRegistrationView::onCreateAccountButtonClicked() {
    std::cout << "[LoginRegistrationView::onCreateAccountButtonClicked] Create account button clicked" << std::endl;
    displayData::Users user;
    user.name = m_firstNameRegistrationLineEdit->text();
    user.surname = m_lastNameRegistrationLineEdit->text();
    user.email = m_emailRegistrationLineEdit->text();
    user.password = m_passwordRegistrationLineEdit->text();
    
    if(m_firstNameRegistrationLineEdit->text().isEmpty() || m_lastNameRegistrationLineEdit->text().isEmpty() || 
       m_emailRegistrationLineEdit->text().isEmpty() || m_passwordRegistrationLineEdit->text().isEmpty() || 
       m_confirmPasswordRegistrationLineEdit->text().isEmpty()) {
        std::cout << "[LoginRegistrationView::onCreateAccountButtonClicked] Input fields are empty" << std::endl;
        m_emptyRegistrationError->showErrorMessage("Input fields are empty");
        return;
    }

    if(m_passwordRegistrationLineEdit->text() != m_confirmPasswordRegistrationLineEdit->text()) {
        std::cout << "[LoginRegistrationView::onCreateAccountButtonClicked] Passwords do not match" << std::endl;
        m_differentPasswordsRegistrationError->showErrorMessage("Passwords do not match");
        return;
    }
    
    emit registerUser(user);
}

void LoginRegistrationView::onLoginLinkButtonClicked() {
    std::cout << "[LoginRegistrationView::onLoginLinkButtonClicked] Login link button clicked" << std::endl;
    if(m_firstNameRegistrationLineEdit->text().isEmpty() && m_lastNameRegistrationLineEdit->text().isEmpty() && 
       m_emailRegistrationLineEdit->text().isEmpty() && m_passwordRegistrationLineEdit->text().isEmpty() && 
       m_confirmPasswordRegistrationLineEdit->text().isEmpty()) {
        m_stackedWidget->setCurrentWidget(m_loginWidget);
        return;
    }

    m_unsavedDataRegistrationMessage->showMessageBox("Unsaved data", "Input data will be cleared", "Leave", "Stay", QMessageBox::Warning);
}

void LoginRegistrationView::approveLoginLinkButtonClicked() {
    std::cout << "[LoginRegistrationView::approveLoginLinkButtonClicked] Approve login link button clicked" << std::endl;
    m_firstNameRegistrationLineEdit->clear();
    m_lastNameRegistrationLineEdit->clear();
    m_emailRegistrationLineEdit->clear();
    m_passwordRegistrationLineEdit->clear();
    m_confirmPasswordRegistrationLineEdit->clear();
    m_stackedWidget->setCurrentWidget(m_loginWidget);
}

void LoginRegistrationView::setupLoginWidget() {
    std::cout << "[LoginRegistrationView::setupLoginWidget] Setting up login widget" << std::endl;
    m_loginWidget = new QWidget();

    m_emptyLoginError = new MessageBox(m_loginWidget);
    m_unsavedDataLoginMessage = new MessageBox(m_loginWidget);

    m_emailLineEdit = new QLineEdit();
    m_emailLineEdit->setPlaceholderText("Email");
    m_passwordLineEdit = new QLineEdit();
    m_passwordLineEdit->setPlaceholderText("Password");
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);

    m_loginButton = new QPushButton("Login");
    m_loginButton->setFixedSize(300, 50);
    m_registrationLinkButton = new QPushButton("Create account");
    m_registrationLinkButton->setFixedSize(150, 30);

    m_vLoginSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_vButtonLoginSpacer = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_hLCenterSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRCenterSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_loginButtonLayout = new QHBoxLayout();
    m_loginButtonLayout->addItem(m_hLCenterSpacer);
    m_loginButtonLayout->addWidget(m_loginButton);
    m_loginButtonLayout->addItem(m_hRCenterSpacer);

    m_registrationLinkLayout = new QHBoxLayout();
    m_registrationLinkLayout->addItem(m_hLCenterSpacer);
    m_registrationLinkLayout->addWidget(m_registrationLinkButton);
    m_registrationLinkLayout->addItem(m_hRCenterSpacer);

    m_loginLayout = new QVBoxLayout();
    m_loginLayout->addItem(m_vUSpacer);
    m_loginLayout->addWidget(m_emailLineEdit);
    m_loginLayout->addWidget(m_passwordLineEdit);
    m_loginLayout->addItem(m_vButtonLoginSpacer);
    m_loginLayout->addLayout(m_loginButtonLayout);
    m_loginLayout->addItem(m_vLoginSpacer);
    m_loginLayout->addLayout(m_registrationLinkLayout);
    m_loginLayout->addItem(m_vDSpacer);

    m_loginWidget->setLayout(m_loginLayout);
}

void LoginRegistrationView::setupRegistrationWidget() {
    std::cout << "[LoginRegistrationView::setupRegistrationWidget] Setting up registration widget" << std::endl;
    m_registrationWidget = new QWidget();

    m_emptyRegistrationError = new MessageBox(m_registrationWidget);
    m_differentPasswordsRegistrationError = new MessageBox(m_registrationWidget);
    m_unsavedDataRegistrationMessage = new MessageBox(m_registrationWidget);

    m_createAccountButton = new QPushButton("Create account");
    m_createAccountButton->setFixedSize(300, 50);
    m_loginLinkButton = new QPushButton("Login");
    m_loginLinkButton->setFixedSize(150, 30);

    m_vRegistrationSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_vLoginLinkSpacer = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_hLCenterRegistrationSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRCenterRegistrationSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_firstNameRegistrationLineEdit = new QLineEdit();
    m_firstNameRegistrationLineEdit->setPlaceholderText("First name");
    m_lastNameRegistrationLineEdit = new QLineEdit();
    m_lastNameRegistrationLineEdit->setPlaceholderText("Last name");
    m_emailRegistrationLineEdit = new QLineEdit();
    m_emailRegistrationLineEdit->setPlaceholderText("Email");
    m_passwordRegistrationLineEdit = new QLineEdit();
    m_passwordRegistrationLineEdit->setPlaceholderText("Password");
    m_passwordRegistrationLineEdit->setEchoMode(QLineEdit::Password);
    m_confirmPasswordRegistrationLineEdit = new QLineEdit();
    m_confirmPasswordRegistrationLineEdit->setPlaceholderText("Confirm password");
    m_confirmPasswordRegistrationLineEdit->setEchoMode(QLineEdit::Password);

    m_registrationButtonLayout = new QHBoxLayout();
    m_registrationButtonLayout->addItem(m_hLCenterRegistrationSpacer);
    m_registrationButtonLayout->addWidget(m_createAccountButton);
    m_registrationButtonLayout->addItem(m_hRCenterRegistrationSpacer);

    m_loginLinkLayout = new QHBoxLayout();
    m_loginLinkLayout->addItem(m_hLCenterRegistrationSpacer);
    m_loginLinkLayout->addWidget(m_loginLinkButton);
    m_loginLinkLayout->addItem(m_hRCenterRegistrationSpacer);

    m_registrationLayout = new QVBoxLayout();
    m_registrationLayout->addItem(m_vUSpacer);
    m_registrationLayout->addWidget(m_firstNameRegistrationLineEdit);
    m_registrationLayout->addWidget(m_lastNameRegistrationLineEdit);
    m_registrationLayout->addWidget(m_emailRegistrationLineEdit);
    m_registrationLayout->addWidget(m_passwordRegistrationLineEdit);
    m_registrationLayout->addWidget(m_confirmPasswordRegistrationLineEdit);
    m_registrationLayout->addItem(m_vButtonLoginSpacer);
    m_registrationLayout->addLayout(m_registrationButtonLayout);
    m_registrationLayout->addItem(m_vRegistrationSpacer);
    m_registrationLayout->addLayout(m_loginLinkLayout);
    m_registrationLayout->addItem(m_vDSpacer);

    m_registrationWidget->setLayout(m_registrationLayout);
}