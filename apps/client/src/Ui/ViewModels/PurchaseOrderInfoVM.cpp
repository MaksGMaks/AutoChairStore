#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(IModel *model, QObject *parent) 
    : IViewModel(model, parent), m_purchaseOrder(model) {}