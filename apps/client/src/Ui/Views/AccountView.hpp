#pragma once

#include <iostream>
#include <memory>
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
    explicit AccountView(std::unique_ptr<IViewModel> viewModel, QWidget *parent = nullptr);
    virtual ~AccountView() = default;

private:
    // View Models
    std::unique_ptr<IViewModel> m_accountVM;

    // Layouts
    std::unique_ptr<QVBoxLayout> m_profileLayout;
    std::unique_ptr<QHBoxLayout> m_profileWidgetLayout;
    std::unique_ptr<QVBoxLayout> m_ordersLayout;
    std::unique_ptr<QHBoxLayout> m_mainLayout;

    // Spacers
    std::unique_ptr<QSpacerItem> m_hRSpacer;
    std::unique_ptr<QSpacerItem> m_hLSpacer;
    std::unique_ptr<QSpacerItem> m_vUSpacer;
    std::unique_ptr<QSpacerItem> m_vDSpacer;

    // Labels
    std::unique_ptr<QLabel> m_surnameLabel;
    std::unique_ptr<QLabel> m_nameLabel;
    std::unique_ptr<QLabel> m_emailLabel;
    std::unique_ptr<QLabel> m_passwordLabel;

    // Buttons
    std::unique_ptr<QPushButton> m_editButton;
    std::unique_ptr<QPushButton> m_saveButton;

    // Line Edits
    std::unique_ptr<QLineEdit> m_surnameEdit;
    std::unique_ptr<QLineEdit> m_nameEdit;
    std::unique_ptr<QLineEdit> m_emailEdit;
    std::unique_ptr<QLineEdit> m_passwordEdit;

    // Others
    std::unique_ptr<QTableWidget> m_ordersTable;
    std::unique_ptr<QWidget> m_profileWidget;
    std::unique_ptr<QWidget> m_ordersWidget;

    // Methods
    void setupUI();
};