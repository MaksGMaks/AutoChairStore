#pragma once

#include <string>
#include <list>
#include <unordered_map>

namespace Common {
    static constexpr const char *COLUMN_KEY = "COLUMNS";
    static constexpr const char *TABLE_KEY = "TABLE:";
    static constexpr const char *REQUEST_KEY = "REQUEST:";
    static constexpr const char *RESPONSE_KEY = "RESPONSE:";
    static constexpr const char *SUCCESS = "SUCCESS";
    static constexpr const char *FAILURE = "FAILURE";

    struct Users {
        static constexpr const char *TABLE_NAME             = "Users";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *NAME_KEY               = "name";
        static constexpr const char *SURNAME_KEY            = "surname";
        static constexpr const char *EMAIL_KEY              = "email";
        static constexpr const char *PASSWORD_KEY           = "password";

        std::string id{};
        std::string name{};
        std::string surname{};
        std::string email{};
        std::string password{};

        bool operator==(const Users &rhs) const {
            return id == rhs.id && name == rhs.name && surname == rhs.surname && email == rhs.email && password == rhs.password;
        }
    };

    struct BaseSeat {
        static constexpr const char *TABLE_NAME             = "BaseSeat";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *BRAND_KEY              = "brand";
        static constexpr const char *SUITABLEFOR_KEY        = "suitableFor";
        static constexpr const char *COLOR_KEY              = "color";
        static constexpr const char *MATERIAL_KEY           = "material";
        static constexpr const char *TYPE_KEY               = "type";
        static constexpr const char *DESCRIPTION_KEY        = "description";

        std::string id{};
        std::string brand{};
        std::string suitableFor{};
        std::string color{};
        std::string material{};
        std::string type{};
        std::string description{};

        bool operator==(const BaseSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && color == rhs.color && material == rhs.material && 
                   type == rhs.type && description == rhs.description;
        }
    };

    struct ChildSeat {
        static constexpr const char *TABLE_NAME             = "ChildSeat";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *BRAND_KEY              = "brand";
        static constexpr const char *AGE_KEY                = "age";
        static constexpr const char *WEIGHT_KEY             = "weight";
        static constexpr const char *HEIGHT_KEY             = "height";
        static constexpr const char *SAFETYKEY_KEY          = "safetyKey";
        static constexpr const char *FASTENING_KEY          = "fastening";
        static constexpr const char *DRIVEWAY_KEY           = "driveway";
        static constexpr const char *DESCRIPTION_KEY        = "description";

        std::string id{};
        std::string brand{};
        std::string age{};
        std::string weight{};
        std::string height{};
        std::string safetyKey{};
        std::string fastening{};
        std::string driveway{};
        std::string description{};

        bool operator==(const ChildSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && age == rhs.age && weight == rhs.weight && height == rhs.height && safetyKey == rhs.safetyKey && 
                   fastening == rhs.fastening && driveway == rhs.driveway && description == rhs.description;
        }
    };

    struct SportSeat {
        static constexpr const char *TABLE_NAME             = "SportSeat";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *BRAND_KEY              = "brand";
        static constexpr const char *SUITABLEFOR_KEY        = "suitableFor";
        static constexpr const char *SHELLTYPE_KEY          = "shellType";     
        static constexpr const char *SHELLMATERIAL_KEY      = "shellMaterial";
        static constexpr const char *COVERMATERIAL_KEY      = "coverMaterial";
        static constexpr const char *COLOR_KEY              = "color";
        static constexpr const char *DESCRIPTION_KEY        = "description";

        std::string id{};
        std::string brand{};
        std::string suitableFor{};
        std::string shellType{};
        std::string shellMaterial{};
        std::string coverMaterial{};
        std::string color{};
        std::string description{};

        bool operator==(const SportSeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && shellType == rhs.shellType && shellMaterial == rhs.shellMaterial && 
                   coverMaterial == rhs.coverMaterial && color == rhs.color && description == rhs.description;
        }        
    };

    struct LuxurySeat {
        static constexpr const char *TABLE_NAME             = "LuxurySeat";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *BRAND_KEY              = "brand";
        static constexpr const char *SUITABLEFOR_KEY        = "suitableFor";
        static constexpr const char *COLOR_KEY              = "color";
        static constexpr const char *MATERIAL_KEY           = "material";
        static constexpr const char *COMFORTLEVEL_KEY       = "comfortLevel";
        static constexpr const char *CUSTOMDESIGN_KEY       = "customDesign";
        static constexpr const char *DESCRIPTION_KEY        = "description";

