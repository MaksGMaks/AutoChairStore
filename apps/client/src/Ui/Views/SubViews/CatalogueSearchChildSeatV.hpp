#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QLabel>
#include <QVector>
#include <QPushButton>
#include "Ui/DisplayData/DisplayData.hpp"

class CatalogueSearchChildSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchChildSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchChildSeatV() = default;

    void addFilters(const QVector<displayData::ChildSeat> &products);

signals:
    void filterClicked(const QVector<QString> &brands, const QVector<QString> &ages, const QVector<QString> &weights, 
                       const QVector<QString> &heights, const QVector<QString> &safetyKeys, const QVector<QString> &fastenings, 
                       const QVector<QString> &driveways);
    void clearClicked();

private slots:
    void onFilterButtonClicked();
    void onClearButtonClicked();
    
private:
    void setupUI();
    void setupConnections();

    // Layout
    QVBoxLayout *m_layout;

    // List widgets
    QListWidget *m_brandListWidget;
    QListWidget *m_ageListWidget;
    QListWidget *m_weightListWidget;
    QListWidget *m_heightListWidget;
    QListWidget *m_safetyKeyListWidget;
    QListWidget *m_fasteningListWidget;
    QListWidget *m_drivewayListWidget;

    // Labels
    QLabel *m_brandLabel;
    QLabel *m_ageLabel;
    QLabel *m_weightLabel;
    QLabel *m_heightLabel;
    QLabel *m_safetyKeyLabel;
    QLabel *m_fasteningLabel;
    QLabel *m_drivewayLabel;

    // Buttons
    QPushButton *m_filterButton;
    QPushButton *m_clearButton;
};