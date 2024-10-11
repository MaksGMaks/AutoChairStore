#pragma once

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CatalogueProductSV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueProductSV(QString &productName, QString &productPrice, QString &unitPrice, QString &imageBytes, QWidget *parent = nullptr);
    virtual ~CatalogueProductSV() = default;

    
private:
    void setupUI();

    // Buttons
    QPushButton *m_addToBusketButton;
    QPushButton *m_buyButton;

    // Labels
    QLabel *m_imageLabel;
    QLabel *m_productNameLabel;
    QLabel *m_productPriceLabel;
    QLabel *m_unitPriceLabel;

    // Image
    QImage *m_productImage;

    // Layout
    QHBoxLayout *m_priceLineLayout;
    QVBoxLayout *m_layout;

};
