#include "ApiManager.hpp"

ApiManager::ApiManager(NetworkManager &networkManager) : m_networkManager(networkManager) {
    setTests();
}

void ApiManager::loginUser(const Common::Users &entity) {
    std::cout << "[ApiManager::loginUser] Logging in user" << std::endl;
    
    for(auto &user : testUsers) {
        if(entity.email == user.email && entity.password == user.password) {
            emit userLoginSuccessfull(user);
            return;
        }
    }
    emit loginRegistrationError("Invalid email or password");
}

void ApiManager::registerUser(const Common::Users &entity, const std::string &code) {
    std::cout << "[ApiManager::registerUser] Registering user" << std::endl;
    if(code == testCode) {
        for(auto &user : testUsers) {
            if(entity.email == user.email) {
                emit loginRegistrationError("Email already exists");
                return;
            }
        }
        testUsers.push_back(entity);
        emit userRegisteredSuccessfully(entity);
    } else {
        emit loginRegistrationError("Invalid code");
    }
}

void ApiManager::sendCode(const std::string &email) {
    std::cout << "[ApiManager::sendCode] Sending code to email: " << email << std::endl;
    for(auto &testEmail : testEmails) {
        if(email == testEmail) {
            return;
        }    
    }
    emit loginRegistrationError("Can't send code to this email");
}

void ApiManager::editUser(const Common::Users &entity) {
    std::cout << "[ApiManager::editUser] Editing user" << std::endl;
    for(auto &user : testUsers) {
        if(user.email == entity.email) {
            user.name = entity.name;
            user.surname = entity.surname;
            emit userFetched(user);
            return;
        }
    }
}

void ApiManager::emailChangeCode(const std::string &email) {
    std::cout << "[ApiManager::emailChangeCode] Sending email change code to email: " << email << std::endl;
    for(auto &testEmail : testEmails) {
        if(email == testEmail) {
            return;
        }    
    }
    emit loginRegistrationError("Can't send code to this email");
}

void ApiManager::changeCode(const std::string &email) {
    std::cout << "[ApiManager::changeCode] Sending password change code to email: " << email << std::endl;
    for(auto &testEmail : testEmails) {
        if(email == testEmail) {
            return;
        }    
    }    
    emit loginRegistrationError("Can't send code to this email");
}

void ApiManager::emailChange(const std::string &oldEmail, const std::string &newEmail, const std::string &code) {
    std::cout << "[ApiManager::emailChange] Changing email" << std::endl;
    for(auto &user : testUsers) {
        if(oldEmail == user.email && code == testCode) {
            user.email = newEmail;
            emit emailChangedSuccessfully(user);
            return;
        }
    }
}

void ApiManager::passwordChange(const std::string &email, const std::string &oldPassword, const std::string &newPassword, const std::string &code) {
    std::cout << "[ApiManager::passwordChange] Changing password" << std::endl;
    for(auto &user : testUsers) {
        if(email == user.email && oldPassword == user.password && code == testCode) {
            user.password = newPassword;
            emit passwordChangedSuccessfully();
            return;
        }
    }
}

void ApiManager::deleteAccount(const std::string &email, const std::string &code) {
    std::cout << "[ApiManager::deleteAccount] Deleting account" << std::endl;
    Common::Users user;
    for(auto &testUser : testUsers) {
        if(email == testUser.email && code == testCode) {
            user = testUser;
            break;
        }
    }
    testUsers.erase(std::remove(testUsers.begin(), testUsers.end(), user), testUsers.end());
    emit deleteAccountSuccessfully();   
}

void ApiManager::fetchPurchaseOrders(const std::string &userId) {
    std::cout << "[ApiManager::fetchPurchaseOrders] Fetching purchase orders" << std::endl;
    
    std::vector<Common::PurchaseOrders> orders;
    for(auto &order : testOrders) {
        if(order.userId == userId) {
            orders.push_back(order);
        }
    }
    emit purchaseOrdersFetched(orders);
}

void ApiManager::fetchProducts() {
    std::cout << "[ApiManager::fetchProducts] Fetching products" << std::endl;
    emit productsFetched(testProducts);
}

void ApiManager::fetchBaseSeats() {
    std::cout << "[ApiManager::fetchBaseSeats] Fetching base seats" << std::endl;
    emit baseSeatsFetched(testBaseSeats);
}

void ApiManager::fetchChildSeats() {
    std::cout << "[ApiManager::fetchChildSeats] Fetching child seats" << std::endl;
    emit childSeatsFetched(testChildSeats);
}

void ApiManager::fetchSportSeats() {
    std::cout << "[ApiManager::fetchSportSeats] Fetching sport seats" << std::endl;
    emit sportSeatsFetched(testSportSeats);
}

void ApiManager::fetchLuxurySeats() {
    std::cout << "[ApiManager::fetchLuxurySeats] Fetching luxury seats" << std::endl;
    emit luxurySeatsFetched(testLuxurySeats);
}

void ApiManager::fetchPhotos() {
    std::cout << "[ApiManager::fetchPhotos] Fetching photos" << std::endl;
    emit photosFetched(testPhotos);
}

void ApiManager::createPurchaseOrder(const Common::PurchaseOrders &entity) {
    std::cout << "[ApiManager::createPurchaseOrder] Creating purchase order" << std::endl;
    testOrders.push_back(entity);
    emit orderCreated();
}

