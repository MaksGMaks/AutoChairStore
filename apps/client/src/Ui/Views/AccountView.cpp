#include "AccountView.hpp"

AccountView::AccountView(AccountViewModel *viewModel, QWidget *parent) 
: IView(viewModel, parent), 
m_accountVM(viewModel) {
    std::cout << "[AccountView::AccountView] constructor" << std::endl;
    setupUI();
    setupConnections();
}

void AccountView::setupConnections() {
    connect(m_editButton, &QPushButton::clicked, this, &AccountView::onEditButtonClicked);
    connect(m_saveButton, &QPushButton::clicked, this, &AccountView::onSaveButtonClicked);

    connect(m_changeEmailButton, &QPushButton::clicked, this, &AccountView::onChangeEmailButtonClicked);
    connect(m_changeEmailSaveButton, &QPushButton::clicked, this, &AccountView::onSaveEmailButtonClicked);
    connect(m_sendEmailCodeButton, &QPushButton::clicked, this, &AccountView::onSendEmailCodeButtonClicked);
    connect(m_cancelEmailChangeButton, &QPushButton::clicked, this, &AccountView::onCancelEmailChangeButtonClicked);

    connect(m_changePasswordButton, &QPushButton::clicked, this, &AccountView::onChangePasswordButtonClicked);
    connect(m_changePasswordSaveButton, &QPushButton::clicked, this, &AccountView::onSavePasswordButtonClicked);
    connect(m_sendPasswordCodeButton, &QPushButton::clicked, this, &AccountView::onSendPasswordCodeButtonClicked);
    connect(m_cancelPasswordChangeButton, &QPushButton::clicked, this, &AccountView::onCancelPasswordChangeButtonClicked);

    connect(m_deleteAccountButton, &QPushButton::clicked, this, &AccountView::onDeleteAccountButtonClicked);
    connect(m_sendDeleteAccountCodeButton, &QPushButton::clicked, this, &AccountView::onSendDeleteAccountCodeButtonClicked);
    connect(m_deleteAccountConfirmButton, &QPushButton::clicked, this, &AccountView::onDeleteAccountConfirmButtonClicked);
    connect(m_deleteAccountDialog, &MessageBox::approveButtonClicked, this, &AccountView::onDeleteAccountConfirmed);

    // From View Model

    connect(m_accountVM, &AccountViewModel::fetchUser, this, &AccountView::onUserFetched);
    connect(m_accountVM, &AccountViewModel::emailCodeSentSuccessfully, this, &AccountView::onEmailCodeSent);
    connect(m_accountVM, &AccountViewModel::changeCodeSentSuccessfully, this, &AccountView::onChangeCodeSent);
    connect(m_accountVM, &AccountViewModel::passwordChangedSuccessfully, this, &AccountView::onPasswordChanged);
    connect(m_accountVM, &AccountViewModel::deleteAccountSuccessfully, this, &AccountView::onDeleteAccountSuccess);

    // To View Model
    connect(this, &AccountView::vmEditUser, m_accountVM, &AccountViewModel::onEditUser);
    connect(this, &AccountView::vmEmailChangeCode, m_accountVM, &AccountViewModel::onEmailChangeCode);
    connect(this, &AccountView::vmChangeCode, m_accountVM, &AccountViewModel::onChangeCode);
    connect(this, &AccountView::vmEmailChange, m_accountVM, &AccountViewModel::onEmailChange);
    connect(this, &AccountView::vmPasswordChange, m_accountVM, &AccountViewModel::onPasswordChange);
    connect(this, &AccountView::vmDeleteAccount, m_accountVM, &AccountViewModel::onDeleteAccount);
}

void AccountView::onEditButtonClicked() {
    std::cout << "[AccountView::onEditButtonClicked] Edit button clicked" << std::endl;
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
        onUserFetched();
    }
}

void AccountView::onSaveButtonClicked() {
    std::cout << "[AccountView::onSaveButtonClicked] Save button clicked" << std::endl;
    if(!m_surnameEdit->text().isEmpty() && !m_nameEdit->text().isEmpty()) {
        m_editButton->setFlat(false);
        m_editButton->setText("Edit");
        m_surnameEdit->setReadOnly(true);
        m_nameEdit->setReadOnly(true);
        m_saveButton->setEnabled(false);
        
        displayData::Users user;
        user.surname = m_surnameEdit->text();
        user.name = m_nameEdit->text();
        
        emit vmEditUser(user);
    } else {
        m_userEditErrorDialog->showErrorMessage("Please fill all fields");
    }
}

