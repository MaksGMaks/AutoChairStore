#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(std::unique_ptr<IModel> model, QObject *parent) 
    : IViewModel(*model, parent), m_users(std::move(model)) {
    
}
