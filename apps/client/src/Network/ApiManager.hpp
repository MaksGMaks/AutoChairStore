#pragma once

#include <QObject>
#include "NetworkManager.hpp"

class ApiManager : public QObject {
    Q_OBJECT
public:
    ApiManager(NetworkManager &NetworkManager);
    virtual ~ApiManager();

private:
    NetworkManager &m_networkManager;
};