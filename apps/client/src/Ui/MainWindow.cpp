#include "MainWindow.hpp"

MainWindow::MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent)
    : QMainWindow(parent) {
    // Models
    m_userModel = std::move(modelFactory.getUserModel());
    
    // View Models
    m_accountViewModel = std::move(vmFactory.getAccountVM(std::move(m_userModel)));
    m_loginRegistrationViewModel = std::move(vmFactory.getLoginRegistrationVM(std::move(m_userModel)));

    // Views
    m_accountView = std::move(viewFactory.getAccountView(std::move(m_accountViewModel)));
    m_catalogueView = std::move(viewFactory.getCatalogueView(std::move(m_accountViewModel)));
    m_loginRegistrationView = std::move(viewFactory.getLoginRegistrationView(std::move(m_loginRegistrationViewModel)));

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
    
    setCentralWidget(m_stackedWidget);
}

void MainWindow::setupConnections() {
    connect(m_menu, &Menu::accountButtonClicked, this, &MainWindow::onAccountButtonClicked);
    connect(m_menu, &Menu::purchaseBusketButtonClicked, this, &MainWindow::onPurchaseBusketButtonClicked);
    connect(m_menu, &Menu::catalogButtonClicked, this, &MainWindow::onCatalogButtonClicked);
}

void MainWindow::onAccountButtonClicked() {
    std::cout << "[MainWindow::onAccountButtonClicked] Account button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_accountView);
}

void MainWindow::onPurchaseBusketButtonClicked() {
    std::cout << "[MainWindow::onPurchaseBusketButtonClicked] Purchase busket button clicked" << std::endl;
}

void MainWindow::onCatalogButtonClicked() {
    std::cout << "[MainWindow::onCatalogButtonClicked] Catalog button clicked" << std::endl;
    m_stackedWidget->setCurrentWidget(m_catalogueView);
}