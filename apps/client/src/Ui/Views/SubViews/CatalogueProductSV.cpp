#include "CatalogueProductSV.hpp"

CatalogueProductSV::CatalogueProductSV(QString &productName, QString &productPrice, QString &unitPrice, QString &imageBytes, QWidget *parent) 
    : QWidget(parent) {
    m_productImage = new QImage();
    m_productImage->loadFromData(QByteArray::fromHex(imageBytes.toUtf8()));

    m_productNameLabel = new QLabel(productName);
    m_productPriceLabel = new QLabel(productPrice);
    m_unitPriceLabel = new QLabel(unitPrice);

    setupUI();
}

void CatalogueProductSV::setupUI() {
    m_imageLabel = new QLabel();
    m_imageLabel->setFixedSize(180, 180);
    m_imageLabel->setPixmap(QPixmap::fromImage(*m_productImage).scaled(180, 180, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    m_addToBusketButton = new QPushButton("Add to basket");
    m_buyButton = new QPushButton("Buy");

    m_priceLineLayout = new QHBoxLayout();
    m_priceLineLayout->addWidget(m_productPriceLabel);
    m_priceLineLayout->addWidget(m_unitPriceLabel);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_imageLabel);
    m_layout->addWidget(m_productNameLabel);
    m_layout->addLayout(m_priceLineLayout);
    m_layout->addWidget(m_addToBusketButton);
    m_layout->addWidget(m_buyButton);

    setLayout(m_layout);
}