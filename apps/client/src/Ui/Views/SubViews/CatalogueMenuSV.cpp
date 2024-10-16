#include "CatalogueMenuSV.hpp"

CatalogueMenuSV::CatalogueMenuSV(QWidget *parent) 
: QWidget(parent) {
    setupUI();
}

void CatalogueMenuSV::setupUI() {
    m_baseSeatsButton = new QPushButton("Base Seats");
    m_childSeatsBusketButton = new QPushButton("Child Seats");
    m_sportSeatsButton = new QPushButton("Sport Seats");
    m_bucketSeatsButton = new QPushButton("Bucket Seats");
    m_luxureSeatsButton = new QPushButton("Luxure Seats");

    m_baseSeatsButton->setFixedSize(200, 40);
    m_childSeatsBusketButton->setFixedSize(200, 40);
    m_sportSeatsButton->setFixedSize(200, 40);
    m_bucketSeatsButton->setFixedSize(200, 40);
    m_luxureSeatsButton->setFixedSize(200, 40);

    m_layout = new QHBoxLayout();
    
    m_layout->addWidget(m_baseSeatsButton);
    m_layout->addWidget(m_childSeatsBusketButton);
    m_layout->addWidget(m_sportSeatsButton);
    m_layout->addWidget(m_bucketSeatsButton);
    m_layout->addWidget(m_luxureSeatsButton);

    setLayout(m_layout);
}