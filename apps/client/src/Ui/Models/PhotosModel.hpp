#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class PhotosModel : public IModel {
    Q_OBJECT
public:
    explicit PhotosModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~PhotosModel() = default;

    std::vector<Common::Photos> photos() const;

    std::string getPhotoById(const std::string &type, const std::string &id) const;
    void fetchPhotos();

signals:
    void photosError(const std::string &errorMessage);

private slots:
    void onPhotosFetched(const std::vector<Common::Photos> &photos);
    void onError(const std::string &errorMessage);


private:
    ApiManager &m_apiManager;
    std::vector<Common::Photos> m_photos;
};