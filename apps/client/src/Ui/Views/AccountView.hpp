#pragma once

#include <iostream>
#include <QSharedPointer>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QSpacerItem>

#include <QSharedPointer>

#include "IView.hpp"

class AccountView : public IView {
    Q_OBJECT

public:
    explicit AccountView(IViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~AccountView() = default;

private:
    // View Models
    IViewModel *m_accountVM;

    // Layouts
    QVBoxLayout *m_profileLayout;
    QHBoxLayout *m_profileWidgetLayout;
    QVBoxLayout *m_ordersLayout;
    QHBoxLayout *m_mainLayout;

    // Spacers
    QSpacerItem *m_hRSpacer;
    QSpacerItem *m_hLSpacer;
    QSpacerItem *m_vUSpacer;
    QSpacerItem *m_vDSpacer;

    // Labels
    QLabel *m_surnameLabel;
    QLabel *m_nameLabel;
    QLabel *m_emailLabel;
    QLabel *m_passwordLabel;

    // Buttons
    QPushButton *m_editButton;
    QPushButton *m_saveButton;

    // Line Edits
    QLineEdit *m_surnameEdit;
    QLineEdit *m_nameEdit;
    QLineEdit *m_emailEdit;
    QLineEdit *m_passwordEdit;

    // Others
    QTableWidget *m_ordersTable;
    QWidget *m_profileWidget;
    QWidget *m_ordersWidget;

    // Methods
    void setupUI();
};