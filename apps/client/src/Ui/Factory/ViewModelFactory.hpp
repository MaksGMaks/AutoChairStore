#pragma once

#include <QSharedPointer>

#include "IFactory.hpp"
#include "Ui/ViewModels/IViewModel.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"

class ViewModelFactory : public IFactory {
public:
    IViewModel* getAccountVM(IModel *model, QObject *parent);
};

