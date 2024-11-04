#pragma once

#include "IViewFactory.hpp"

class ViewFactory : public IViewFactory {
public:
    AccountView *getAccountView(AccountViewModel *viewModel, QWidget *parent = nullptr) override;
    CatalogueView *getCatalogueView(CatalogueViewModel *viewModel, QWidget *parent = nullptr) override;
    LoginRegistrationView *getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent = nullptr) override;
    PurchaseOrderInfoV *getPurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr) override;
    ProductPageView *getProductPageView(ProductPageViewModel *viewModel, QWidget *parent = nullptr) override;
    BasketView *getBasketView(BasketViewModel *viewModel, QWidget *parent = nullptr) override;
};