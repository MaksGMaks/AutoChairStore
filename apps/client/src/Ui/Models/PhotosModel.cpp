#include "PhotosModel.hpp"

PhotosModel::PhotosModel(ApiManager &apiManager, QObject *parent)
: IModel(parent), 
m_apiManager(apiManager) {
    
}

std::vector<Common::Photos> PhotosModel::photos() const {
    return m_photos;
}

std::string PhotosModel::getPhotoById(const std::string &id) const {
    for(const auto &photo : m_photos) {
        if(photo.productTypeId == id) {
            return photo.image;
        }
    }
    
    return "";
}