void AccountView::onChangeEmailButtonClicked() {
    std::cout << "[AccountView::onChangeEmailButtonClicked] Change email button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_changeEmailWidget);
}

void AccountView::onSaveEmailButtonClicked() {
    std::cout << "[AccountView::onSaveEmailButtonClicked] Save email button clicked" << std::endl;
    if(!m_newEmailEdit->text().isEmpty() && !m_confirmEmailEdit->text().isEmpty() && !m_emailCodeEdit->text().isEmpty()) {
        if(m_newEmailEdit->text() == m_confirmEmailEdit->text()) {
            emit vmEmailChange(m_emailEdit->text(), m_newEmailEdit->text(), m_emailCodeEdit->text());
        }
    } else {
        m_emailChangeErrorDialog->showErrorMessage("Please fill all fields");
    }
}

void AccountView::onSendEmailCodeButtonClicked() {
    std::cout << "[AccountView::onSendEmailCodeButtonClicked] Send email code button clicked" << std::endl;
    if(!m_newEmailEdit->text().isEmpty() && !m_confirmEmailEdit->text().isEmpty()) {
        if(m_newEmailEdit->text() == m_confirmEmailEdit->text()) {
            emit vmEmailChangeCode(m_newEmailEdit->text());
        } else {
            m_emailChangeErrorDialog->showErrorMessage("Emails do not match. Please enter the same email in both fields");
        }
    } else {
        m_emailChangeErrorDialog->showErrorMessage("Please enter email in both fields");
    }
}

void AccountView::onCancelEmailChangeButtonClicked() {
    std::cout << "[AccountView::onCancelEmailChangeButtonClicked] Cancel email change button clicked" << std::endl;
    if(m_newEmailEdit->text().isEmpty() && m_confirmEmailEdit->text().isEmpty() && m_emailCodeEdit->text().isEmpty()) {
        m_stackedWidget->setCurrentWidget(m_accountWidget);
        return;
    }

    m_emailChangeErrorDialog->showMessageBox("Unsaved changes", "Data will be cleared", "Continue", "Stay", QMessageBox::Question);
    connect(m_emailChangeErrorDialog, &MessageBox::approveButtonClicked, this, [this] {
        m_newEmailEdit->clear();
        m_confirmEmailEdit->clear();
        m_emailCodeEdit->clear();
        m_stackedWidget->setCurrentWidget(m_accountWidget);
    });
}

void AccountView::onChangePasswordButtonClicked() {
    std::cout << "[AccountView::onChangePasswordButtonClicked] Change password button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_changePasswordWidget);
}

void AccountView::onSavePasswordButtonClicked() {
    std::cout << "[AccountView::onSavePasswordButtonClicked] Save password button clicked" << std::endl;
    if(!m_oldPasswordEdit->text().isEmpty() && !m_newPasswordEdit->text().isEmpty() && !m_confirmPasswordEdit->text().isEmpty() && !m_passwordCodeEdit->text().isEmpty()) {
        if(m_newPasswordEdit->text() == m_confirmPasswordEdit->text()) {
            emit vmPasswordChange(m_emailEdit->text(), m_oldPasswordEdit->text(), m_newPasswordEdit->text(), m_passwordCodeEdit->text());
        } else {
            m_passwordChangeErrorDialog->showErrorMessage("Passwords do not match. Please enter the same password in both fields");
        }
    } else {
        m_passwordChangeErrorDialog->showErrorMessage("Please fill all fields");
    }
    m_stackedWidget->setCurrentWidget(m_accountWidget);
}

void AccountView::onSendPasswordCodeButtonClicked() {
    std::cout << "[AccountView::onSendPasswordCodeButtonClicked] Send password code button clicked" << std::endl;
    emit vmChangeCode(m_emailEdit->text());
}

