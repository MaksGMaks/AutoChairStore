#pragma once

#include <iostream>

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>

class Menu : public QWidget {
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    virtual ~Menu() = default;

private:
    void setupUI();

    // Buttons
    QPushButton *m_accountButton;
    QPushButton *m_purchaseBusketButton;
    QPushButton *m_catalogButton;
    
    // Layout
    QHBoxLayout *m_layout;

    // Icons
    QIcon m_accountIcon;
    QIcon m_purchaseBusketIcon;
    QIcon m_catalogIcon;

signals:
    void accountButtonClicked();
    void purchaseBusketButtonClicked();
    void catalogButtonClicked();

public slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

};