#pragma once

#include <QSharedPointer>

#include "IFactory.hpp"
#include "Ui/Views/IView.hpp"
#include "Ui/Views/AccountView.hpp"

class ViewFactory : public IFactory {
public:
    QSharedPointer<IView> getAccountView(QSharedPointer<IViewModel> viewModel, QWidget *parent);
};