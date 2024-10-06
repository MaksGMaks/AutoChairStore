#include "IViewModel.hpp"

IViewModel::IViewModel(IModel *model, QObject *parent) : QObject(parent) {
    connect(this, &IViewModel::errorOccurred, model, &IModel::errorOccurred);
}