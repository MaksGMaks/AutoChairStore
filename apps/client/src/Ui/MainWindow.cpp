#include "MainWindow.hpp"

MainWindow::MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent)
    : QMainWindow(parent) {
    m_userModel = std::move(modelFactory.getUserModel(this));
    m_accountViewModel = std::move(vmFactory.getAccountVM(std::move(m_userModel), this));
    m_accountView = std::move(viewFactory.getAccountView(std::move(m_accountViewModel), this));

    setWindowTitle("Autochair Shop");
    resize(800, 600);

    setupUi();
}

void MainWindow::setupUi() {
    m_menu = std::make_unique<Menu>(this);
    m_menu->setFixedHeight(50);
    setMenuWidget(m_menu.get());
    stackedWidget = std::make_unique<QStackedWidget>(this);
    stackedWidget->addWidget(m_accountView.get());
    
    setCentralWidget(stackedWidget.get());
}

void MainWindow::setupConnections() {
    connect(m_menu.get(), &Menu::accountButtonClicked, this, &MainWindow::onAccountButtonClicked);
    connect(m_menu.get(), &Menu::purchaseBusketButtonClicked, this, &MainWindow::onPurchaseBusketButtonClicked);
    connect(m_menu.get(), &Menu::catalogButtonClicked, this, &MainWindow::onCatalogButtonClicked);
}

void MainWindow::onAccountButtonClicked() {
    std::cout << "[MainWindow::onAccountButtonClicked] Account button clicked" << std::endl;
}

void MainWindow::onPurchaseBusketButtonClicked() {
    std::cout << "[MainWindow::onPurchaseBusketButtonClicked] Purchase busket button clicked" << std::endl;
}

void MainWindow::onCatalogButtonClicked() {
    std::cout << "[MainWindow::onCatalogButtonClicked] Catalog button clicked" << std::endl;
}