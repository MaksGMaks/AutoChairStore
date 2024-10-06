#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(IModel *model, QObject *parent) 
    : IViewModel(model, parent), m_users(model) {}
