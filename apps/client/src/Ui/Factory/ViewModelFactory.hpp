#pragma once

#include "IViewModelFactory.hpp"

class ViewModelFactory : public IViewModelFactory {
public:
    AccountViewModel* getAccountVM(UsersModel *model, QObject *parent = nullptr) override;
    CatalogueViewModel* getCatalogueVM(ProductsModel *model, QObject *parent = nullptr) override;
    LoginRegistrationViewModel* getLoginRegistrationVM(UsersModel *model, QObject *parent = nullptr) override;
};

