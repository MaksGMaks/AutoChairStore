#include "AccountViewModel.hpp"

AccountViewModel::AccountViewModel(UsersModel *usrModel, PurchaseOrdersModel *ordersModel, ProductsModel *prodModel, PhotosModel *photoModel, QObject *parent) 
: IViewModel(parent)
, m_userModel(usrModel)
, m_purchaseOrdersModel(ordersModel)
, m_productsModel(prodModel)
, m_photosModel(photoModel) {
    // Connect to model signals
    connect(m_userModel, &UsersModel::fetchUser, this, &AccountViewModel::onFetchUser);
    connect(m_userModel, &UsersModel::passwordChangedSuccessfully, this, &AccountViewModel::onPasswordChanged);
    connect(m_userModel, &UsersModel::deleteAccountSuccessfully, this, &AccountViewModel::onDeleteAccountSuccess);

    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrdersFetched, this, &AccountViewModel::onPurchaseOrdersFetched);
    connect(m_purchaseOrdersModel, &PurchaseOrdersModel::purchaseOrderError, this, &AccountViewModel::onErrorOccurred);

    connect(m_productsModel, &ProductsModel::baseSeatLoadedSuccess, this, &AccountViewModel::onLoadBaseSeatSuccess);
    connect(m_productsModel, &ProductsModel::childSeatLoadedSuccess, this, &AccountViewModel::onLoadChildSeatSuccess);
    connect(m_productsModel, &ProductsModel::sportSeatLoadedSuccess, this, &AccountViewModel::onLoadSportSeatSuccess);
    connect(m_productsModel, &ProductsModel::luxurySeatLoadedSuccess, this, &AccountViewModel::onLoadLuxurySeatSuccess);

    // Connect to model slots
    connect(this, &AccountViewModel::modelEditUser, m_userModel, &UsersModel::onEditUser);
    connect(this, &AccountViewModel::modelEmailChangeCode, m_userModel, &UsersModel::onEmailChangeCode);
    connect(this, &AccountViewModel::modelChangeCode, m_userModel, &UsersModel::onChangeCode);
    connect(this, &AccountViewModel::modelEmailChange, m_userModel, &UsersModel::onEmailChange);
    connect(this, &AccountViewModel::modelPasswordChange, m_userModel, &UsersModel::onPasswordChange);
    connect(this, &AccountViewModel::modelDeleteAccount, m_userModel, &UsersModel::onDeleteAccount);

    connect(this, &AccountViewModel::modelFetchPurchaseOrders, m_purchaseOrdersModel, &PurchaseOrdersModel::onFetchPurchaseOrders);
    connect(this, &AccountViewModel::modelLoadSeat, m_productsModel, &ProductsModel::onLoadSeat);
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

void AccountViewModel::onCancelOrder(const QString &id) {
    emit modelCancelOrder(id.toStdString());
}

void AccountViewModel::onLoadSeat(const QString &id) {
    emit modelLoadSeat(id.toStdString());
}

void AccountViewModel::onLoadBaseSeatSuccess(const Common::BaseSeat &seat) {
    emit baseSeatLoadedSuccess(convertBaseSeatToDisplayData(seat));
}

void AccountViewModel::onLoadChildSeatSuccess(const Common::ChildSeat &seat) {
    emit childSeatLoadedSuccess(convertChildSeatToDisplayData(seat));
}

void AccountViewModel::onLoadSportSeatSuccess(const Common::SportSeat &seat) {
    emit sportSeatLoadedSuccess(convertSportSeatToDisplayData(seat));
}

void AccountViewModel::onLoadLuxurySeatSuccess(const Common::LuxurySeat &seat) {
    emit luxurySeatLoadedSuccess(convertLuxurySeatToDisplayData(seat));
}

void AccountViewModel::onCancelOrderSuccess() {
    //emit cancelOrderSuccess();
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

displayData::BaseSeat AccountViewModel::convertBaseSeatToDisplayData(const Common::BaseSeat &seat) {
    displayData::BaseSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById(seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.color = QString::fromStdString(seat.color);
    data.material = QString::fromStdString(seat.material);
    data.type = QString::fromStdString(seat.type);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::ChildSeat AccountViewModel::convertChildSeatToDisplayData(const Common::ChildSeat &seat) {
    displayData::ChildSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById(seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.age = QString::fromStdString(seat.age);
    data.weight = QString::fromStdString(seat.weight);
    data.height = QString::fromStdString(seat.height);
    data.safetyKey = QString::fromStdString(seat.safetyKey);
    data.fastening = QString::fromStdString(seat.fastening);
    data.driveway = QString::fromStdString(seat.driveway);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::SportSeat AccountViewModel::convertSportSeatToDisplayData(const Common::SportSeat &seat) {
    displayData::SportSeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById(seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.shellType = QString::fromStdString(seat.shellType);
    data.shellMaterial = QString::fromStdString(seat.shellMaterial);
    data.coverMaterial = QString::fromStdString(seat.coverMaterial);
    data.color = QString::fromStdString(seat.color);
    data.description = QString::fromStdString(seat.description);

    return data;
}

displayData::LuxurySeat AccountViewModel::convertLuxurySeatToDisplayData(const Common::LuxurySeat &seat) {
    displayData::LuxurySeat data;
    data.id = QString::fromStdString(seat.id);
    data.image = QString::fromStdString(m_photosModel->getPhotoById(seat.id));
    data.brand = QString::fromStdString(seat.brand);
    data.suitableFor = QString::fromStdString(seat.suitableFor);
    data.color = QString::fromStdString(seat.color);
    data.material = QString::fromStdString(seat.material);
    data.comfortLevel = QString::fromStdString(seat.comfortLevel);
    data.customDesign = QString::fromStdString(seat.customDesign);
    data.description = QString::fromStdString(seat.description);

    return data;
}