#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class SuppliersModel : public IModel {
    Q_OBJECT
public:
    explicit SuppliersModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~SuppliersModel() = default;

    QVector<Common::Suppliers> suppliers() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::Suppliers> m_suppliers;
};