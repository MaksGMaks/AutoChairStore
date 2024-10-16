#pragma once

#include <QObject>

class IModel : public QObject {
    Q_OBJECT

public:
    IModel(QObject *parent = nullptr);
    virtual ~IModel() = default;
};