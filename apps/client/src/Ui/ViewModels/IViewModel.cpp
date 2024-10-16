#include "IViewModel.hpp"

IViewModel::IViewModel(QObject *parent) : QObject(parent) {
}

void IViewModel::onErrorOccurred(const QString &errorMessage) {
    emit errorOccurred(errorMessage);
}