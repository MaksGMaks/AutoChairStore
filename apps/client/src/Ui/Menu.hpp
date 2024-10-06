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

    QPushButton *m_accountButton;
    QPushButton *m_purchaseBusketButton;
    QPushButton *m_catalogButton;
    QHBoxLayout *m_layout;

signals:
    void accountButtonClicked();
    void purchaseBusketButtonClicked();
    void catalogButtonClicked();

public slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

};