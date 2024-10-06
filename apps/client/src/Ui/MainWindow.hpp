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
    std::unique_ptr<QStackedWidget> stackedWidget;
    std::unique_ptr<Menu> m_menu;

    // Models
    std::unique_ptr<IModel> m_userModel;
    
    // View Models
    std::unique_ptr<IViewModel> m_accountViewModel;
    
    // Views
    std::unique_ptr<IView> m_accountView;
};