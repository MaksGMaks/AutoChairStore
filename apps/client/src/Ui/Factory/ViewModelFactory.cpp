#include "ViewModelFactory.hpp"

AccountViewModel* ViewModelFactory::getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent) {
    return new AccountViewModel(usrModel, ordersModel, prodModel, photoModel, parent);
}

CatalogueViewModel* ViewModelFactory::getCatalogueVM(ProductsModel *model, QObject *parent) {
    return new CatalogueViewModel(model, parent);
}

LoginRegistrationViewModel* ViewModelFactory::getLoginRegistrationVM(UsersModel *model, QObject *parent) {
    return new LoginRegistrationViewModel(model, parent);
}

PurchaseOrderInfoVM* ViewModelFactory::getPurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent) {
    return new PurchaseOrderInfoVM(model, parent);
}