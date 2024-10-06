#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(std::unique_ptr<IModel> model, QObject *parent) : IViewModel(*model, parent) {
    m_purchaseOrder = std::move(model);
}