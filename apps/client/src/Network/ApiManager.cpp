#include "ApiManager.hpp"

ApiManager::ApiManager(NetworkManager &networkManager) : m_networkManager(networkManager) {
    setTests();
}

void ApiManager::loginUser(const Common::Users &entity) {
    std::cout << "[ApiManager::loginUser] Logging in user" << std::endl;
    
    // for(auto &user : testUsers) {
    //     if(entity.email == user.email && entity.password == user.password) {
    //         emit userLoginSuccessfull(user);
    //         return;
    //     }
    // }

    Common::Request request = Common::Request::GETSPECIAL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::Users::TABLE_NAME};
    data[Common::COLUMN_KEY] = {Common::Users::EMAIL_KEY, Common::Users::PASSWORD_KEY};
    data[Common::Users::EMAIL_KEY] = {entity.email};
    data[Common::Users::PASSWORD_KEY] = {entity.password};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();
    if(response[Common::RESPONSE_KEY].front() == Common::SUCCESS) {
        Common::Users user;
        user.id = response[Common::Users::ID_KEY].front();
        user.name = response[Common::Users::NAME_KEY].front();
        user.surname = response[Common::Users::SURNAME_KEY].front();
        user.email = response[Common::Users::EMAIL_KEY].front();
        emit userLoginSuccessfull(user);
    } else {
        emit loginRegistrationError("Invalid email or password");
    }
}

void ApiManager::registerUser(const Common::Users &entity, const std::string &code) {
    std::cout << "[ApiManager::registerUser] Registering user" << std::endl;
    // if(code == testCode) {
    //     for(auto &user : testUsers) {
    //         if(entity.email == user.email) {
    //             emit loginRegistrationError("Email already exists");
    //             return;
    //         }
    //     }
    //     testUsers.push_back(entity);
    //     emit userRegisteredSuccessfully(entity);
    // } else {
    //     emit loginRegistrationError("Invalid code");
    // }
    if(code == testCode) {
        Common::Request request = Common::Request::ADD;
        Common::Dataset data;
        data[Common::TABLE_KEY] = {Common::Users::TABLE_NAME};
        data[Common::Users::NAME_KEY] = {entity.name};
        data[Common::Users::SURNAME_KEY] = {entity.surname};
        data[Common::Users::EMAIL_KEY] = {entity.email};
        data[Common::Users::PASSWORD_KEY] = {entity.password};
        m_networkManager.sendRequest(data, request);
        Common::Dataset response = m_networkManager.readResponse();
        if(response[Common::RESPONSE_KEY].front() == Common::SUCCESS) {
            emit userRegisteredSuccessfully(entity);
        } else {
            emit loginRegistrationError("Email already exists");
        }
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
    
    // std::vector<Common::PurchaseOrders> orders;
    // for(auto &order : testOrders) {
    //     if(order.userId == userId) {
    //         orders.push_back(order);
    //     }
    // }
    // emit purchaseOrdersFetched(orders);

    Common::Request request = Common::Request::GETSPECIAL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::PurchaseOrders::TABLE_NAME};
    data[Common::COLUMN_KEY] = {Common::PurchaseOrders::USERID_KEY};
    data[Common::PurchaseOrders::USERID_KEY] = {userId};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    if(response[Common::RESPONSE_KEY].front() == Common::SUCCESS) {
        std::vector<Common::PurchaseOrders> orders;
        Common::Data ids = response[Common::PurchaseOrders::ID_KEY];
        Common::Data userIds = response[Common::PurchaseOrders::USERID_KEY];
        Common::Data productIds = response[Common::PurchaseOrders::PRODUCTID_KEY];
        Common::Data paidTypes = response[Common::PurchaseOrders::PAIDTYPE_KEY];
        Common::Data destinations = response[Common::PurchaseOrders::DESTINATION_KEY];
        Common::Data packageIds = response[Common::PurchaseOrders::PACKAGEID_KEY];
        Common::Data deliveryDates = response[Common::PurchaseOrders::DELIVERYDATE_KEY];
        Common::Data statuses = response[Common::PurchaseOrders::STATUS_KEY];

        for(auto id : ids) {
            Common::PurchaseOrders order;
            order.id = id;
            order.userId = userIds.front();
            userIds.pop_front();
            order.productId = productIds.front();
            productIds.pop_front();
            order.paidType = paidTypes.front();
            paidTypes.pop_front();
            order.destination = destinations.front();
            destinations.pop_front();
            order.packageId = packageIds.front();
            packageIds.pop_front();
            order.deliveryDate = deliveryDates.front();
            deliveryDates.pop_front();
            order.status = statuses.front();
            statuses.pop_front();

            orders.push_back(order);
        }

        emit purchaseOrdersFetched(orders);
    } else {
        emit purchaseOrdersError("Error fetching purchase orders");
    }
}

