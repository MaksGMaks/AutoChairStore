#pragma once
#include <QString>
#include <string>

namespace displayData {
    struct Users {
        QString id{};
        QString name{};
        QString surname{};
        QString email{};
        QString password{};
    };
    
    struct Products {
        QString id{};
        QString name{};
        QString photo{};
        QString price{};
        QString priceUnit{};

        bool operator==(const Products &rhs) const {
            return id == rhs.id && name == rhs.name && photo == rhs.photo && price == rhs.price && priceUnit == rhs.priceUnit;
        }
    };

    struct PurchaseOrder {
        QString id{};
        QString userId{};
        QString packageId{};
        QString productId{};
        QString productName{};
        QString paidType{};
        QString date{};
        QString destination{};
        QString status{};

        bool operator==(const PurchaseOrder &rhs) const {
            return id == rhs.id && userId == rhs.userId && packageId == rhs.packageId && productId == rhs.productId && 
                   productName == rhs.productName && paidType == rhs.paidType && date == rhs.date && destination == rhs.destination && status == rhs.status;
        }
    };

    struct BaseSeat {
        QString id{};
        QString image{};
        QString brand{};
        QString suitableFor{};
        QString color{};
        QString material{};
        QString type{};
        QString description{};

        bool operator==(const BaseSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && color == rhs.color && material == rhs.material && 
                   type == rhs.type && description == rhs.description;
        }
    };

    struct ChildSeat {
        QString id{};
        QString image{};
        QString brand{};
        QString age{};
        QString weight{};
        QString height{};
        QString safetyKey{};
        QString fastening{};
        QString driveway{};
        QString description{};

        bool operator==(const ChildSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && age == rhs.age && weight == rhs.weight && height == rhs.height && safetyKey == rhs.safetyKey && 
                   fastening == rhs.fastening && driveway == rhs.driveway && description == rhs.description;
        }
    };

    struct SportSeat {
        QString id{};
        QString image{};
        QString brand{};
        QString suitableFor{};
        QString shellType{};
        QString shellMaterial{};
        QString coverMaterial{};
        QString color{};
        QString description{};

        bool operator==(const SportSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && shellType == rhs.shellType && shellMaterial == rhs.shellMaterial && 
                   coverMaterial == rhs.coverMaterial && color == rhs.color && description == rhs.description;
        }
    };

    struct LuxurySeat {
        QString id{};
        QString image{};
        QString brand{};
        QString suitableFor{};
        QString color{};
        QString material{};
        QString comfortLevel{};
        QString customDesign{};
        QString description{};

        bool operator==(const LuxurySeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && color == rhs.color && material == rhs.material && 
                   comfortLevel == rhs.comfortLevel && customDesign == rhs.customDesign && description == rhs.description;
        }
    };


    
} // namespace display_data