#pragma once

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class CatalogueMenuSV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueMenuSV(QWidget *parent = nullptr);
    virtual ~CatalogueMenuSV() = default;

private:
    void setupUI();

    // Buttons
    QPushButton *m_baseSeatsButton;
    QPushButton *m_childSeatsBusketButton;
    QPushButton *m_sportSeatsButton;
    QPushButton *m_bucketSeatsButton;
    QPushButton *m_luxureSeatsButton;

    // Layout
    QHBoxLayout *m_layout;

};
