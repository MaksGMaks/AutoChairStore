#include "ViewModelFactory.hpp"

AccountViewModel* ViewModelFactory::getAccountVM(UsersModel *model, QObject *parent) {
    return new AccountViewModel(model, parent);
}

CatalogueViewModel* ViewModelFactory::getCatalogueVM(ProductsModel *model, QObject *parent) {
    return new CatalogueViewModel(model, parent);
}

LoginRegistrationViewModel* ViewModelFactory::getLoginRegistrationVM(UsersModel *model, QObject *parent) {
    return new LoginRegistrationViewModel(model, parent);
}