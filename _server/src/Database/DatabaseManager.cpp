#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager() {
    dataTable = nullptr;
    if(database::create_db(dataTable)) {
            std::cout << "Database was successfully created" << std::endl;
    }

    users = new UsersTable(dataTable);
    suppliers = new SuppliersTable(dataTable);
    purchaseOrders = new PurchaseOrdersTable(dataTable);
    products = new ProductsTable(dataTable);
    productInfo = new ProductInfoTable(dataTable);
    photos = new PhotosTable(dataTable);
    managers = new ManagersTable(dataTable);
    inventory = new InventoryTable(dataTable);
}

DatabaseManager::~DatabaseManager() {}

void DatabaseManager::readRequest(Request request, Common::Dataset &entity) {
    
    if(entity["TABLE:"].front() == Common::Users::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            std::cout << "[UserTable::GETALL] >> operation started\n";
            entity.clear();
            entity = users->getAll();
            break;

        case Request::GET:
            std::cout << "[UserTable::GET] >> operation started\n";
            users->get(entity);
            break;
        case Request::ADD:
            std::cout << "[UserTable::ADD] >> operation started\n";
            if(!users->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            std::cout << "[UserTable::UPDATE] >> operation started\n";
            if(!users->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            std::cout << "[UserTable::DELETE] >> operation started\n";
            if(!users->deleteAt(entity))
                std::cout << "[UserTable::DELETE] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Suppliers::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = suppliers->getAll();
            break;
        case Request::ADD:
            if(!suppliers->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!suppliers->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!suppliers->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::PurchaseOrders::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = purchaseOrders->getAll();
            break;
        case Request::ADD:
            if(!purchaseOrders->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!purchaseOrders->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!purchaseOrders->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Products::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = products->getAll();
            break;
        case Request::ADD:
            if(!products->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!products->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!products->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::ProductInfo::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = productInfo->getAll();
            break;
        case Request::ADD:
            if(!productInfo->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!productInfo->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!productInfo->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Photos::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = photos->getAll();
            break;
        case Request::ADD:
            if(!photos->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!photos->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!photos->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Managers::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = managers->getAll();
            break;
        case Request::ADD:
            if(!managers->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!managers->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!managers->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

    if(entity["TABLE:"].front() == Common::Inventory::TABLE_NAME) {
        switch (request)
        {
        case Request::GETALL:
            entity.clear();
            entity = inventory->getAll();
            break;
        case Request::ADD:
            if(!inventory->add(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        case Request::UPDATE:
            if(!inventory->update(entity))
                std::cout << "[UserTable::UPDATE] >> operation failed\n";
            break;
        case Request::DELETE:
            if(!inventory->deleteAt(entity))
                std::cout << "[UserTable::ADD] >> operation failed\n";
            break;
        default:
            break;
        }
    }

}