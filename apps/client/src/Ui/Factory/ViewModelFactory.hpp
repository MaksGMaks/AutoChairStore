#pragma once

#include "IViewModelFactory.hpp"

class ViewModelFactory : public IViewModelFactory {
public:
    AccountViewModel* getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, QObject *parent = nullptr) override;
    BasketViewModel* getBasketVM(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, QObject *parent = nullptr) override;
    ProductPageViewModel* getProductPageVM(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent = nullptr) override;
    CatalogueViewModel* getCatalogueVM(ProductsModel *prodModel, PhotosModel *photosModel, QObject *parent = nullptr) override;
    LoginRegistrationViewModel* getLoginRegistrationVM(UsersModel *model, QObject *parent = nullptr) override;
    PurchaseOrderInfoVM* getPurchaseOrderInfoVM(PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent = nullptr) override;
};

