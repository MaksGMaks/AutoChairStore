#include "IView.hpp"

IView::IView(IViewModel &viewModel, QObject *parent) : QObject(parent) {
    connect(this, &IView::errorOccurred, &viewModel, &IViewModel::errorOccurred);
}