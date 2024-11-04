#pragma once

#include "Ui/Views/AccountView.hpp"
#include "Ui/Views/CatalogueView.hpp"
#include "Ui/Views/LoginRegistrationView.hpp"
#include "Ui/Views/PurchaseOrderInfoV.hpp"
#include "Ui/Views/ProductPageView.hpp"
#include "Ui/Views/BasketView.hpp"

class IViewFactory {
public:
    virtual ~IViewFactory() = default;

    virtual AccountView *getAccountView(AccountViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual CatalogueView *getCatalogueView(CatalogueViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual LoginRegistrationView *getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual PurchaseOrderInfoV *getPurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr) = 0;
    virtual ProductPageView *getProductPageView(ProductPageViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual BasketView *getBasketView(BasketViewModel *viewModel, QWidget *parent = nullptr) = 0;
};