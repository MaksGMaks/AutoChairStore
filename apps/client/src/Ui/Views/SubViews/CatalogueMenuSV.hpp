#pragma once

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class CatalogueMenuSV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueMenuSV(QWidget *parent = nullptr);
    ~CatalogueMenuSV() = default;

signals:
    void openBaseSeats();
    void openChildSeats();
    void openSportSeats();
    void openLuxurySeats();

private:
    void setupUI();
    void setupConnections();

    // Buttons
    QPushButton *m_baseSeatsButton;
    QPushButton *m_childSeatsBusketButton;
    QPushButton *m_sportSeatsButton;
    QPushButton *m_luxureSeatsButton;

    // Layout
    QHBoxLayout *m_layout;

};