void ApiManager::fetchProducts() {
    std::cout << "[ApiManager::fetchProducts] Fetching products" << std::endl;
    Common::Request request = Common::Request::GETALL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::Products::TABLE_NAME};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    std::vector<Common::Products> products;
    Common::Data ids = response[Common::Products::ID_KEY];
    Common::Data productNames = response[Common::Products::PRODUCTNAME_KEY];
    Common::Data productTypes = response[Common::Products::PRODUCTTYPE_KEY];
    Common::Data productTypeIds = response[Common::Products::PRODUCTTYPEID_KEY];
    Common::Data prices = response[Common::Products::PRICE_KEY];
    Common::Data priceUnits = response[Common::Products::PRICEUNIT_KEY];
    Common::Data quantities = response[Common::Products::QUANTITY_KEY];
    Common::Data hasDiscounts = response[Common::Products::HASDISCOUNT_KEY];
    Common::Data discounts = response[Common::Products::DISCOUNT_KEY];
    Common::Data isReadyToSells = response[Common::Products::ISREADYTOSELL_KEY];

    for(auto id : ids) {
        Common::Products product;
        product.id = id;
        product.productName = productNames.front();
        productNames.pop_front();
        product.productType = productTypes.front();
        productTypes.pop_front();
        product.productTypeId = productTypeIds.front();
        productTypeIds.pop_front();
        product.price = prices.front();
        prices.pop_front();
        product.priceUnit = priceUnits.front();
        priceUnits.pop_front();
        product.quantity = std::stoi(quantities.front());
        quantities.pop_front();
        product.hasDiscount = hasDiscounts.front();
        hasDiscounts.pop_front();
        product.discount = discounts.front();
        discounts.pop_front();
        product.isReadyToSell = isReadyToSells.front() == "TRUE";
        isReadyToSells.pop_front();

        products.push_back(product);
    }

    emit productsFetched(products);
}

void ApiManager::fetchBaseSeats() {
    std::cout << "[ApiManager::fetchBaseSeats] Fetching base seats" << std::endl;
    Common::Request request = Common::Request::GETALL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::BaseSeat::TABLE_NAME};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    std::vector<Common::BaseSeat> baseSeats;
    Common::Data ids = response[Common::BaseSeat::ID_KEY];
    Common::Data brands = response[Common::BaseSeat::BRAND_KEY];
    Common::Data suitableFors = response[Common::BaseSeat::SUITABLEFOR_KEY];
    Common::Data colors = response[Common::BaseSeat::COLOR_KEY];
    Common::Data materials = response[Common::BaseSeat::MATERIAL_KEY];
    Common::Data types = response[Common::BaseSeat::TYPE_KEY];
    Common::Data descriptions = response[Common::BaseSeat::DESCRIPTION_KEY];

    for(auto id : ids) {
        Common::BaseSeat seat;
        seat.id = id;
        seat.brand = brands.front();
        brands.pop_front();
        seat.suitableFor = suitableFors.front();
        suitableFors.pop_front();
        seat.color = colors.front();
        colors.pop_front();
        seat.material = materials.front();
        materials.pop_front();
        seat.type = types.front();
        types.pop_front();
        seat.description = descriptions.front();
        descriptions.pop_front();

        baseSeats.push_back(seat);
    }

    emit baseSeatsFetched(baseSeats);
}

void ApiManager::fetchChildSeats() {
    std::cout << "[ApiManager::fetchChildSeats] Fetching child seats" << std::endl;
    Common::Request request = Common::Request::GETALL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::ChildSeat::TABLE_NAME};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    std::vector<Common::ChildSeat> childSeats;
    Common::Data ids = response[Common::ChildSeat::ID_KEY];
    Common::Data brands = response[Common::ChildSeat::BRAND_KEY];
    Common::Data ages = response[Common::ChildSeat::AGE_KEY];
    Common::Data weights = response[Common::ChildSeat::WEIGHT_KEY];
    Common::Data heights = response[Common::ChildSeat::HEIGHT_KEY];
    Common::Data safetyKeys = response[Common::ChildSeat::SAFETYKEY_KEY];
    Common::Data fastenings = response[Common::ChildSeat::FASTENING_KEY];
    Common::Data driveways = response[Common::ChildSeat::DRIVEWAY_KEY];
    Common::Data childDescriptions = response[Common::ChildSeat::DESCRIPTION_KEY];

    for(auto id : ids) {
        Common::ChildSeat seat;
        seat.id = id;
        seat.brand = brands.front();
        brands.pop_front();
        seat.age = ages.front();
        ages.pop_front();
        seat.weight = weights.front();
        weights.pop_front();
        seat.height = heights.front();
        heights.pop_front();
        seat.safetyKey = safetyKeys.front();
        safetyKeys.pop_front();
        seat.fastening = fastenings.front();
        fastenings.pop_front();
        seat.driveway = driveways.front();
        driveways.pop_front();
        seat.description = childDescriptions.front();
        childDescriptions.pop_front();

        childSeats.push_back(seat);
    }

    emit childSeatsFetched(childSeats);
}

