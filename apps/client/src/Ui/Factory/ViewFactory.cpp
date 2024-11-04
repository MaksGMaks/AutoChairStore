#include "ViewFactory.hpp"

AccountView *ViewFactory::getAccountView(AccountViewModel *viewModel, QWidget *parent) {
    return new AccountView(viewModel, parent);
}

CatalogueView *ViewFactory::getCatalogueView(CatalogueViewModel *viewModel, QWidget *parent) {
    return new CatalogueView(viewModel, parent);
}

LoginRegistrationView *ViewFactory::getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent) {
    return new LoginRegistrationView(viewModel, parent);
}

PurchaseOrderInfoV *ViewFactory::getPurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent) {
    return new PurchaseOrderInfoV(viewModel, parent);
}

ProductPageView *ViewFactory::getProductPageView(ProductPageViewModel *viewModel, QWidget *parent) {
    return new ProductPageView(viewModel, parent);
}

BasketView *ViewFactory::getBasketView(BasketViewModel *viewModel, QWidget *parent) {
    return new BasketView(viewModel, parent);
}