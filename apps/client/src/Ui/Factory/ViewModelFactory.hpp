#pragma once

#include <memory>

#include "IFactory.hpp"
#include "Ui/ViewModels/IViewModel.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"

class ViewModelFactory : public IFactory {
public:
    std::unique_ptr<IViewModel> getAccountVM(std::unique_ptr<IModel> model, QObject *parent);
};

