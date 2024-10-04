#include "AccountView.hpp"

AccountView::AccountView(std::unique_ptr<IViewModel> viewModel, QObject *parent) 
    : IView(*viewModel, parent), m_accountVM(std::move(viewModel)) {
    
}