void AccountView::onCancelPasswordChangeButtonClicked() {
    std::cout << "[AccountView::onCancelPasswordChangeButtonClicked] Cancel password change button clicked" << std::endl;
    if(m_oldPasswordEdit->text().isEmpty() && m_newPasswordEdit->text().isEmpty() && m_confirmPasswordEdit->text().isEmpty() && m_passwordCodeEdit->text().isEmpty()) {
        m_stackedWidget->setCurrentWidget(m_accountWidget);
        return;
    }

    m_passwordChangeErrorDialog->showMessageBox("Unsaved changes", "Data will be cleared", "Continue", "Stay", QMessageBox::Question);
    connect(m_passwordChangeErrorDialog, &MessageBox::approveButtonClicked, this, [this] {
        m_oldPasswordEdit->clear();
        m_newPasswordEdit->clear();
        m_confirmPasswordEdit->clear();
        m_passwordCodeEdit->clear();
        m_stackedWidget->setCurrentWidget(m_accountWidget);
    });

}

void AccountView::onDeleteAccountButtonClicked() {
    std::cout << "[AccountView::onDeleteAccountButtonClicked] Delete account button clicked" << std::endl;
    m_deleteAccountCodeDialog->exec();
}

void AccountView::onSendDeleteAccountCodeButtonClicked() {
    std::cout << "[AccountView::onSendDeleteAccountCodeButtonClicked] Send delete account code button clicked" << std::endl;
    emit vmChangeCode(m_emailEdit->text());
}

void AccountView::onDeleteAccountConfirmButtonClicked() {
    std::cout << "[AccountView::onDeleteAccountConfirmButtonClicked] Delete account confirm button clicked" << std::endl;
    m_deleteAccountCodeDialog->close();
    m_deleteAccountDialog->showMessageBox("Delete account", "Account will be deleted. Action is irreversible", "Delete account", "Cancel", QMessageBox::Warning);
}

void AccountView::onDeleteAccountConfirmed() {
    std::cout << "[AccountView::onDeleteAccountConfirmed] Delete account confirmed" << std::endl;
    emit vmDeleteAccount(m_emailEdit->text(), m_deleteAccountCodeEdit->text());
}

void AccountView::onUserFetched() {
    std::cout << "[AccountView::onUserFetched] User fetched" << std::endl;
    displayData::Users user = m_accountVM->user();
    m_surnameEdit->setText(user.surname);
    m_nameEdit->setText(user.name);
    m_emailEdit->setText(user.email);
}

void AccountView::onEmailCodeSent() {
    std::cout << "[AccountView::onEmailCodeSent] Email code sent" << std::endl;
    
}

void AccountView::onChangeCodeSent() {
    std::cout << "[AccountView::onPasswordCodeSent] Password code sent" << std::endl;
    
}

void AccountView::onPasswordChanged() {
    std::cout << "[AccountView::onPasswordChanged] Password changed" << std::endl;
    m_passwordChangeSuccessDialog->showMessageBox("Password changed", "You will be redirected to account page", "OK", "", QMessageBox::Information);
    connect(m_passwordChangeSuccessDialog, &MessageBox::approveButtonClicked, this, [this] {
        m_oldPasswordEdit->clear();
        m_newPasswordEdit->clear();
        m_confirmPasswordEdit->clear();
        m_passwordCodeEdit->clear();
        m_stackedWidget->setCurrentWidget(m_accountWidget);
    });
    connect(m_passwordChangeSuccessDialog, &MessageBox::rejectButtonClicked, this, [this] {
        m_oldPasswordEdit->clear();
        m_newPasswordEdit->clear();
        m_confirmPasswordEdit->clear();
        m_passwordCodeEdit->clear();
        m_stackedWidget->setCurrentWidget(m_accountWidget);
    });
}

void AccountView::onDeleteAccountSuccess() {
    std::cout << "[AccountView::onDeleteAccountSuccess] Account deleted" << std::endl;
    m_deleteAccountDialog->showMessageBox("Account deleted", "You will be redirected to login/registration page", "OK", "", QMessageBox::Information);
    m_deleteCodeEdit->clear();
    connect(m_deleteAccountDialog, &MessageBox::approveButtonClicked, this, [this] {
        emit accountDeleted();
    });
    connect(m_deleteAccountDialog, &MessageBox::rejectButtonClicked, this, [this] {
        emit accountDeleted();
    });
}

