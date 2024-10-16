#pragma once

#include <iostream>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QTimer>

#include "IView.hpp"
#include "Ui/ViewModels/LoginRegistrationViewModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"
#include "Ui/MessageBox.hpp"

class LoginRegistrationView : public IView {
    Q_OBJECT
public:
    explicit LoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~LoginRegistrationView() = default;

signals:
    // Sends the user data to the view model on login or registration
    void loginUser(const displayData::Users &user);
    void registerUser(const displayData::Users &user);
    void sendCode(const QString &email);

private slots:
    // Button clicked slots
    void onLoginButtonClicked();
    void onRegistrationLinkButtonClicked();
    void approveRegistrationLinkButtonClicked();

    void onCreateAccountButtonClicked();
    void onSendCodeButtonClicked();
    void onLoginLinkButtonClicked();
    void approveLoginLinkButtonClicked();

    // Result slots
    void onCodeSentSuccessfully();

private:
    void setupUI();
    void setupConnection();
    void setupLoginWidget();
    void setupRegistrationWidget();

    LoginRegistrationViewModel *m_loginRegistrationVM;
    
    // Main widget
    QStackedWidget *m_stackedWidget;

    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_pageLayout;

    QSpacerItem *m_lHSpacer;
    QSpacerItem *m_rHSpacer;
    QSpacerItem *m_vUSpacer;
    QSpacerItem *m_vDSpacer;

    // Login widget
    QWidget *m_loginWidget;
    
    MessageBox *m_emptyLoginError;
    MessageBox *m_unsavedDataLoginMessage;

    QPushButton *m_loginButton;
    QPushButton *m_registrationLinkButton;
    
    QLineEdit *m_emailLineEdit;
    QLineEdit *m_passwordLineEdit;

    QSpacerItem *m_vLoginSpacer;
    QSpacerItem *m_vButtonLoginSpacer;
    QSpacerItem *m_hLCenterSpacer;
    QSpacerItem *m_hRCenterSpacer;

    QVBoxLayout *m_loginLayout;
    QHBoxLayout *m_loginButtonLayout;
    QHBoxLayout *m_registrationLinkLayout;

    // Registration widget
    QWidget *m_registrationWidget;

    QTimer *m_codeTimer;

    MessageBox *m_emptyRegistrationError;
    MessageBox *m_differentPasswordsRegistrationError;
    MessageBox *m_unsavedDataRegistrationMessage;

    QPushButton *m_createAccountButton;
    QPushButton *m_sendCodeButton;
    QPushButton *m_loginLinkButton;

    QLineEdit *m_firstNameRegistrationLineEdit;
    QLineEdit *m_lastNameRegistrationLineEdit;
    QLineEdit *m_emailRegistrationLineEdit;
    QLineEdit *m_emailCodeRegistrationLineEdit;
    QLineEdit *m_passwordRegistrationLineEdit;
    QLineEdit *m_confirmPasswordRegistrationLineEdit;

    QSpacerItem *m_vRegistrationSpacer;
    QSpacerItem *m_vLoginLinkSpacer;
    QSpacerItem *m_hLCenterRegistrationSpacer;
    QSpacerItem *m_hRCenterRegistrationSpacer;

    QVBoxLayout *m_registrationLayout;

    QHBoxLayout *m_registrationButtonLayout;
    QHBoxLayout *m_sendCodeButtonLayout;
    QHBoxLayout *m_loginLinkLayout;
};