#pragma once

#include <QObject>
#include "Ui/Models/IModel.hpp"

class IViewModel : public QObject {
    Q_OBJECT

public:
    IViewModel(IModel *model, QObject *parent = nullptr);
    virtual ~IViewModel() = default;

signals:
    void errorOccurred(const QString &errorMessage);
};