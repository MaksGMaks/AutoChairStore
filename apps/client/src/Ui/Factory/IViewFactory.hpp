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
    virtual CatalogueView *getCatalogueView(IViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual LoginRegistrationView *getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual PurchaseOrderInfoV *getPurchaseOrderInfoV(AccountViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual ProductPageView *getProductPageView(CatalogueViewModel *viewModel, QWidget *parent = nullptr) = 0;
    virtual BasketView *getBasketView(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr) = 0;
};