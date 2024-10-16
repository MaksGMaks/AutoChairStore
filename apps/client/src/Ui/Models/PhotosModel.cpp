#include "PhotosModel.hpp"

PhotosModel::PhotosModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    
}

QVector<Common::Photos> PhotosModel::photos() const {
    return m_photos;
}