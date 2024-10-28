#include "MainWindow.hpp"

MainWindow::MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent)
    : QMainWindow(parent) {
    // Models
    m_userModel = std::move(modelFactory.getUserModel());
    m_productsModel = std::move(modelFactory.getProductsModel());
    m_purchaseOrdersModel = std::move(modelFactory.getPurchaseOrdersModel());
    m_photosModel = std::move(modelFactory.getPhotosModel());
    
    // View Models
    m_accountViewModel = std::move(vmFactory.getAccountVM(std::move(m_userModel), std::move(m_purchaseOrdersModel), std::move(m_productsModel), 
                         std::move(m_photosModel)));
    m_loginRegistrationViewModel = std::move(vmFactory.getLoginRegistrationVM(std::move(m_userModel)));
    m_catalogueViewModel = std::move(vmFactory.getCatalogueVM(std::move(m_productsModel)));
    m_purchaseOrderInfoVM = std::move(vmFactory.getPurchaseOrderInfoVM(std::move(m_purchaseOrdersModel)));

    // Views
    m_accountView = std::move(viewFactory.getAccountView(std::move(m_accountViewModel)));
    m_catalogueView = std::move(viewFactory.getCatalogueView(std::move(m_catalogueViewModel)));
    m_loginRegistrationView = std::move(viewFactory.getLoginRegistrationView(std::move(m_loginRegistrationViewModel)));
    m_purchaseOrderInfoV = std::move(viewFactory.getPurchaseOrderInfoV(std::move(m_accountViewModel)));
    m_productPageView = std::move(viewFactory.getProductPageView(std::move(m_catalogueViewModel)));
    m_basketView = std::move(viewFactory.getBasketView(std::move(m_purchaseOrderInfoVM)));

    setWindowTitle("Autochair Shop");
    resize(800, 600);

    setupUi();
    setupConnections();
    
    m_menu->setVisible(false);
}

void MainWindow::setupUi() {
    m_menu = new Menu(this);
    m_menu->setFixedHeight(50);
    setMenuWidget(m_menu);
    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->addWidget(m_loginRegistrationView);
    m_stackedWidget->addWidget(m_accountView);
    m_stackedWidget->addWidget(m_catalogueView);
    m_stackedWidget->addWidget(m_purchaseOrderInfoV);
    m_stackedWidget->addWidget(m_productPageView);
    m_stackedWidget->addWidget(m_basketView);
    
    setCentralWidget(m_stackedWidget);
}

void MainWindow::setupConnections() {
    connect(m_menu, &Menu::accountButtonClicked, this, &MainWindow::onAccountButtonClicked);
    connect(m_menu, &Menu::purchaseBusketButtonClicked, this, &MainWindow::onPurchaseBusketButtonClicked);
    connect(m_menu, &Menu::catalogButtonClicked, this, &MainWindow::onCatalogButtonClicked);

    connect(m_loginRegistrationView, &LoginRegistrationView::loginRegistrationSuccessfull, this, &MainWindow::onLoginSuccessfull);
    connect(m_accountView, &AccountView::accountDeleted, this, &MainWindow::onAccountDeleted);

    connect(m_accountView, &AccountView::openOrder, [this](const QString &id) {
        m_purchaseOrderInfoV->onLoadOrder(id);
        m_stackedWidget->setCurrentWidget(m_purchaseOrderInfoV);
    });

    connect(m_purchaseOrderInfoV, &PurchaseOrderInfoV::goBack, [this]() {
        m_stackedWidget->setCurrentWidget(m_accountView);
    });

    connect(m_catalogueView, &CatalogueView::openProductPage, [this](const QString &id) {
        m_productPageView->onLoadOrder(id);
        m_stackedWidget->setCurrentWidget(m_productPageView);
    });
}

void MainWindow::onLoginSuccessfull() {
    std::cout << "[MainWindow::onLoginSuccessfull] User logged in successfully" << std::endl;
    m_menu->setVisible(true);
    m_stackedWidget->setCurrentWidget(m_catalogueView);
    m_productsModel->fetchProducts();
}

void MainWindow::onAccountDeleted() {
    std::cout << "[MainWindow::onAccountDeleted] Account deleted" << std::endl;
    m_menu->setVisible(false);
    m_stackedWidget->setCurrentWidget(m_loginRegistrationView);
}

void MainWindow::onAccountButtonClicked() {
    std::cout << "[MainWindow::onAccountButtonClicked] Account button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_accountView);
    m_userModel->fetchUser();
}

void MainWindow::onPurchaseBusketButtonClicked() {
    std::cout << "[MainWindow::onPurchaseBusketButtonClicked] Purchase busket button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_basketView);
}

void MainWindow::onCatalogButtonClicked() {
    std::cout << "[MainWindow::onCatalogButtonClicked] Catalog button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_catalogueView);
    m_productsModel->fetchProducts();
}