void ApiManager::setTests() {
    test::test_photos utils;

    testUsers.reserve(5);
    Common::Users user;
    user.id = "0";
    user.name = "Max";
    user.surname = "Kozak";
    user.email = "kozak@gmail.com";
    user.password = "12345678";
    testUsers.push_back(user);
    testCode = "12345678";
    testEmails = {"kozak@gmail.com", "test123@gmail.com", "test321@hotmail.com", "max@lpnu.ua", "gachi@gmail.com"};

    testProducts.reserve(20);
    for(int i = 0; i < 20; i++) {
        Common::Products product;
        product.id = std::to_string(i);
        product.productName = "Product " + std::to_string(i);
        product.productType = (i < 5) ? "1" : (i < 10) ? "2" : (i < 15) ? "3" : "4";
        product.productTypeId = std::to_string(i % 5);
        product.price = std::to_string(20000 + (i * 1000));
        product.priceUnit = "грн";
        product.quantity = 10;
        product.hasDiscount = (i % 2 == 0) ? "TRUE" : "FALSE";
        product.discount = "50";
        product.isReadyToSell = true;
        testProducts.push_back(product);
    }

    testOrders.reserve(5);
    Common::PurchaseOrders order;
    order.id = "1";
    order.userId = "0";
    order.productId = "1";
    order.paidType = "Card";
    order.destination = "City, Street, House";
    order.packageId = "99 9999 9999 9999";
    order.deliveryDate = "2021-12-12";
    order.status = "Delivered";
    testOrders.push_back(order);

    testBaseSeats.reserve(5);
    for(int i = 0; i < 5; i++) {
        Common::BaseSeat seat;
        seat.id = std::to_string(i);
        seat.brand = "Brand " + std::to_string(i);
        seat.suitableFor = "Suitable for " + std::to_string(i);
        seat.color = "Color " + std::to_string(i);
        seat.material = "Material " + std::to_string(i);
        seat.type = "Type " + std::to_string(i);
        seat.description = "Description " + std::to_string(i);
        testBaseSeats.push_back(seat);
    }

    testChildSeats.reserve(5);
    for(int i = 0; i < 5; i++) {
        Common::ChildSeat seat;
        seat.id = std::to_string(i);
        seat.brand = "Brand " + std::to_string(i);
        seat.age = "Age " + std::to_string(i);
        seat.weight = "Weight " + std::to_string(i);
        seat.height = "Height " + std::to_string(i);
        seat.safetyKey = "Safety key " + std::to_string(i);
        seat.fastening = "Fastening " + std::to_string(i);
        seat.driveway = "Driveway " + std::to_string(i);
        seat.description = "Description " + std::to_string(i);
        testChildSeats.push_back(seat);
    }

    testSportSeats.reserve(5);
    for(int i = 0; i < 5; i++) {
        Common::SportSeat seat;
        seat.id = std::to_string(i);
        seat.brand = "Brand " + std::to_string(i);
        seat.suitableFor = "Suitable for " + std::to_string(i);
        seat.shellType = "Shell type " + std::to_string(i);
        seat.shellMaterial = "Shell material " + std::to_string(i);
        seat.coverMaterial = "Cover material " + std::to_string(i);
        seat.color = "Color " + std::to_string(i);
        seat.description = "Description " + std::to_string(i);
        testSportSeats.push_back(seat);
    }

    testLuxurySeats.reserve(5);
    for(int i = 0; i < 5; i++) {
        Common::LuxurySeat seat;
        seat.id = std::to_string(i);
        seat.brand = "Brand " + std::to_string(i);
        seat.suitableFor = "Suitable for " + std::to_string(i);
        seat.color = "Color " + std::to_string(i);
        seat.material = "Material " + std::to_string(i);
        seat.comfortLevel = "Comfort level " + std::to_string(i);
        seat.customDesign = "Custom design " + std::to_string(i);
        seat.description = "Description " + std::to_string(i);
        testLuxurySeats.push_back(seat);
    }

    testPhotos.reserve(20);
    for(int i = 0; i < 20; i++) {
        Common::Photos photo;
        photo.id = std::to_string(i);
        photo.productType = (i < 5) ? "1" : (i < 10) ? "2" : (i < 15) ? "3" : "4";
        photo.productTypeId = std::to_string(i % 5);
        testPhotos.push_back(photo);
    }

    for(auto &photo : testPhotos) {
        if(photo.productType == "1") {
            photo.image = (photo.productTypeId == "0") ? utils.seat1 : (photo.productTypeId == "1") ? utils.seat2 : (photo.productTypeId == "2") 
            ? utils.seat3 : (photo.productTypeId == "3") ? utils.seat4 : utils.seat5;
        } else if(photo.productType == "2") {
            photo.image = (photo.productTypeId == "0") ? utils.childSeat1 : (photo.productTypeId == "1") ? utils.childSeat2 : (photo.productTypeId == "2")
            ? utils.childSeat3 : (photo.productTypeId == "3") ? utils.childSeat4 : utils.childSeat5;
        } else if(photo.productType == "3") {
            photo.image = (photo.productTypeId == "0") ? utils.sportSeat1 : (photo.productTypeId == "1") ? utils.sportSeat2 : (photo.productTypeId == "2")
            ? utils.sportSeat3 : (photo.productTypeId == "3") ? utils.sportSeat4 : utils.sportSeat5;
        } else {
            photo.image = (photo.productTypeId == "0") ? utils.luxurySeat1 : (photo.productTypeId == "1") ? utils.luxurySeat2 : (photo.productTypeId == "2")
            ? utils.luxurySeat3 : (photo.productTypeId == "3") ? utils.luxurySeat4 : utils.luxurySeat5;
        }
    }
}