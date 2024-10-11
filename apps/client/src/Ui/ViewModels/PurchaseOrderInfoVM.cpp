#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent) 
    : IViewModel(model, parent), m_purchaseOrder(model) {}