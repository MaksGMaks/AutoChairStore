#pragma once

#include <string>
#include <list>
#include <unordered_map>

namespace Common {
    struct Users {
        static constexpr const char *TABLE_NAME     = "Users";
        static constexpr const char *ID_KEY         = "id";
        static constexpr const char *NAME_KEY       = "name";
        static constexpr const char *SURNAME_KEY    = "surname";
        static constexpr const char *EMAIL_KEY      = "email";
        static constexpr const char *PASSWORD_KEY   = "password";

        std::string id{};
        std::string name{};
        std::string surname{};
        std::string email{};
        std::string password{};
    };

    struct Suppliers {
        static constexpr const char *TABLE_NAME = "Suppliers";
        static constexpr const char *ID_KEY     = "id";
        static constexpr const char *NAME_KEY   = "name";
        static constexpr const char *PHONE_KEY  = "phone";
        static constexpr const char *EMAIL_KEY  = "email";

        std::string id{};
        std::string name{};
        std::string phone{};
        std::string email{};
    };

    struct ProductInfo {
        static constexpr const char *TABLE_NAME         = "ProductInfo";
        static constexpr const char *ID_KEY             = "id";
        static constexpr const char *DESCRIPTION_KEY    = "description";
        static constexpr const char *SUPPLIERID_KEY     = "supplierId";
        static constexpr const char *NAME_KEY           = "name";
        static constexpr const char *LASTPRICE_KEY      = "lastPrice";
        static constexpr const char *UNIT_KEY           = "unit";
        static constexpr const char *ISIMPORTED_KEY     = "isImported";

        std::string id{};
        std::string description{};
        std::string supplierId{};
        std::string name{};
        std::string lastPrice{};
        std::string unit{};
        std::string isImported{};
    };

    struct Photos {
        static constexpr const char *TABLE_NAME     = "Photos";
        static constexpr const char *ID_KEY         = "id";
        static constexpr const char *PRODUCTID_KEY  = "productId";
        static constexpr const char *IMAGE_KEY      = "image";

        std::string id{};
        std::string productId{};
        std::string image{};
    };

    struct Inventory {
        static constexpr const char *TABLE_NAME         = "Inventory";
        static constexpr const char *ID_KEY             = "id";
        static constexpr const char *PRODUCTINFOID_KEY  = "productInfoId";
        static constexpr const char *QUANTITY_KEY       = "quantity";
        static constexpr const char *ISREADYTOSELL_KEY  = "isReadyToSell";

        std::string id{};
        std::string productInfoId{};
        std::string quantity{};
        std::string idReadyToSell{};
    };

    struct Products {
        static constexpr const char *TABLE_NAME         = "Products";
        static constexpr const char *ID_KEY             = "id";
        static constexpr const char *INVENTORYID_KEY    = "inventoryId";
        static constexpr const char *HASDISCOUNT_KEY    = "hasDiscount";
        static constexpr const char *DISCOUNT_KEY       = "discount";

        std::string id{};
        std::string inventoryId{};
        std::string hasDiscount{};
        std::string discount{};
    };

    struct PurchaseOrders {
        static constexpr const char *TABLE_NAME = "PurchaseOrders";
        static constexpr const char *ID_KEY     = "id";
        static constexpr const char *USERID_KEY   = "userId";
        static constexpr const char *PRODUCTINFOID_KEY   = "productionInfoId";
        static constexpr const char *ISPREPAID_KEY  = "isPrePaid";
        static constexpr const char *ISFULLPAID_KEY  = "isFullPaid";
        static constexpr const char *SHOULDPAID_KEY     = "shouldPaid";
        static constexpr const char *DESTINATION_KEY   = "destination";
        static constexpr const char *PACKAGEID_KEY   = "packageId";
        static constexpr const char *DELIVERYDATE_KEY  = "deliveryDate";

        std::string id{};
        std::string userId{};
        std::string productionInfoId{};
        std::string isPrePaid{};
        std::string isFullPaid{};
        std::string shouldPaid{};
        std::string destination{};
        std::string packageId{};
        std::string deliveryDate{};
    };
    
    using Data    = std::list<std::string>;
    using Dataset = std::unordered_map<std::string, Data>;   

    enum class Request {
    GET = 0,
    ADD = 1,
    DELETE = 2,
    UPDATE = 3,
    GETALL = 4
};

}