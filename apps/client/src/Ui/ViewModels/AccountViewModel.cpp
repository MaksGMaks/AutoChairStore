#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(QSharedPointer<IModel> model, QObject *parent) 
    : IViewModel(*model, parent), m_users(std::move(model)) {
    
}
