#include "IView.hpp"

IView::IView(IViewModel *viewModel, QWidget *parent) : QWidget(parent) {
    m_errorMessageBox = new MessageBox(this);
    connect(viewModel, &IViewModel::errorOccurred, this, &IView::onErrorOccurred);
}

void IView::onErrorOccurred(const QString &errorMessage) {
    m_errorMessageBox->showErrorMessage(errorMessage);
}