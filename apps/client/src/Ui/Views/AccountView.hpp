#pragma once

#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QSpacerItem>

#include "IView.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"

class AccountView : public IView {
    Q_OBJECT

public:
    explicit AccountView(AccountViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~AccountView() = default;

private:
    // Methods
    void setupUI();
    void setupConnections();

    // View Models
    AccountViewModel *m_accountVM;

    // Layouts
    QVBoxLayout *m_profileLayout;
    QHBoxLayout *m_profileWidgetLayout;
    QHBoxLayout *m_ordersHLayout;
    QVBoxLayout *m_ordersVLayout;
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
    // QLabel *m_passwordLabel;

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
    // QLineEdit *m_passwordEdit;

    // Others
    QTableWidget *m_ordersTable;
    QWidget *m_profileWidget;
    QWidget *m_ordersWidget;

};