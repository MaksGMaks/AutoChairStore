#include "ViewFactory.hpp"

AccountView *ViewFactory::getAccountView(AccountViewModel *viewModel, QWidget *parent) {
    return new AccountView(viewModel, parent);
}

CatalogueView *ViewFactory::getCatalogueView(IViewModel *viewModel, QWidget *parent) {
    return new CatalogueView(viewModel, parent);
}

LoginRegistrationView *ViewFactory::getLoginRegistrationView(LoginRegistrationViewModel *viewModel, QWidget *parent) {
    return new LoginRegistrationView(viewModel, parent);
}
