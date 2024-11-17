#pragma once

#include "Ui/ViewModels/IViewModel.hpp"
#include "Ui/ViewModels/BasketViewModel.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"
#include "Ui/ViewModels/ProductPageViewModel.hpp"
#include "Ui/ViewModels/CatalogueViewModel.hpp"
#include "Ui/ViewModels/LoginRegistrationViewModel.hpp"
#include "Ui/ViewModels/PurchaseOrderInfoVM.hpp"

class IViewModelFactory
{
public:
    virtual ~IViewModelFactory() = default;

    virtual AccountViewModel* getAccountVM(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, QObject *parent = nullptr) = 0;
    virtual BasketViewModel* getBasketVM(ProductsModel *productsModel, PurchaseOrdersModel *purchaseOrdersModel, UsersModel *usrModel, QObject *parent = nullptr) = 0;
    virtual ProductPageViewModel* getProductPageVM(ProductsModel *productsModel, PhotosModel *photosModel, QObject *parent = nullptr) = 0;
    virtual CatalogueViewModel* getCatalogueVM(ProductsModel *prodModel, PhotosModel *photosModel, QObject *parent = nullptr) = 0;
    virtual LoginRegistrationViewModel* getLoginRegistrationVM(UsersModel *model, QObject *parent = nullptr) = 0;
    virtual PurchaseOrderInfoVM* getPurchaseOrderInfoVM(PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent = nullptr) = 0;
};