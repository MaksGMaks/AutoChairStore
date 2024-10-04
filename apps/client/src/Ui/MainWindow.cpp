#include "MainWindow.hpp"

MainWindow::MainWindow(ModelFactory &modelFactory, ViewModelFactory &vmFactory, ViewFactory &viewFactory, QWidget *parent)
    : QMainWindow(parent) {
    m_userModel = std::move(modelFactory.getUserModel(this));
    m_accountViewModel = std::move(vmFactory.getAccountVM(std::move(m_userModel), this));
    m_accountView = std::move(viewFactory.getAccountView(std::move(m_accountViewModel), this));
}