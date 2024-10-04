#include "ViewFactory.hpp"

std::unique_ptr<IView> ViewFactory::getAccountView(std::unique_ptr<IViewModel> viewModel, QObject *parent) {
    std::unique_ptr<IView> view = std::make_unique<AccountView>(std::move(viewModel), parent);
    return view;
}