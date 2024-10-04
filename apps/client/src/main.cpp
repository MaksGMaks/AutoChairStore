#include <iostream>
#include <QApplication>

#include "Network/NetworkManager.hpp"
#include "Network/ApiManager.hpp"
#include "Ui/MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::unique_ptr<NetworkManager> network = std::make_unique<NetworkManager>();
    ApiManager apiManager(*network);
    
    ModelFactory modelFactory(apiManager);
    ViewModelFactory vmFactory;
    ViewFactory viewFactory;

    std::unique_ptr<MainWindow> mainWindow = std::make_unique<MainWindow>(modelFactory, vmFactory, viewFactory);
    mainWindow->show();

    return app.exec();
}