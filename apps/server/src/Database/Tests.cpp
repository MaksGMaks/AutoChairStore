#include "Tests.hpp"

namespace database {

    Tests::Tests() {
        setTests();
    }

    void Tests::setTests() {
        test::test_photos utils;

        Common::Dataset userEntity;
        userEntity[Common::TABLE_KEY] = {Common::Users::TABLE_NAME};
        userEntity[Common::Users::NAME_KEY] = {"Max"};
        userEntity[Common::Users::SURNAME_KEY] = {"Kozak"};
        userEntity[Common::Users::EMAIL_KEY] = {"test1@gmail.com"};
        userEntity[Common::Users::PASSWORD_KEY] = {"12345678"};

        userEntityRequest = Common::Request::ADD;

        userEntities.push_back(userEntity);

        testCode = "12345678";
        testEmails = {"test1@gmail.com"};

        for(int i = 0; i < 20; i++) {
            Common::Dataset productEntity;
            productEntity[Common::TABLE_KEY] = {Common::Products::TABLE_NAME};
            productEntity[Common::Products::PRODUCTNAME_KEY].push_back("Product " + std::to_string(i));
            productEntity[Common::Products::PRODUCTTYPE_KEY].push_back((i < 5) ? "1" : (i < 10) ? "2" : (i < 15) ? "3" : "4");
            productEntity[Common::Products::PRODUCTTYPEID_KEY].push_back(std::to_string(i % 5));
            productEntity[Common::Products::PRICE_KEY].push_back(std::to_string(20000 + (i * 1000)));
            productEntity[Common::Products::PRICEUNIT_KEY].push_back("грн");
            productEntity[Common::Products::QUANTITY_KEY].push_back("10");
            productEntity[Common::Products::HASDISCOUNT_KEY].push_back((i % 2 == 0) ? "TRUE" : "FALSE");
            productEntity[Common::Products::DISCOUNT_KEY].push_back("50");
            productEntity[Common::Products::ISREADYTOSELL_KEY].push_back("TRUE");

            productEntities.push_back(productEntity);
        }

        productEntityRequest = Common::Request::ADD;

        Common::Dataset orderEntity;
        orderEntity[Common::TABLE_KEY] = {Common::PurchaseOrders::TABLE_NAME};
        orderEntity[Common::PurchaseOrders::USERID_KEY] = {"1"};
        orderEntity[Common::PurchaseOrders::PRODUCTID_KEY] = {"1"};
        orderEntity[Common::PurchaseOrders::PAIDTYPE_KEY] = {"Card"};
        orderEntity[Common::PurchaseOrders::DESTINATION_KEY] = {"City, Street, House"};
        orderEntity[Common::PurchaseOrders::PACKAGEID_KEY] = {"99 9999 9999 9999"};
        orderEntity[Common::PurchaseOrders::DELIVERYDATE_KEY] = {"2021-12-12"};
        orderEntity[Common::PurchaseOrders::STATUS_KEY] = {"Delivered"};

        orderEntities.push_back(orderEntity);

        orderEntityRequest = Common::Request::ADD;

        
        for(int i = 0; i < 5; i++) {
            Common::Dataset baseSeatEntity;
            baseSeatEntity[Common::TABLE_KEY] = {Common::BaseSeat::TABLE_NAME};
            baseSeatEntity[Common::BaseSeat::BRAND_KEY].push_back("Brand " + std::to_string(i));
            baseSeatEntity[Common::BaseSeat::SUITABLEFOR_KEY].push_back("Suitable for " + std::to_string(i));
            baseSeatEntity[Common::BaseSeat::COLOR_KEY].push_back("Color " + std::to_string(i));
            baseSeatEntity[Common::BaseSeat::MATERIAL_KEY].push_back("Material " + std::to_string(i));
            baseSeatEntity[Common::BaseSeat::TYPE_KEY].push_back("Type " + std::to_string(i));
            baseSeatEntity[Common::BaseSeat::DESCRIPTION_KEY].push_back("Description " + std::to_string(i));

            baseSeatEntities.push_back(baseSeatEntity);
        }

        baseSeatEntityRequest = Common::Request::ADD;

        for(int i = 0; i < 5; i++) {
            Common::Dataset childSeatEntity;
            childSeatEntity[Common::TABLE_KEY] = {Common::ChildSeat::TABLE_NAME};
            childSeatEntity[Common::ChildSeat::BRAND_KEY].push_back("Brand " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::AGE_KEY].push_back("Age " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::WEIGHT_KEY].push_back("Weight " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::HEIGHT_KEY].push_back("Height " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::SAFETYKEY_KEY].push_back("Safety key " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::FASTENING_KEY].push_back("Fastening " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::DRIVEWAY_KEY].push_back("Driveway " + std::to_string(i));
            childSeatEntity[Common::ChildSeat::DESCRIPTION_KEY].push_back("Description " + std::to_string(i));

            childSeatEntities.push_back(childSeatEntity);
        }

        childSeatEntityRequest = Common::Request::ADD;

        for(int i = 0; i < 5; i++) {
            Common::Dataset sportSeatEntity;
            sportSeatEntity[Common::TABLE_KEY] = {Common::SportSeat::TABLE_NAME};
            sportSeatEntity[Common::SportSeat::BRAND_KEY].push_back("Brand " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::SUITABLEFOR_KEY].push_back("Suitable for " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::SHELLTYPE_KEY].push_back("Shell type " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::SHELLMATERIAL_KEY].push_back("Shell material " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::COVERMATERIAL_KEY].push_back("Cover material " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::COLOR_KEY].push_back("Color " + std::to_string(i));
            sportSeatEntity[Common::SportSeat::DESCRIPTION_KEY].push_back("Description " + std::to_string(i));

            sportSeatEntities.push_back(sportSeatEntity);
        }

        sportSeatEntityRequest = Common::Request::ADD;

        for(int i = 0; i < 5; i++) {
            Common::Dataset luxurySeatEntity;
            luxurySeatEntity[Common::TABLE_KEY] = {Common::LuxurySeat::TABLE_NAME};
            luxurySeatEntity[Common::LuxurySeat::BRAND_KEY].push_back("Brand " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::SUITABLEFOR_KEY].push_back("Suitable for " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::COLOR_KEY].push_back("Color " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::MATERIAL_KEY].push_back("Material " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::COMFORTLEVEL_KEY].push_back("Comfort level " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::CUSTOMDESIGN_KEY].push_back("Custom design " + std::to_string(i));
            luxurySeatEntity[Common::LuxurySeat::DESCRIPTION_KEY].push_back("Description " + std::to_string(i));
        }

        luxurySeatEntityRequest = Common::Request::ADD;

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

        for(auto &photo : testPhotos) {
            Common::Dataset photoEntity;
            photoEntity[Common::TABLE_KEY] = {Common::Photos::TABLE_NAME};
            photoEntity[Common::Photos::ID_KEY].push_back(photo.id);
            photoEntity[Common::Photos::PRODUCTTYPE_KEY].push_back(photo.productType);
            photoEntity[Common::Photos::PRODUCTTYPEID_KEY].push_back(photo.productTypeId);
            photoEntity[Common::Photos::IMAGE_KEY].push_back(photo.image);

            photoEntities.push_back(photoEntity);
        }

        photoEntityRequest = Common::Request::ADD;
    }
};