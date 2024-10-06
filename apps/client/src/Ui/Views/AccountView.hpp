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
    explicit AccountView(QSharedPointer<IViewModel> viewModel, QWidget *parent = nullptr);
    virtual ~AccountView() = default;

private:
    // View Models
    QSharedPointer<IViewModel> m_accountVM;

    // Layouts
    QSharedPointer<QVBoxLayout> m_profileLayout;
    QSharedPointer<QHBoxLayout> m_profileWidgetLayout;
    QSharedPointer<QVBoxLayout> m_ordersLayout;
    QSharedPointer<QHBoxLayout> m_mainLayout;

    // Spacers
    QSharedPointer<QSpacerItem> m_hRSpacer;
    QSharedPointer<QSpacerItem> m_hLSpacer;
    QSharedPointer<QSpacerItem> m_vUSpacer;
    QSharedPointer<QSpacerItem> m_vDSpacer;

    // Labels
    QSharedPointer<QLabel> m_surnameLabel;
    QSharedPointer<QLabel> m_nameLabel;
    QSharedPointer<QLabel> m_emailLabel;
    QSharedPointer<QLabel> m_passwordLabel;

    // Buttons
    QSharedPointer<QPushButton> m_editButton;
    QSharedPointer<QPushButton> m_saveButton;

    // Line Edits
    QSharedPointer<QLineEdit> m_surnameEdit;
    QSharedPointer<QLineEdit> m_nameEdit;
    QSharedPointer<QLineEdit> m_emailEdit;
    QSharedPointer<QLineEdit> m_passwordEdit;

    // Others
    QSharedPointer<QTableWidget> m_ordersTable;
    QSharedPointer<QWidget> m_profileWidget;
    QSharedPointer<QWidget> m_ordersWidget;

    // Methods
    void setupUI();
};