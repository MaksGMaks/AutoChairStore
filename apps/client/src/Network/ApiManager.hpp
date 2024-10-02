#pragma once

#include <QObject>
#include "NetworkManager.hpp"

class ApiManager : public QObject {
    Q_OBJECT
public:
    explicit ApiManager(NetworkManager &NetworkManager);
    ~ApiManager();

private:
    NetworkManager &m_networkManager;
};