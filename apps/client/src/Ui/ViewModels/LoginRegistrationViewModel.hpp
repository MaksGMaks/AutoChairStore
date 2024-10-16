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

signals:
    void modelLoginUser(const Common::Users &entity);
    void modelRegisterUser(const Common::Users &entity);
    void modelSendCode(const std::string &email);

    void codeSentSuccessfully();

public slots:
    void onLoginUser(const displayData::Users &entity);
    void onRegisterUser(const displayData::Users &entity);
    void onSendCode(const QString &email);

private slots:
    void onCodeSentSuccessfully();

private:
    UsersModel *m_users;

    displayData::Users convertToDisplayData(const Common::Users &entity);
    Common::Users convertToEntity(const displayData::Users &entity);


};