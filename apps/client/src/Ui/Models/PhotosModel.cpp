#include "PhotosModel.hpp"

PhotosModel::PhotosModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    connect(&m_apiManager, &ApiManager::photosFetched, this, &PhotosModel::onPhotosFetched);
    connect(&apiManager, &ApiManager::photosError, this, &PhotosModel::onError);
}

std::vector<Common::Photos> PhotosModel::photos() const {
    return m_photos;
}

void PhotosModel::fetchPhotos() {
    m_apiManager.fetchPhotos();
}

void PhotosModel::onPhotosFetched(const std::vector<Common::Photos> &photos) {
    m_photos = photos;
}

void PhotosModel::onError(const std::string &errorMessage) {
    emit photosError(errorMessage);
}

std::string PhotosModel::getPhotoById(const std::string &type, const std::string &id) const {
    for(const auto &photo : m_photos) {
        if(photo.productTypeId == id && photo.productType == type) {
            return photo.image;
        }
    }
    
    return "";
}