#pragma once

#include "Ui/Models/IModel.hpp"
#include "Ui/Models/PhotosModel.hpp"
#include "Ui/Models/ProductsModel.hpp"
#include "Ui/Models/PurchaseOrdersModel.hpp"
#include "Ui/Models/UsersModel.hpp"

class IModelFactory
{
public:
    virtual ~IModelFactory() = default;

    virtual PhotosModel *getPhotosModel(QObject *parent = nullptr) = 0;
    virtual ProductsModel *getProductsModel(QObject *parent = nullptr) = 0;
    virtual PurchaseOrdersModel *getPurchaseOrdersModel(QObject *parent = nullptr) = 0;
    virtual UsersModel *getUserModel(QObject *parent = nullptr) = 0;
};