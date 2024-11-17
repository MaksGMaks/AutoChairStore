#pragma once

#include <QObject>
#include "NetworkManager.hpp"
#include "TEST_PHOTOS.hpp"

class ApiManager : public QObject {
    Q_OBJECT
public:
    ApiManager(NetworkManager &NetworkManager);
    virtual ~ApiManager() = default;

    // Login and registration
    void loginUser(const Common::Users &entity);
    void registerUser(const Common::Users &entity, const std::string &code);
    void sendCode(const std::string &email);

    //  Account
    void editUser(const Common::Users &entity);
    void emailChangeCode(const std::string &email);
    void changeCode(const std::string &email);
    void emailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code);
    void passwordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code);
    void deleteAccount(const std::string &email, const std::string &code);

    // Purchase orders
    void fetchPurchaseOrders(const std::string &userId);
    void createPurchaseOrder(const std::vector<Common::PurchaseOrders> &entity);

    // Product
    void fetchProducts();
    void fetchBaseSeats();
    void fetchChildSeats();
    void fetchSportSeats();
    void fetchLuxurySeats();

    // Photos
    void fetchPhotos();

signals:
    // Login and registration
    void loginRegistrationError(const std::string &errorMessage);
    void userLoginSuccessfull(const Common::Users &entity);
    void userRegisteredSuccessfully(const Common::Users &entity);
    void codeSentSuccessfully();

    // Account
    void accountError(const std::string &errorMessage);
    void userFetched(const Common::Users &entity);
    void emailChangedSuccessfully(const Common::Users &entity);
    void passwordChangedSuccessfully();
    void deleteAccountSuccessfully();

    // Purchase orders
    void purchaseOrdersError(const std::string &errorMessage);
    void purchaseOrdersFetched(const std::vector<Common::PurchaseOrders> &orders);
    void orderCreated();

    // Product
    void productsError(const std::string &errorMessage);
    void productsFetched(const std::vector<Common::Products> &products);
    void baseSeatsFetched(const std::vector<Common::BaseSeat> &baseSeats);
    void childSeatsFetched(const std::vector<Common::ChildSeat> &childSeats);
    void sportSeatsFetched(const std::vector<Common::SportSeat> &sportSeats);
    void luxurySeatsFetched(const std::vector<Common::LuxurySeat> &luxurySeats);

    // Photos
    void photosError(const std::string &errorMessage);
    void photosFetched(const std::vector<Common::Photos> &photos);

private:
    NetworkManager &m_networkManager;

    // Tests

    void setTests();
    std::vector<Common::Users> testUsers;
    std::string testCode;
    std::vector<std::string> testEmails;
    std::vector<Common::PurchaseOrders> testOrders;
    std::vector<Common::Products> testProducts;

    std::vector<Common::BaseSeat> testBaseSeats;
    std::vector<Common::ChildSeat> testChildSeats;
    std::vector<Common::SportSeat> testSportSeats;
    std::vector<Common::LuxurySeat> testLuxurySeats;

    std::vector<Common::Photos> testPhotos;

};