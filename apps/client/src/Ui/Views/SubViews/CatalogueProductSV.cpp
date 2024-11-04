#include "CatalogueProductSV.hpp"

CatalogueProductSV::CatalogueProductSV(QString &productName, QString &productPrice, QString &unitPrice, QString &discount, QString &hasDiscount, QString &imageBytes, QWidget *parent) 
: QWidget(parent) {
    m_productImage = new QImage();
    m_productImage->loadFromData(QByteArray::fromHex(imageBytes.toUtf8()));

    m_productNameLabel = new QLabel(productName);
    m_totalPriceLabel = new QLabel(productPrice);
    m_priceLabel = new QLabel("");
    m_unitPriceLabel = new QLabel(unitPrice);
    int price = productPrice.toInt();
    m_discountLabel = new QLabel("");
    if(hasDiscount == "TRUE") {
        m_discountLabel->setText("-" + discount + "%");
        m_priceLabel->setText(productPrice);
        price = productPrice.toInt() - (discount.toInt() * (productPrice.toInt() / 100));
        m_totalPriceLabel->setText(QString::number(price));
    }

    setupUI();

    connect(m_addToBusketButton, &QPushButton::clicked, this, [this]() {
        emit addToBasketClicked();
    });

    connect(m_buyButton, &QPushButton::clicked, this, [this]() {
        emit buyClicked();
    });
}

void CatalogueProductSV::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit openProductPage();
    }
    QWidget::mouseDoubleClickEvent(event);
}

void CatalogueProductSV::setupUI() {
    m_imageLabel = new QLabel();
    m_imageLabel->setFixedSize(160, 160);
    m_imageLabel->setPixmap(QPixmap::fromImage(*m_productImage).scaled(160, 160, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_imageLabel->setAlignment(Qt::AlignCenter);

    QFont m_priceFont = m_priceLabel->font();
    m_priceFont.setBold(true);
    m_priceFont.setPointSize(14);
    m_productNameLabel->setFont(m_priceFont);
    m_priceFont.setBold(false);
    m_priceFont.setPointSize(12);
    m_discountLabel->setFont(m_priceFont);
    m_totalPriceLabel->setFont(m_priceFont);
    m_unitPriceLabel->setFont(m_priceFont);
    m_priceFont.setStrikeOut(true);
    m_priceLabel->setFont(m_priceFont);

    m_spacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_addToBusketButton = new QPushButton("Add to basket");
    m_buyButton = new QPushButton("Buy");

    m_priceLineLayout = new QHBoxLayout();
    m_priceLineLayout->addWidget(m_discountLabel);
    m_priceLineLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_priceLineLayout->addWidget(m_totalPriceLabel);
    m_priceLineLayout->addWidget(m_unitPriceLabel);

    QHBoxLayout *m_priceLayout = new QHBoxLayout();
    m_priceLayout->addWidget(m_priceLabel);

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_imageLabel);
    m_layout->addSpacerItem(m_spacer);
    m_layout->addWidget(m_productNameLabel);
    m_layout->addLayout(m_priceLineLayout);
    m_layout->addLayout(m_priceLayout);
    m_layout->addWidget(m_addToBusketButton);
    m_layout->addWidget(m_buyButton);

    setLayout(m_layout);
}