void AccountView::setupUI() {
    std::cout << "[AccountView::setupUI] Setting up UI" << std::endl;
    m_userEditErrorDialog = new MessageBox(this);

    m_surnameLabel = new QLabel("Surname: ");
    m_nameLabel = new QLabel("Name: ");
    m_emailLabel = new QLabel("Email: ");
    
    m_editButton = new QPushButton("Edit");
    m_saveButton = new QPushButton("Save");
    m_changeEmailButton = new QPushButton("Change email");
    m_changePasswordButton = new QPushButton("Change password");
    m_deleteAccountButton = new QPushButton("Delete account");

    m_surnameEdit = new QLineEdit();
    m_surnameEdit->setReadOnly(true);
    m_nameEdit = new QLineEdit();
    m_nameEdit->setReadOnly(true);
    m_emailEdit = new QLineEdit();
    m_emailEdit->setReadOnly(true);

    m_surnameLabel->setFixedSize(300, 40);
    m_nameLabel->setFixedSize(300, 40);
    m_emailLabel->setFixedSize(300, 40);

    m_editButton->setFixedSize(300, 50);
    m_saveButton->setFixedSize(300, 50);
    m_saveButton->setEnabled(false);
    m_changeEmailButton->setFixedSize(300, 50);
    m_changePasswordButton->setFixedSize(300, 50);
    m_deleteAccountButton->setFixedSize(300, 50);

    m_surnameEdit->setFixedSize(300, 40);
    m_nameEdit->setFixedSize(300, 40);
    m_emailEdit->setFixedSize(300, 40);
    
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

    m_profileWidget = new QWidget();
    m_profileWidget->setLayout(m_profileWidgetLayout);

    m_ordersTable = new QTableWidget();
    m_ordersTable->setColumnCount(4);
    m_ordersTable->setHorizontalHeaderLabels({"Package ID", "Date", "Payment Status", "Destination"});
    m_ordersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_ordersTable->setColumnWidth(0, 200);
    m_ordersTable->setColumnWidth(1, 150);
    m_ordersTable->setColumnWidth(2, 150);
    m_ordersTable->setColumnWidth(3, 250);
    for(int i = 0; i < m_ordersTable->columnCount(); i++) {
        m_ordersTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
    }
    m_ordersTable->setMinimumSize(500, 300);

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

    m_accountLayout = new QHBoxLayout();
    m_accountLayout->addWidget(m_profileWidget);
    m_accountLayout->addWidget(m_ordersWidget);

    m_accountWidget = new QWidget();
    m_accountWidget->setLayout(m_accountLayout);

    setupEmailChangeWidget();
    setupPasswordChangeWidget();
    setupDeleteAccountDialogs();

    m_stackedWidget = new QStackedWidget();
    m_stackedWidget->addWidget(m_accountWidget);
    m_stackedWidget->addWidget(m_changeEmailWidget);
    m_stackedWidget->addWidget(m_changePasswordWidget);

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addWidget(m_stackedWidget);
    setLayout(m_mainLayout);
}

        //  Change email widget

void AccountView::setupEmailChangeWidget() {
    m_emailChangeErrorDialog = new MessageBox(this);

    m_changeEmailWidget = new QWidget();
    m_newEmailEdit = new QLineEdit();
    m_newEmailEdit->setPlaceholderText("New email");
    m_confirmEmailEdit = new QLineEdit();
    m_confirmEmailEdit->setPlaceholderText("Confirm email");
    m_emailCodeEdit = new QLineEdit();
    m_emailCodeEdit->setPlaceholderText("Code 8 digits");
    m_emailCodeEdit->setMaxLength(8);

    m_changeEmailSaveButton = new QPushButton("Save");
    m_changeEmailSaveButton->setFixedHeight(50);
    m_sendEmailCodeButton = new QPushButton("Send code");
    m_sendEmailCodeButton->setFixedHeight(50);
    m_cancelEmailChangeButton = new QPushButton("Cancel");
    m_cancelEmailChangeButton->setFixedSize(100, 30);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(m_cancelEmailChangeButton, 1, Qt::AlignCenter);
    
    m_vUChangeEmailSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_vDChangeEmailSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_hLChangeEmailSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRChangeEmailSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_changePasswordVLayout = new QVBoxLayout();
    m_changePasswordVLayout->addItem(m_vUChangeEmailSpacer);
    m_changePasswordVLayout->addWidget(m_newEmailEdit);
    m_changePasswordVLayout->addWidget(m_confirmEmailEdit);
    m_changePasswordVLayout->addWidget(m_emailCodeEdit);
    m_changePasswordVLayout->addWidget(m_changeEmailSaveButton);
    m_changePasswordVLayout->addWidget(m_sendEmailCodeButton);
    m_changePasswordVLayout->addLayout(hLayout);
    m_changePasswordVLayout->addItem(m_vDChangeEmailSpacer);

    m_changePasswordHLayout = new QHBoxLayout();
    m_changePasswordHLayout->addItem(m_hLChangeEmailSpacer);
    m_changePasswordHLayout->addLayout(m_changePasswordVLayout);
    m_changePasswordHLayout->addItem(m_hRChangeEmailSpacer);

    m_changeEmailWidget->setLayout(m_changePasswordHLayout);
}

        // Change password widget

