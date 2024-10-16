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
        
    };
    
} // namespace display_data