void ApiManager::fetchSportSeats() {
    std::cout << "[ApiManager::fetchSportSeats] Fetching sport seats" << std::endl;
    Common::Request request = Common::Request::GETALL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::SportSeat::TABLE_NAME};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    std::vector<Common::SportSeat> sportSeats;
    Common::Data ids = response[Common::SportSeat::ID_KEY];
    Common::Data brands = response[Common::SportSeat::BRAND_KEY];
    Common::Data suitableFors = response[Common::SportSeat::SUITABLEFOR_KEY];
    Common::Data shellTypes = response[Common::SportSeat::SHELLTYPE_KEY];
    Common::Data shellMaterials = response[Common::SportSeat::SHELLMATERIAL_KEY];
    Common::Data coverMaterials = response[Common::SportSeat::COVERMATERIAL_KEY];
    Common::Data colors = response[Common::SportSeat::COLOR_KEY];
    Common::Data sportDescriptions = response[Common::SportSeat::DESCRIPTION_KEY];

    for(auto id : ids) {
        Common::SportSeat seat;
        seat.id = id;
        seat.brand = brands.front();
        brands.pop_front();
        seat.suitableFor = suitableFors.front();
        suitableFors.pop_front();
        seat.shellType = shellTypes.front();
        shellTypes.pop_front();
        seat.shellMaterial = shellMaterials.front();
        shellMaterials.pop_front();
        seat.coverMaterial = coverMaterials.front();
        coverMaterials.pop_front();
        seat.color = colors.front();
        colors.pop_front();
        seat.description = sportDescriptions.front();
        sportDescriptions.pop_front();

        sportSeats.push_back(seat);
    }

    emit sportSeatsFetched(sportSeats);
}

void ApiManager::fetchLuxurySeats() {
    std::cout << "[ApiManager::fetchLuxurySeats] Fetching luxury seats" << std::endl;
    Common::Request request = Common::Request::GETALL;
    Common::Dataset data;
    data[Common::TABLE_KEY] = {Common::LuxurySeat::TABLE_NAME};
    m_networkManager.sendRequest(data, request);
    Common::Dataset response = m_networkManager.readResponse();

    std::vector<Common::LuxurySeat> luxurySeats;
    Common::Data ids = response[Common::LuxurySeat::ID_KEY];
    Common::Data brands = response[Common::LuxurySeat::BRAND_KEY];
    Common::Data suitableFors = response[Common::LuxurySeat::SUITABLEFOR_KEY];
    Common::Data colors = response[Common::LuxurySeat::COLOR_KEY];
    Common::Data materials = response[Common::LuxurySeat::MATERIAL_KEY];
    Common::Data comfortLevels = response[Common::LuxurySeat::COMFORTLEVEL_KEY];
    Common::Data customDesigns = response[Common::LuxurySeat::CUSTOMDESIGN_KEY];
    Common::Data luxuryDescriptions = response[Common::LuxurySeat::DESCRIPTION_KEY];

    for(auto id : ids) {
        Common::LuxurySeat seat;
        seat.id = id;
        seat.brand = brands.front();
        brands.pop_front();
        seat.suitableFor = suitableFors.front();
        suitableFors.pop_front();
        seat.color = colors.front();
        colors.pop_front();
        seat.material = materials.front();
        materials.pop_front();
        seat.comfortLevel = comfortLevels.front();
        comfortLevels.pop_front();
        seat.customDesign = customDesigns.front();
        customDesigns.pop_front();
        seat.description = luxuryDescriptions.front();
        luxuryDescriptions.pop_front();

        luxurySeats.push_back(seat);
    }

    emit luxurySeatsFetched(luxurySeats);
}

void ApiManager::fetchPhotos() {
    // std::cout << "[ApiManager::fetchPhotos] Fetching photos" << std::endl;
    // Common::Request request = Common::Request::GETALL;
    // Common::Dataset data;
    // data[Common::TABLE_KEY] = {Common::Photos::TABLE_NAME};
    // m_networkManager.sendRequest(data, request);
    // Common::Dataset response = m_networkManager.readResponse();

    // std::cout << "[ApiManager::fetchPhotos] Response: " << response[Common::RESPONSE_KEY].front() << std::endl;
    // std::vector<Common::Photos> photos;
    // Common::Data ids = response[Common::Photos::ID_KEY];
    // Common::Data productTypes = response[Common::Photos::PRODUCTTYPE_KEY];
    // Common::Data productTypeIds = response[Common::Photos::PRODUCTTYPEID_KEY];
    // Common::Data images = response[Common::Photos::IMAGE_KEY];

    // std::cout << "[ApiManager::fetchPhotos] ids size: " << ids.size() << std::endl;
    // for(auto id : ids) {
    //     Common::Photos photo;
    //     photo.id = id;
    //     photo.productType = productTypes.front();
    //     productTypes.pop_front();
    //     photo.productTypeId = productTypeIds.front();
    //     productTypeIds.pop_front();
    //     photo.image = images.front();
    //     images.pop_front();

    //     photos.push_back(photo);
    // }

    emit photosFetched(testPhotos);
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