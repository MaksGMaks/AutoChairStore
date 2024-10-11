#pragma once



#include "IViewModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"

class PurchaseOrderInfoVM : public IViewModel {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoVM(PurchaseOrdersModel *model, QObject *parent = nullptr);
    virtual ~PurchaseOrderInfoVM() = default;

private:
    PurchaseOrdersModel *m_purchaseOrder;
};