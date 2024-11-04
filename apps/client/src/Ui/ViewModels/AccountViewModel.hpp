#pragma once

#include "IViewModel.hpp"
#include "Ui/Models/UsersModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PhotosModel.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class AccountViewModel : public IViewModel {
    Q_OBJECT
public:
    explicit AccountViewModel(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, QObject *parent = nullptr);
    virtual ~AccountViewModel() = default;

    displayData::Users user() const;
    QVector<displayData::PurchaseOrder> purchaseOrders() const;

signals:
    void modelEditUser(const Common::Users &entity);
    void modelEmailChangeCode(const std::string &email);
    void modelChangeCode(const std::string &email);
    void modelEmailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code);
    void modelPasswordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code);
    void modelDeleteAccount(const std::string &email, const std::string &code);

    void fetchUser();
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

    void modelFetchPurchaseOrders(const std::string &userId);
    void purchaseOrdersFetched();
    

public slots:
    void onEditUser(const displayData::Users &user);
    void onEmailChangeCode(const QString &email);
    void onChangeCode(const QString &email);
    void onEmailChange(const QString &oldEmail, const QString &newEmail, const QString &code);
    void onPasswordChange(const QString &email, const QString &oldPassword, const QString &newPassword, const QString &code);
    void onDeleteAccount(const QString &email, const QString &code);

    void onFetchPurchaseOrders(const QString &userId);
    
private slots:
    void onFetchUser();
    void onPasswordChanged();
    void onDeleteAccountSuccess();

    void onPurchaseOrdersFetched();

private:
    UsersModel *m_userModel;
    PurchaseOrdersModel *m_purchaseOrdersModel;
    ProductsModel *m_productsModel;
    PhotosModel *m_photosModel;

    displayData::Users m_user;
    QVector<displayData::PurchaseOrder> m_purchaseOrders;
    
    Common::Users convertUserToEntity(const displayData::Users &user);
    displayData::Users convertUserToDisplayData(const Common::Users &user);

    displayData::PurchaseOrder convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order);
};