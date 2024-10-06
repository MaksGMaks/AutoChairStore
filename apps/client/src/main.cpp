#include <iostream>
#include <QApplication>

#include "Network/NetworkManager.hpp"
#include "Network/ApiManager.hpp"
#include "Ui/MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    NetworkManager *network = new NetworkManager();
    ApiManager apiManager(*network);
    
    ModelFactory modelFactory(apiManager);
    ViewModelFactory vmFactory;
    ViewFactory viewFactory;

    MainWindow *mainWindow = new MainWindow(modelFactory, vmFactory, viewFactory);
    mainWindow->show();

    return app.exec();
}