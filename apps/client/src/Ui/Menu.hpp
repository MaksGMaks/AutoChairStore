#pragma once

#include <iostream>
#include <QSharedPointer>
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

    QSharedPointer<QPushButton> m_accountButton;
    QSharedPointer<QPushButton> m_purchaseBusketButton;
    QSharedPointer<QPushButton> m_catalogButton;
    QSharedPointer<QHBoxLayout> m_layout;

signals:
    void accountButtonClicked();
    void purchaseBusketButtonClicked();
    void catalogButtonClicked();

public slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

};