        std::string id{};
        std::string brand{};
        std::string suitableFor{};
        std::string color{};
        std::string material{};
        std::string comfortLevel{};
        std::string customDesign{};
        std::string description{};

        bool operator==(const LuxurySeat &rhs) const {
            return id == rhs.id && brand == rhs.brand && suitableFor == rhs.suitableFor && color == rhs.color && material == rhs.material && 
                   comfortLevel == rhs.comfortLevel && customDesign == rhs.customDesign && description == rhs.description;
        }    
    };

    struct Photos {
        static constexpr const char *TABLE_NAME             = "Photos";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *PRODUCTTYPE_KEY        = "productType";
        static constexpr const char *PRODUCTTYPEID_KEY      = "productTypeId";
        static constexpr const char *IMAGE_KEY              = "image";

        std::string id{};
        std::string productType{};
        std::string productTypeId{};        
        std::string image{};

        bool operator==(const Photos &rhs) const {
            return id == rhs.id && productType == rhs.productType && productTypeId == rhs.productTypeId && image == rhs.image;
        }
    };

    struct Products {
        static constexpr const char *TABLE_NAME             = "Products";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *PRODUCTNAME_KEY        = "productName";
        static constexpr const char *PRODUCTTYPE_KEY        = "productType";
        static constexpr const char *PRODUCTTYPEID_KEY      = "productTypeId";
        static constexpr const char *PRICE_KEY              = "price";
        static constexpr const char *PRICEUNIT_KEY          = "priceUnit";
        static constexpr const char *QUANTITY_KEY           = "quantity";
        static constexpr const char *HASDISCOUNT_KEY        = "hasDiscount";
        static constexpr const char *DISCOUNT_KEY           = "discount";
        static constexpr const char *ISREADYTOSELL_KEY      = "isReadyToSell";

        std::string id{};
        std::string productName{};
        std::string productType{};
        std::string productTypeId{};
        std::string price{};
        std::string priceUnit{};
        std::string quantity{};
        std::string hasDiscount{};
        std::string discount{};
        std::string isReadyToSell{};

        bool operator==(const Products &rhs) const {
            return id == rhs.id && productName == rhs.productName && productType == rhs.productType && productTypeId == rhs.productTypeId && 
                   price == rhs.price && priceUnit == rhs.priceUnit && quantity == rhs.quantity && hasDiscount == rhs.hasDiscount && 
                   discount == rhs.discount && isReadyToSell == rhs.isReadyToSell;    
        }
    };

    struct PurchaseOrders {
        static constexpr const char *TABLE_NAME             = "PurchaseOrders";
        static constexpr const char *ID_KEY                 = "id";
        static constexpr const char *USERID_KEY             = "userId";
        static constexpr const char *PRODUCTID_KEY          = "productId";
        static constexpr const char *PAIDTYPE_KEY           = "paidType";
        static constexpr const char *DELIVERYTYPE_KEY       = "deliveryType";
        static constexpr const char *DESTINATION_KEY        = "destination";
        static constexpr const char *PACKAGEID_KEY          = "packageId";
        static constexpr const char *DELIVERYDATE_KEY       = "deliveryDate";
        static constexpr const char *STATUS_KEY             = "status";

        std::string id{};
        std::string userId{};
        std::string productId{};
        std::string paidType{};
        std::string deliveryType{};
        std::string destination{};
        std::string packageId{};
        std::string deliveryDate{};
        std::string status{};

        bool operator==(const PurchaseOrders &rhs) const {
            return id == rhs.id && userId == rhs.userId && productId == rhs.productId && paidType == rhs.paidType && 
                   destination == rhs.destination && packageId == rhs.packageId && deliveryDate == rhs.deliveryDate && status == rhs.status;
        }

    };
    
    struct Verification {
        static constexpr const char *TABLE_NAME         = "verification_codes";
        static constexpr const char *EMAIL_KEY          = "email";
        static constexpr const char *CODE_KEY           = "code";
        static constexpr const char *CREATEDAT_KEY      = "created_at";

        std::string email{};
        std::string code{};
        std::string createdAt{};

        bool operator==(const Verification &rhs) const {
            return email == rhs.email && code == rhs.code && createdAt == rhs.createdAt;
        }
    };
    
    typedef std::list<std::string> Data;
    typedef std::unordered_map<std::string, Data> Dataset;

    enum class Request {
        GET = 0,
        ADD = 1,
        DELETE = 2,
        UPDATE = 3,
        GETALL = 4,
        GETSPECIAL = 5,
        SENDCODE = 6
    };

}