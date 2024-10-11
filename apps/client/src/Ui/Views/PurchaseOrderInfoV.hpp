#pragma once

#include "IView.hpp"
#include "Ui/ViewModels/PurchaseOrderInfoVM.hpp"

class PurchaseOrderInfoV : public IView {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoV(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr);
    virtual ~PurchaseOrderInfoV() = default;

private:
    PurchaseOrderInfoVM *m_purchaseOrderVM;

};