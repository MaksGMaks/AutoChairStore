#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(TableFactory &tableFactory) {
    dataTable = nullptr;
    if(database::create_db(dataTable)) {
            std::cerr << "Database was successfully created" << std::endl;
    }

    users = tableFactory.makeUsersTable(dataTable);
    purchaseOrders = tableFactory.makePurchaseOrdersTable(dataTable);
    products = tableFactory.makeProductsTable(dataTable);
    photos = tableFactory.makePhotosTable(dataTable);
    baseSeats = tableFactory.makeBaseSeatTable(dataTable);
    childSeats = tableFactory.makeChildSeatTable(dataTable);
    luxurySeats = tableFactory.makeLuxurySeatTable(dataTable);
    sportSeats = tableFactory.makeSportSeatTable(dataTable);

    runTests();
}

void DatabaseManager::readRequest(Common::Request request, Common::Dataset &entity) {
    std::cout << "[DatabaseManager::readRequest] reading request" << std::endl;
    if(entity[Common::TABLE_KEY].front() == Common::Users::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all users" << std::endl;
            entity.clear();
            entity = users->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting user" << std::endl;
            users->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting user special" << std::endl;
            users->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding user" << std::endl;
            if(!users->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating user" << std::endl;
            if(!users->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting user" << std::endl;
            if(!users->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::PurchaseOrders::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all purchase orders" << std::endl;
            entity.clear();
            entity = purchaseOrders->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting purchase order" << std::endl;
            purchaseOrders->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting purchase order special" << std::endl;
            purchaseOrders->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding purchase order" << std::endl;
            if(!purchaseOrders->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating purchase order" << std::endl;
            if(!purchaseOrders->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting purchase order" << std::endl;
            if(!purchaseOrders->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::Products::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all products" << std::endl;
            entity.clear();
            entity = products->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting product" << std::endl;
            products->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting product special" << std::endl;
            products->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding product" << std::endl;
            if(!products->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating product" << std::endl;
            if(!products->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting product" << std::endl;
            if(!products->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::Photos::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all photos" << std::endl;
            entity.clear();
            entity = photos->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting photo" << std::endl;
            photos->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting photo special" << std::endl;
            photos->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding photo" << std::endl;
            if(!photos->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating photo" << std::endl;
            if(!photos->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting photo" << std::endl;
            if(!photos->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::BaseSeat::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all base seats" << std::endl;
            entity.clear();
            entity = baseSeats->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting base seat" << std::endl;
            baseSeats->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting base seat special" << std::endl;
            baseSeats->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding base seat" << std::endl;
            if(!baseSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating base seat" << std::endl;
            if(!baseSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting base seat" << std::endl;
            if(!baseSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::ChildSeat::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all child seats" << std::endl;
            entity.clear();
            entity = childSeats->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting child seat" << std::endl;
            childSeats->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting child seat special" << std::endl;
            childSeats->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding child seat" << std::endl;
            if(!childSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating child seat" << std::endl;
            if(!childSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting child seat" << std::endl;
            if(!childSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::LuxurySeat::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all luxury seats" << std::endl;
            entity.clear();
            entity = luxurySeats->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting luxury seat" << std::endl;
            luxurySeats->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting luxury seat special" << std::endl;
            luxurySeats->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding luxury seat" << std::endl;
            if(!luxurySeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating luxury seat" << std::endl;
            if(!luxurySeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting luxury seat" << std::endl;
            if(!luxurySeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

    if(entity[Common::TABLE_KEY].front() == Common::SportSeat::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            std::cout << "[DatabaseManager::readRequest] Getting all sport seats" << std::endl;
            entity.clear();
            entity = sportSeats->getAll();
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GET:
            std::cout << "[DatabaseManager::readRequest] Getting sport seat" << std::endl;
            sportSeats->get(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::GETSPECIAL:
            std::cout << "[DatabaseManager::readRequest] Getting sport seat special" << std::endl;
            sportSeats->getColumns(entity);
            if(entity.empty()) {
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::ADD:
            std::cout << "[DatabaseManager::readRequest] Adding sport seat" << std::endl;
            if(!sportSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::UPDATE:
            std::cout << "[DatabaseManager::readRequest] Updating sport seat" << std::endl;
            if(!sportSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        case Common::Request::DELETE:
            std::cout << "[DatabaseManager::readRequest] Deleting sport seat" << std::endl;
            if(!sportSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::FAILURE};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {Common::SUCCESS};
            }
            break;
        default:
            break;
        }
    }

}

void DatabaseManager::runTests() {
    database::Tests tests;
    
    for(auto test : tests.userEntities) {
        readRequest(tests.userEntityRequest, test);
    }

    for(auto test : tests.orderEntities) {
        readRequest(tests.orderEntityRequest, test);
    }

    for(auto test : tests.productEntities) {
        readRequest(tests.productEntityRequest, test);
    }

    for(auto test : tests.baseSeatEntities) {
        readRequest(tests.baseSeatEntityRequest, test);
    }

    for(auto test : tests.childSeatEntities) {
        readRequest(tests.childSeatEntityRequest, test);
    }

    for(auto test : tests.sportSeatEntities) {
        readRequest(tests.sportSeatEntityRequest, test);
    }

    for(auto test : tests.luxurySeatEntities) {
        readRequest(tests.luxurySeatEntityRequest, test);
    }

    for(auto test : tests.photoEntities) {
        readRequest(tests.photoEntityRequest, test);
    }
}