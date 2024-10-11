#pragma once

#include "IModel.hpp"
#include "Network/ApiManager.hpp"

class PhotosModel : public IModel {
    Q_OBJECT
public:
    explicit PhotosModel(ApiManager &apiManager, QObject *parent = nullptr);
    virtual ~PhotosModel() = default;

    QVector<Common::Photos> photos() const;

private:
    ApiManager &m_apiManager;
    QVector<Common::Photos> m_photos;
};