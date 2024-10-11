#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "Menu.hpp"

#include "Factory/ModelFactory.hpp"
#include "Factory/ViewModelFactory.hpp"
#include "Factory/ViewFactory.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent = nullptr);
    virtual ~MainWindow() = default;

public slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

private:
    void setupUi();
    void setupConnections();
    // Ui
    QStackedWidget *m_stackedWidget;
    Menu *m_menu;

    // Models
    UsersModel *m_userModel;
    
    // View Models
    AccountViewModel *m_accountViewModel;
    LoginRegistrationViewModel *m_loginRegistrationViewModel;
    
    // Views
    IView *m_accountView;
    IView *m_catalogueView;
    IView *m_loginRegistrationView;
};