#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class PhotosModel : public IModel {
    Q_OBJECT
public:
    explicit PhotosModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~PhotosModel() = default;

    std::vector<Common::Photos> photos() const;

    std::string getPhotoById(const std::string &id) const;

private:
    ApiManager &m_apiManager;
    std::vector<Common::Photos> m_photos;
};