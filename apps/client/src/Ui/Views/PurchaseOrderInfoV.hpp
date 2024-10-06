#pragma once

#include "IView.hpp"

class PurchaseOrderInfoV : public IView {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoV(std::unique_ptr<IViewModel> viewModel, QWidget *parent = nullptr);
    virtual ~PurchaseOrderInfoV() = default;

private:

};