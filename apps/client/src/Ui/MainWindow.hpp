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

private slots:
    void onAccountButtonClicked();
    void onPurchaseBusketButtonClicked();
    void onCatalogButtonClicked();

    void onLoginSuccessfull();
    void onAccountDeleted();

private:
    void setupUi();
    void setupConnections();
    // Ui
    QStackedWidget *m_stackedWidget;
    Menu *m_menu;
    MessageBox *m_messageBox;

    // Models
    UsersModel *m_userModel;
    ProductsModel *m_productsModel;
    PurchaseOrdersModel *m_purchaseOrdersModel;
    PhotosModel *m_photosModel;

    // View Models
    AccountViewModel *m_accountViewModel;
    LoginRegistrationViewModel *m_loginRegistrationViewModel;
    CatalogueViewModel *m_catalogueViewModel;
    ProductPageViewModel *m_productPageViewModel;
    PurchaseOrderInfoVM *m_purchaseOrderInfoVM;
    BasketViewModel *m_basketViewModel;
    
    // Views
    AccountView *m_accountView;
    CatalogueView *m_catalogueView;
    LoginRegistrationView *m_loginRegistrationView;
    PurchaseOrderInfoV *m_purchaseOrderInfoV;
    ProductPageView *m_productPageView;
    BasketView *m_basketView;
};