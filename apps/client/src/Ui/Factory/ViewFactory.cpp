#include "ViewFactory.hpp"

QSharedPointer<IView> ViewFactory::getAccountView(QSharedPointer<IViewModel> viewModel, QWidget *parent) {
    QSharedPointer<IView> view = QSharedPointer<AccountView>::create(std::move(viewModel), parent);
    return view;
}