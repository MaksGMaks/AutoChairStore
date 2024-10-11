#pragma once

#include <QVector>

#include "IViewModel.hpp"
#include "Ui/Models/UsersModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class LoginRegistrationViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit LoginRegistrationViewModel(UsersModel *model, QObject *parent = nullptr);
    virtual ~LoginRegistrationViewModel() = default;

    displayData::Users user() const;

signals:
    void loginSuccessfull();
    void loginFail();
    
    void registrationSuccessfull();
    void registrationFail();

    void loginUser(const Common::Users &entity);
    void registerUser(const Common::Users &entity);
    
    void errorOccurred(const QString &errorMessage);

private slots:
    void onUserLogin();
    void onUserLoginFailed();
    void onUserRegistered();
    void onUserRegisterationFailed();

public slots:
    void onLoginUser(const displayData::Users &entity);
    void onRegisterUser(const displayData::Users &entity);

private:
    UsersModel *m_users;

    displayData::Users m_usersData;

    displayData::Users convertToDisplayData(const Common::Users &entity);
    Common::Users convertToEntity(const displayData::Users &entity);


};