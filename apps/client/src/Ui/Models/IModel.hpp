#pragma once

#include <QObject>

class IModel : public QObject {
    Q_OBJECT

public:
    explicit IModel(QObject *parent = nullptr);
    virtual ~IModel();

signals:
    void errorOccurred(const QString &errorMessage);
};