#pragma once

#include "IView.hpp"

class PurchaseOrderInfoV : public IView {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoV(IViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~PurchaseOrderInfoV() = default;

private:

};