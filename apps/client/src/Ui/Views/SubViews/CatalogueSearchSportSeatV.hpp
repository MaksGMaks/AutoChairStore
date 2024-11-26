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

class CatalogueSearchSportSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchSportSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchSportSeatV() = default;

    void addFilters(const QVector<displayData::SportSeat> &products);

signals:
    void filterClicked(const QVector<QString> &brands, const QVector<QString> &suitedFors, 
                       const QVector<QString> &shellTypes, const QVector<QString> &shellMaterials, const QVector<QString> &coverMaterials, 
                       const QVector<QString> &colors);
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
    QListWidget *m_suitedForListWidget;
    QListWidget *m_shellTypeListWidget;
    QListWidget *m_shellMaterialListWidget;
    QListWidget *m_coverMaterialListWidget;
    QListWidget *m_colorListWidget;

    // Labels
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_shellTypeLabel;
    QLabel *m_shellMaterialLabel;
    QLabel *m_coverMaterialLabel;
    QLabel *m_colorLabel;

    // Buttons
    QPushButton *m_filterButton;
    QPushButton *m_clearButton;
};