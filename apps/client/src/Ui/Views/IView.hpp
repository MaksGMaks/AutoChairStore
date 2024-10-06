#pragma once

#include <QWidget>

#include "Ui/ViewModels/IViewModel.hpp"

class IView : public QWidget {
    Q_OBJECT
public:
    IView(IViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~IView() = default;

signals:
    void errorOccurred(const QString &errorMessage);
};