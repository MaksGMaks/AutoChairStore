#pragma once

#include <iostream>
#include <memory>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class Menu : public QWidget {
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    virtual ~Menu() = default;

private:
    void setupUI();

    std::unique_ptr<QPushButton> m_accountButton;
    std::unique_ptr<QPushButton> m_purchaseBusketButton;
    std::unique_ptr<QPushButton> m_catalogButton;
    std::unique_ptr<QHBoxLayout> m_layout;

signals:
    void accountButtonClicked();
    void purchaseBusketButtonClicked();
    void catalogButtonClicked();

public slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

};