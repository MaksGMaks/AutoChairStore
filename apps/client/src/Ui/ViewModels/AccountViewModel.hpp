#pragma once

#include <QSharedPointer>

#include "IViewModel.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(QSharedPointer<IModel> model, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

private:
    QSharedPointer<IModel> m_users;
};