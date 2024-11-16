#pragma once

#include "DatabaseManager.hpp"
#include "TEST_PHOTOS.hpp"

namespace database {

    class Tests {
    public:
        Tests();
        ~Tests() = default;
        
        std::string testCode;
        std::vector<std::string> testEmails;

        std::vector<Common::Photos> testPhotos;

        std::vector<Common::Dataset> userEntities;
        Common::Request userEntityRequest;

        std::vector<Common::Dataset> productEntities;
        Common::Request productEntityRequest;

        std::vector<Common::Dataset> orderEntities;
        Common::Request orderEntityRequest;

        std::vector<Common::Dataset> baseSeatEntities;
        Common::Request baseSeatEntityRequest;

        std::vector<Common::Dataset> childSeatEntities;
        Common::Request childSeatEntityRequest;

        std::vector<Common::Dataset> sportSeatEntities;
        Common::Request sportSeatEntityRequest;

        std::vector<Common::Dataset> luxurySeatEntities;
        Common::Request luxurySeatEntityRequest;

        std::vector<Common::Dataset> photoEntities;
        Common::Request photoEntityRequest;
        
    private:
        void setTests();
    };
};