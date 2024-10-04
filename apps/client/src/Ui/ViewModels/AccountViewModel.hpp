#pragma once

#include "IViewModel.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(std::unique_ptr<IModel> model, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

private:
    std::unique_ptr<IModel> m_users;
};