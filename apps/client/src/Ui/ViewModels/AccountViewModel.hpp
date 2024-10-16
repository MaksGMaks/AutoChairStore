#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/UsersModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(UsersModel *model, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

    displayData::Users user() const;

signals:
    void modelEditUser(const Common::Users &entity);
    void modelEmailChangeCode(const std::string &email);
    void modelChangeCode(const std::string &email);
    void modelEmailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code);
    void modelPasswordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code);
    void modelDeleteAccount(const std::string &email, const std::string &code);

    void fetchUser();
    void emailCodeSentSuccessfully();
    void changeCodeSentSuccessfully();
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

public slots:
    void onEditUser(const displayData::Users &user);
    void onEmailChangeCode(const QString &email);
    void onChangeCode(const QString &email);
    void onEmailChange(const QString &oldEmail, const QString &newEmail, const QString &code);
    void onPasswordChange(const QString &email, const QString &oldPassword, const QString &newPassword, const QString &code);
    void onDeleteAccount(const QString &email, const QString &code);

private slots:
    void onFetchUser();
    void onEmailCodeSent();
    void onChangeCodeSent();
    void onPasswordChanged();
    void onDeleteAccountSuccess();

private:
    UsersModel *m_userModel;
    displayData::Users m_user;
    
    Common::Users convertUserToEntity(const displayData::Users &user);
    displayData::Users convertUserToDisplayData(const Common::Users &user);

};