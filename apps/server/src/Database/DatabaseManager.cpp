#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(std::unique_ptr<ITableFactory> tableFactory) {
    dataTable = nullptr;
    if(database::create_db(dataTable)) {
            std::cerr << "Database was successfully created" << std::endl;
    }

    users = tableFactory->makeUsersTable(dataTable);
    suppliers = tableFactory->makeSuppliersTable(dataTable);
    purchaseOrders = tableFactory->makePurchaseOrdersTable(dataTable);
    products = tableFactory->makeProductsTable(dataTable);
    productInfo = tableFactory->makeProductInfoTable(dataTable);
    photos = tableFactory->makePhotosTable(dataTable);
    inventory = tableFactory->makeInventoryTable(dataTable);
}

DatabaseManager::~DatabaseManager() {}

void DatabaseManager::readRequest(Common::Request request, Common::Dataset &entity) {
    
    if(entity["TABLE:"].front() == Common::Users::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = users->getAll();
            break;
        case Common::Request::GET:
            users->get(entity);
            break;
        case Common::Request::ADD:
            if(!users->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!users->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!users->deleteAt(entity))
                std::cerr << "[UserTable::DELETE] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Suppliers::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = suppliers->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!suppliers->add(entity))
                std::cerr << "[SuppliersTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!suppliers->update(entity))
                std::cerr << "[SuppliersTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!suppliers->deleteAt(entity))
                std::cerr << "[SuppliersTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::PurchaseOrders::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = purchaseOrders->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!purchaseOrders->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!purchaseOrders->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!purchaseOrders->deleteAt(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Products::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = products->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!products->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!products->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!products->deleteAt(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::ProductInfo::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = productInfo->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!productInfo->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!productInfo->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!productInfo->deleteAt(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Photos::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = photos->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!photos->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!photos->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!photos->deleteAt(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Inventory::TABLE_NAME) {
        switch (request)
        {
        case Common::Request::GETALL:
            entity.clear();
            entity = inventory->getAll();
            break;
        case Common::Request::GET:
            suppliers->get(entity);
            break;
        case Common::Request::ADD:
            if(!inventory->add(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        case Common::Request::UPDATE:
            if(!inventory->update(entity))
                std::cerr << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Common::Request::DELETE:
            if(!inventory->deleteAt(entity))
                std::cerr << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

}