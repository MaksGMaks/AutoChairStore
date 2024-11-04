#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, QObject *parent) 
: IViewModel(parent)
, m_userModel(usrModel)
, m_purchaseOrdersModel(ordersModel)
, m_productsModel(prodModel) {
    // Connect to model signals
    connect(m_userModel, &UsersModel::fetchUser, this, &AccountViewModel::onFetchUser);
    connect(m_userModel, &UsersModel::passwordChangedSuccessfully, this, &AccountViewModel::onPasswordChanged);
    connect(m_userModel, &UsersModel::deleteAccountSuccessfully, this, &AccountViewModel::onDeleteAccountSuccess);

    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrdersFetched, this, &AccountViewModel::onPurchaseOrdersFetched);
    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrderError, this, &AccountViewModel::onErrorOccurred);

    // Connect to model slots
    connect(this, &AccountViewModel::modelEditUser, m_userModel, &UsersModel::onEditUser);
    connect(this, &AccountViewModel::modelEmailChangeCode, m_userModel, &UsersModel::onEmailChangeCode);
    connect(this, &AccountViewModel::modelChangeCode, m_userModel, &UsersModel::onChangeCode);
    connect(this, &AccountViewModel::modelEmailChange, m_userModel, &UsersModel::onEmailChange);
    connect(this, &AccountViewModel::modelPasswordChange, m_userModel, &UsersModel::onPasswordChange);
    connect(this, &AccountViewModel::modelDeleteAccount, m_userModel, &UsersModel::onDeleteAccount);

    connect(this, &AccountViewModel::modelFetchPurchaseOrders, m_purchaseOrdersModel, &PurchaseOrdersModel::onFetchPurchaseOrders);
}

displayData::Users AccountViewModel::user() const {
    return m_user;
}

QVector<displayData::PurchaseOrder> AccountViewModel::purchaseOrders() const {
    return m_purchaseOrders;
}

void AccountViewModel::onEditUser(const displayData::Users &user) {
    emit modelEditUser(convertUserToEntity(user));
}

void AccountViewModel::onEmailChangeCode(const QString &email) {
    emit modelEmailChangeCode(email.toStdString());
}

void AccountViewModel::onChangeCode(const QString &email) {
    emit modelChangeCode(email.toStdString());
}

void AccountViewModel::onEmailChange(const QString &oldEmail, const QString &newEmail, const QString &code) {
    emit modelEmailChange(oldEmail.toStdString(), newEmail.toStdString(), code.toStdString());
}

void AccountViewModel::onPasswordChange(const QString &email, const QString &oldPassword, const QString &newPassword, const QString &code) {
    emit modelPasswordChange(email.toStdString(), oldPassword.toStdString(), newPassword.toStdString(), code.toStdString());
}

void AccountViewModel::onDeleteAccount(const QString &email, const QString &code) {
    emit modelDeleteAccount(email.toStdString(), code.toStdString());
}

void AccountViewModel::onFetchUser() {
    m_user = convertUserToDisplayData(m_userModel->user());
    emit fetchUser();
}

void AccountViewModel::onPasswordChanged() {
    emit passwordChangedSuccessfully();
}

void AccountViewModel::onDeleteAccountSuccess() {
    emit deleteAccountSuccessfully();
}

void AccountViewModel::onFetchPurchaseOrders(const QString &userId) {
    emit modelFetchPurchaseOrders(userId.toStdString());
}

void AccountViewModel::onPurchaseOrdersFetched() {
    std::cout << "[AccountViewModel::onPurchaseOrdersFetched] Purchase orders fetched" << std::endl;
    m_purchaseOrders.clear();
    for(const auto &order : m_purchaseOrdersModel->purchaseOrders()) {
        m_purchaseOrders.push_back(convertPurchaseOrderToDisplayData(order));
    }
    emit purchaseOrdersFetched();
}

Common::Users AccountViewModel::convertUserToEntity(const displayData::Users &user) {
    Common::Users entity;
    entity.id = user.id.toStdString();
    entity.name = user.name.toStdString();
    entity.surname = user.surname.toStdString();
    entity.email = user.email.toStdString();
    entity.password = user.password.toStdString();

    return entity;
}

displayData::Users AccountViewModel::convertUserToDisplayData(const Common::Users &user) {
    displayData::Users data;
    data.id = QString::fromStdString(user.id);
    data.name = QString::fromStdString(user.name);
    data.surname = QString::fromStdString(user.surname);
    data.email = QString::fromStdString(user.email);
    data.password = QString::fromStdString(user.password);

    return data;
}


displayData::PurchaseOrder AccountViewModel::convertPurchaseOrderToDisplayData(const Common::PurchaseOrders &order) {
    displayData::PurchaseOrder data;
    data.id = QString::fromStdString(order.id);
    data.userId = QString::fromStdString(order.userId);
    data.productId = QString::fromStdString(order.productId);
    data.productName = QString::fromStdString(m_productsModel->getNameById(order.productId));
    data.paidType = QString::fromStdString(order.paidType);
    data.date = QString::fromStdString(order.deliveryDate);
    data.destination = QString::fromStdString(order.destination);
    data.packageId = QString::fromStdString(order.packageId);
    data.status = QString::fromStdString(order.status);

    std::cout << "[AccountViewModel::convertPurchaseOrderToDisplayData] Product name before: " << order.productId  << "\nProduct name after: " << data.productId.toStdString() << std::endl;

    return data;
}