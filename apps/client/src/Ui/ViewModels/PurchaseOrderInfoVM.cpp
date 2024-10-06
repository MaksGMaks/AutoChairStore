#include "PurchaseOrderInfoVM.hpp"

PurchaseOrderInfoVM::PurchaseOrderInfoVM(QSharedPointer<IModel> model, QObject *parent) : IViewModel(*model, parent) {
    m_purchaseOrder = std::move(model);
}