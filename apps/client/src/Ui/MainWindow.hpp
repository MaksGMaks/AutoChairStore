#pragma once

#include <QApplication>
#include <QMainWindow>

#include "Factory/ModelFactory.hpp"
#include "Factory/ViewModelFactory.hpp"
#include "Factory/ViewFactory.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent = nullptr);
    virtual ~MainWindow() = default;

private:
    std::unique_ptr<IModel> m_userModel;
    std::unique_ptr<IViewModel> m_accountViewModel;
    std::unique_ptr<IView> m_accountView;
};