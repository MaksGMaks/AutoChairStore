#include "PurchaseOrderInfoV.hpp"

PurchaseOrderInfoV::PurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent) 
    : IView(viewModel, parent), 
      m_purchaseOrderVM(viewModel) {
    std::cout << "[PurchaseOrderInfoV::PurchaseOrderInfoV] constructor" << std::endl;
}