#pragma once

#include <memory>

#include "IFactory.hpp"
#include "Ui/Views/IView.hpp"
#include "Ui/Views/AccountView.hpp"

class ViewFactory : public IFactory {
public:
    std::unique_ptr<IView> getAccountView(std::unique_ptr<IViewModel> viewModel, QWidget *parent);
};