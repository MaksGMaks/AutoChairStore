#pragma once

#include "IViewModel.hpp"

class PurchaseOrderInfoVM : public IViewModel {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoVM(std::unique_ptr<IModel> model, QObject *parent = nullptr);
    virtual ~PurchaseOrderInfoVM() = default;

private:
    std::unique_ptr<IModel> m_purchaseOrder;
};