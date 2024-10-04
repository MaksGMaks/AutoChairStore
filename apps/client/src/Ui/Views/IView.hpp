#pragma once

#include <QObject>

#include "Ui/ViewModels/IViewModel.hpp"

class IView : public QObject {
    Q_OBJECT
public:
    explicit IView(IViewModel &viewModel, QObject *parent = nullptr);
    virtual ~IView() = default;

signals:
    void errorOccurred(const QString &errorMessage);
};