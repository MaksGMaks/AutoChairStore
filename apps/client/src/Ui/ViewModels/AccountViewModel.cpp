#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(UsersModel *model, QObject *parent) 
    : IViewModel(model, parent), m_users(model) {}
