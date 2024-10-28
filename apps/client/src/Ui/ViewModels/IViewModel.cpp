#include "IViewModel.hpp"

IViewModel::IViewModel(QObject *parent) : QObject(parent) {
}

void IViewModel::onErrorOccurred(const std::string &errorMessage) {
    emit errorOccurred(QString::fromStdString(errorMessage));
}