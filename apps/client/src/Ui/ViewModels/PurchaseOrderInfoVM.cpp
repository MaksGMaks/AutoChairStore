#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent) 
    : IViewModel(parent), m_purchaseOrder(model) {}