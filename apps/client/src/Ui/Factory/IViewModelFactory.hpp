#pragma once

#include "Ui/ViewModels/IViewModel.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"
#include "Ui/ViewModels/CatalogueViewModel.hpp"
#include "Ui/ViewModels/LoginRegistrationViewModel.hpp"
#include "Ui/ViewModels/PurchaseOrderInfoVM.hpp"

class IViewModelFactory
{
public:
    virtual ~IViewModelFactory() = default;

    virtual AccountViewModel* getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent = nullptr) = 0;
    virtual CatalogueViewModel* getCatalogueVM(ProductsModel *model, QObject *parent = nullptr) = 0;
    virtual LoginRegistrationViewModel* getLoginRegistrationVM(UsersModel *model, QObject *parent = nullptr) = 0;
    virtual PurchaseOrderInfoVM* getPurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent = nullptr) = 0;
};