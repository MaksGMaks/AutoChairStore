#pragma once

#include "IViewFactory.hpp"

class ViewFactory : public IViewFactory {
public:
    AccountView *getAccountView(AccountViewModel *viewModel, QWidget *parent = nullptr) override;
    CatalogueView *getCatalogueView(IViewModel *viewModel, QWidget *parent = nullptr) override;
    LoginRegistrationView *getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent = nullptr) override;
    PurchaseOrderInfoV *getPurchaseOrderInfoV(AccountViewModel *viewModel, QWidget *parent = nullptr) override;
    ProductPageView *getProductPageView(CatalogueViewModel *viewModel, QWidget *parent = nullptr) override;
    BasketView *getBasketView(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr) override;
};