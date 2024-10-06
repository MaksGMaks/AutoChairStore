#pragma once

#include <QSharedPointer>

#include "IViewModel.hpp"

class PurchaseOrderInfoVM : public IViewModel {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoVM(QSharedPointer<IModel> model, QObject *parent = nullptr);
    virtual ~PurchaseOrderInfoVM() = default;

private:
    QSharedPointer<IModel> m_purchaseOrder;
};