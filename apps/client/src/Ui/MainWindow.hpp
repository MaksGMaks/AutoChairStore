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
    QSharedPointer<QStackedWidget> stackedWidget;
    QSharedPointer<Menu> m_menu;

    // Models
    QSharedPointer<IModel> m_userModel;
    
    // View Models
    QSharedPointer<IViewModel> m_accountViewModel;
    
    // Views
    QSharedPointer<IView> m_accountView;
};