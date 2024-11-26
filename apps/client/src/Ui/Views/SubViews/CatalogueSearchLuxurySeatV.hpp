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

class CatalogueSearchLuxurySeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchLuxurySeatV(QWidget *parent = nullptr);
    ~CatalogueSearchLuxurySeatV() = default;

    void addFilters(const QVector<displayData::LuxurySeat> &products);

signals:
    void filterClicked(const QVector<QString> &brands, const QVector<QString> &suitedFors, 
                       const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &comforts, 
                       const QVector<QString> &customDesigns);
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
    QListWidget *m_colorListWidget;
    QListWidget *m_materialListWidget;
    QListWidget *m_comfortListWidget;
    QListWidget *m_customDesignListWidget;

    // Labels
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_colorLabel;
    QLabel *m_materialLabel;
    QLabel *m_comfortLabel;
    QLabel *m_customDesignLabel;

    // Buttons
    QPushButton *m_filterButton;
    QPushButton *m_clearButton;
};