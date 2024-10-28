#pragma once

#include "IViewModelFactory.hpp"

class ViewModelFactory : public IViewModelFactory {
public:
    AccountViewModel* getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent = nullptr) override;
    CatalogueViewModel* getCatalogueVM(ProductsModel *model, QObject *parent = nullptr) override;
    LoginRegistrationViewModel* getLoginRegistrationVM(UsersModel *model, QObject *parent = nullptr) override;
    PurchaseOrderInfoVM* getPurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent = nullptr) override;
};

