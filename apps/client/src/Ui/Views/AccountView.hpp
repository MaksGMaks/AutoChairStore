#pragma once

#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QHeaderView>

#include "IView.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"
#include "Ui/MessageBox.hpp"
#include "Ui/TimerButton.hpp"

class AccountView : public IView {
    Q_OBJECT

public:
    explicit AccountView(AccountViewModel *viewModel, QWidget *parent = nullptr);
    ~AccountView() = default;

signals:
    void vmEditUser(const displayData::Users &user);
    void vmEmailChangeCode(const QString &email);
    void vmChangeCode(const QString &email);
    void vmEmailChange(const QString &oldEmail, const QString &newEmail, const QString &code);
    void vmPasswordChange(const QString &email, const QString &oldPassword, const QString &newPassword, const QString &code);
    void vmDeleteAccount(const QString &email, const QString &code);

    void vmFetchPurchaseOrders(const QString &userId);
    void openOrder(const QString &id);

    void accountDeleted();

private slots:
    void onEditButtonClicked();
    void onSaveButtonClicked();

    void onChangeEmailButtonClicked();
    void onSaveEmailButtonClicked();
    void onSendEmailCodeButtonClicked();
    void onCancelEmailChangeButtonClicked();

    void onChangePasswordButtonClicked();
    void onSavePasswordButtonClicked();
    void onSendPasswordCodeButtonClicked();
    void onCancelPasswordChangeButtonClicked();

    void onDeleteAccountButtonClicked();
    void onSendDeleteAccountCodeButtonClicked();
    void onDeleteAccountConfirmButtonClicked();
    void onDeleteAccountConfirmed();

    void onOrderClicked();

    // View Model slots
    void onUserFetched();
    void onPasswordChanged();
    void onDeleteAccountSuccess();

    void onPurchaseOrdersFetched();

private:
    // Methods
    void setupUI();
    void setupEmailChangeWidget();
    void setupPasswordChangeWidget();
    void setupDeleteAccountDialogs();
    void setupConnections();

    // View Models
    AccountViewModel *m_accountVM;

    // MessageBox
    MessageBox *m_userEditErrorDialog;

    // Layouts
    QVBoxLayout *m_profileLayout;
    QHBoxLayout *m_profileWidgetLayout;
    QHBoxLayout *m_ordersHLayout;
    QVBoxLayout *m_ordersVLayout;
    QHBoxLayout *m_accountLayout;
    QHBoxLayout *m_mainLayout;

    // Spacers
    QSpacerItem *m_hRSpacer;
    QSpacerItem *m_hLSpacer;
    QSpacerItem *m_vUSpacer;
    QSpacerItem *m_vMSpacer;
    QSpacerItem *m_vDSpacer;
    QSpacerItem *m_hRTableSpacer;
    QSpacerItem *m_hLTableSpacer;
    QSpacerItem *m_vUTableSpacer;
    QSpacerItem *m_vDTableSpacer;

    // Labels
    QLabel *m_surnameLabel;
    QLabel *m_nameLabel;
    QLabel *m_emailLabel;

    // Buttons
    QPushButton *m_editButton;
    QPushButton *m_saveButton;
    QPushButton *m_changePasswordButton;
    QPushButton *m_changeEmailButton;
    QPushButton *m_deleteAccountButton;

    // Line Edits
    QLineEdit *m_surnameEdit;
    QLineEdit *m_nameEdit;
    QLineEdit *m_emailEdit;

    // Change email widget
    MessageBox *m_emailChangeErrorDialog;

    QWidget *m_changeEmailWidget;
    QLineEdit *m_newEmailEdit;
    QLineEdit *m_confirmEmailEdit;
    QLineEdit *m_emailCodeEdit;
    QPushButton *m_changeEmailSaveButton;
    QPushButton *m_sendEmailCodeButton;
    QPushButton *m_cancelEmailChangeButton;

    QSpacerItem *m_vUChangeEmailSpacer;
    QSpacerItem *m_vDChangeEmailSpacer;
    QSpacerItem *m_hLChangeEmailSpacer;
    QSpacerItem *m_hRChangeEmailSpacer;

    QLabel *m_emailChangeCodeTimerLabel;
    TimerButton *m_emailChangeCodeTimer;

    QVBoxLayout *m_changeEmailVLayout;
    QHBoxLayout *m_changeEmailHLayout;

    // Change password widget
    MessageBox *m_passwordChangeErrorDialog;
    MessageBox *m_passwordChangeSuccessDialog;

    QWidget *m_changePasswordWidget;
    QLineEdit *m_oldPasswordEdit;
    QLineEdit *m_newPasswordEdit;
    QLineEdit *m_confirmPasswordEdit;
    QLineEdit *m_passwordCodeEdit;
    QPushButton *m_changePasswordSaveButton;
    QPushButton *m_sendPasswordCodeButton;
    QPushButton *m_cancelPasswordChangeButton;

    QSpacerItem *m_vUChangePasswordSpacer;
    QSpacerItem *m_vDChangePasswordSpacer;
    QSpacerItem *m_hLChangePasswordSpacer;
    QSpacerItem *m_hRChangePasswordSpacer;

    QLabel *m_passwordChangeCodeTimerLabel;
    TimerButton *m_passwordChangeCodeTimer;

    QVBoxLayout *m_changePasswordVLayout;
    QHBoxLayout *m_changePasswordHLayout;

    // Delete account code dialog
    QMessageBox *m_deleteAccountCodeDialog;
    QLineEdit *m_deleteAccountCodeEdit;
    QPushButton *m_sendDeleteAccountCodeButton;
    QPushButton *m_deleteAccountConfirmButton;
    MessageBox *m_deleteAccountDialog;
    MessageBox *m_deleteAccountSuccessDialog;
    MessageBox *m_deleteAccountErrorDialog;

    QLabel *m_deleteAccountCodeLabel;
    TimerButton *m_deleteAccountCodeTimer;

    // Others
    QTableWidget *m_ordersTable;
    QWidget *m_profileWidget;
    QWidget *m_ordersWidget;
    QWidget *m_accountWidget;

    QStackedWidget *m_stackedWidget;

};