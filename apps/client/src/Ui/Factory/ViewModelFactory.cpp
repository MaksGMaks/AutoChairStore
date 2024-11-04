#include "ViewModelFactory.hpp"

AccountViewModel* ViewModelFactory::getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, QObject *parent) {
    return new AccountViewModel(usrModel, ordersModel, prodModel, parent);
}

BasketViewModel* ViewModelFactory::getBasketVM(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, QObject *parent) {
    return new BasketViewModel(productsModel, purchaseOrdersModel, parent);
}

ProductPageViewModel* ViewModelFactory::getProductPageVM(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent) {
    return new ProductPageViewModel(productsModel, photosModel, parent);
}

CatalogueViewModel* ViewModelFactory::getCatalogueVM(ProductsModel *prodModel, PhotosModel *photosModel, QObject *parent) {
    return new CatalogueViewModel(prodModel, photosModel, parent);
}

LoginRegistrationViewModel* ViewModelFactory::getLoginRegistrationVM(UsersModel *model, QObject *parent) {
    return new LoginRegistrationViewModel(model, parent);
}

PurchaseOrderInfoVM* ViewModelFactory::getPurchaseOrderInfoVM(PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent) {
    return new PurchaseOrderInfoVM(ordersModel, prodModel, photoModel, parent);
}