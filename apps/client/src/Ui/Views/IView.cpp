#include "IView.hpp"

IView::IView(IViewModel &viewModel, QWidget *parent) : QWidget(parent) {
    connect(this, &IView::errorOccurred, &viewModel, &IViewModel::errorOccurred);
}