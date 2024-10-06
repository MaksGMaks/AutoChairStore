#include "ViewFactory.hpp"

IView* ViewFactory::getAccountView(IViewModel *viewModel, QWidget *parent) {
    IView *view = new AccountView(viewModel, parent);
    return view;
}