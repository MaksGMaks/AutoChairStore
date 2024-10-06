#include "ViewModelFactory.hpp"

QSharedPointer<IViewModel> ViewModelFactory::getAccountVM(QSharedPointer<IModel> model, QObject *parent) {
    QSharedPointer<IViewModel> viewModel = QSharedPointer<AccountViewModel>::create(std::move(model), parent);
    return viewModel;
}