void AccountView::setupPasswordChangeWidget() {
    m_passwordChangeErrorDialog = new MessageBox(this);
    m_passwordChangeSuccessDialog = new MessageBox(this);

    m_changePasswordWidget = new QWidget();
    m_oldPasswordEdit = new QLineEdit();
    m_oldPasswordEdit->setPlaceholderText("Old password");
    m_oldPasswordEdit->setEchoMode(QLineEdit::Password);
    m_newPasswordEdit = new QLineEdit();
    m_newPasswordEdit->setPlaceholderText("New password");
    m_newPasswordEdit->setEchoMode(QLineEdit::Password);
    m_confirmPasswordEdit = new QLineEdit();
    m_confirmPasswordEdit->setPlaceholderText("Confirm password");
    m_confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    m_passwordCodeEdit = new QLineEdit();
    m_passwordCodeEdit->setPlaceholderText("Code 8 digits");
    m_passwordCodeEdit->setMaxLength(8);

    m_changePasswordSaveButton = new QPushButton("Save");
    m_changePasswordSaveButton->setFixedHeight(50);
    m_sendPasswordCodeButton = new QPushButton("Send code");
    m_sendPasswordCodeButton->setFixedHeight(50);
    m_cancelPasswordChangeButton = new QPushButton("Cancel");
    m_cancelPasswordChangeButton->setFixedSize(100, 30);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(m_cancelPasswordChangeButton, 1, Qt::AlignCenter);
    
    m_vUChangePasswordSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_vDChangePasswordSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_hLChangePasswordSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    m_hRChangePasswordSpacer = new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    m_changePasswordVLayout = new QVBoxLayout();
    m_changePasswordVLayout->addItem(m_vUChangePasswordSpacer);
    m_changePasswordVLayout->addWidget(m_oldPasswordEdit);
    m_changePasswordVLayout->addWidget(m_newPasswordEdit);
    m_changePasswordVLayout->addWidget(m_confirmPasswordEdit);
    m_changePasswordVLayout->addWidget(m_passwordCodeEdit);
    m_changePasswordVLayout->addWidget(m_changePasswordSaveButton);
    m_changePasswordVLayout->addWidget(m_sendPasswordCodeButton);
    m_changePasswordVLayout->addLayout(hLayout);
    m_changePasswordVLayout->addItem(m_vDChangePasswordSpacer);

    m_changePasswordHLayout = new QHBoxLayout();
    m_changePasswordHLayout->addItem(m_hLChangePasswordSpacer);
    m_changePasswordHLayout->addLayout(m_changePasswordVLayout);
    m_changePasswordHLayout->addItem(m_hRChangePasswordSpacer);

    m_changePasswordWidget->setLayout(m_changePasswordHLayout);
}

void AccountView::setupDeleteAccountDialogs() {
    m_deleteAccountCodeDialog = new QMessageBox();
    m_deleteAccountCodeEdit = new QLineEdit();
    m_deleteAccountCodeEdit->setMaxLength(8);

    m_sendDeleteAccountCodeButton = new QPushButton("Send code");
    m_deleteAccountConfirmButton = new QPushButton("Confirm");

    m_deleteAccountCodeDialog->setWindowTitle("Delete account");
    m_deleteAccountCodeDialog->addButton(m_deleteAccountConfirmButton, QMessageBox::AcceptRole);
    m_deleteAccountCodeDialog->setText("Enter code to delete account");
    m_deleteAccountCodeDialog->layout()->addWidget(m_deleteAccountCodeEdit);
    m_deleteAccountCodeDialog->layout()->addWidget(m_sendDeleteAccountCodeButton);
    m_deleteAccountCodeDialog->layout()->addWidget(m_deleteAccountConfirmButton);

    m_deleteAccountDialog = new MessageBox(this);
}