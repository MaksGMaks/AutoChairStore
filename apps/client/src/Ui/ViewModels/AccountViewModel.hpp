#pragma once

#include <QSharedPointer>

#include "IViewModel.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(IModel *model, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

private:
    IModel *m_users;
};