#include "ViewModelFactory.hpp"

IViewModel* ViewModelFactory::getAccountVM(IModel *model, QObject *parent) {
    IViewModel *viewModel = new AccountViewModel(model, parent);
    return viewModel;
}