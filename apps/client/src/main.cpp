#include <iostream>
#include <QApplication>

#include "Network/NetworkManager.hpp"
#include "Network/ApiManager.hpp"
#include "Ui/MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QSharedPointer<NetworkManager> network = QSharedPointer<NetworkManager>::create();
    ApiManager apiManager(*network);
    
    ModelFactory modelFactory(apiManager);
    ViewModelFactory vmFactory;
    ViewFactory viewFactory;

    QSharedPointer<MainWindow> mainWindow = QSharedPointer<MainWindow>::create(modelFactory, vmFactory, viewFactory);
    mainWindow->show();

    return app.exec();
}