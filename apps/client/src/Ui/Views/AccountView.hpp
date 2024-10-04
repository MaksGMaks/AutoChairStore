#pragma once

#include "IView.hpp"

class AccountView : public IView {
    Q_OBJECT

public:
    explicit AccountView(std::unique_ptr<IViewModel> viewModel, QObject *parent = nullptr);
    virtual ~AccountView() = default;

private:
    std::unique_ptr<IViewModel> m_accountVM;
};