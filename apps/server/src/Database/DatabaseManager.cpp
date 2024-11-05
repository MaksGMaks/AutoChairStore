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
}

DatabaseManager::~DatabaseManager() {}

void DatabaseManager::readRequest(Common::Request request, Common::Dataset &entity) {
    std::cout << "[DatabaseManager::readRequest] reading request" << std::endl;
    if(entity[Common::TABLE_KEY].front() == Common::Users::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = users->getAll();
            break;
        case Common::Request::GET:
            users->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            users->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!users->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!users->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!users->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = purchaseOrders->getAll();
            break;
        case Common::Request::GET:
            purchaseOrders->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            purchaseOrders->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!purchaseOrders->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!purchaseOrders->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!purchaseOrders->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = products->getAll();
            break;
        case Common::Request::GET:
            products->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            products->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!products->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!products->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!products->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = photos->getAll();
            break;
        case Common::Request::GET:
            photos->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            photos->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!photos->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!photos->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!photos->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = baseSeats->getAll();
            break;
        case Common::Request::GET:
            baseSeats->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            baseSeats->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!baseSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!baseSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!baseSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = childSeats->getAll();
            break;
        case Common::Request::GET:
            childSeats->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            childSeats->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!childSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!childSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!childSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = luxurySeats->getAll();
            break;
        case Common::Request::GET:
            luxurySeats->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            luxurySeats->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!luxurySeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!luxurySeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!luxurySeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
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
            entity.clear();
            entity = sportSeats->getAll();
            break;
        case Common::Request::GET:
            sportSeats->get(entity);
            break;
        case Common::Request::GETSPECIAL:
            sportSeats->getColumns(entity);
            break;
        case Common::Request::ADD:
            if(!sportSeats->add(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::UPDATE:
            if(!sportSeats->update(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        case Common::Request::DELETE:
            if(!sportSeats->deleteAt(entity)) {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Error"};
            } else {
                entity.clear();
                entity[Common::RESPONSE_KEY] = {"Done"};
            }
            break;
        default:
            break;
        }
    }

}