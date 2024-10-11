#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/UsersModel.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(UsersModel *model, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

private:
    UsersModel *m_users;
    
};