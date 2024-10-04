#include "ViewModelFactory.hpp"

std::unique_ptr<IViewModel> ViewModelFactory::getAccountVM(std::unique_ptr<IModel> model, QObject *parent) {
    std::unique_ptr<IViewModel> viewModel = std::make_unique<AccountViewModel>(std::move(model), parent);
    return viewModel;
}