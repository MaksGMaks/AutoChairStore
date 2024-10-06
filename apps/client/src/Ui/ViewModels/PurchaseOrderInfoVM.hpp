#pragma once

#include <QSharedPointer>

#include "IViewModel.hpp"

class PurchaseOrderInfoVM : public IViewModel {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoVM(IModel *model, QObject *parent = nullptr);
    virtual ~PurchaseOrderInfoVM() = default;

private:
    IModel m_purchaseOrder;
};