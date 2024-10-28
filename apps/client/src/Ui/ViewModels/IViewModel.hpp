#pragma once

#include <QObject>
#include "Ui/Models/IModel.hpp"

class IViewModel : public QObject {
    Q_OBJECT

public:
    IViewModel(QObject *parent = nullptr);
    virtual ~IViewModel() = default;

protected slots:
    void onErrorOccurred(const std::string &errorMessage);

signals:
    void errorOccurred(const QString &errorMessage);
};