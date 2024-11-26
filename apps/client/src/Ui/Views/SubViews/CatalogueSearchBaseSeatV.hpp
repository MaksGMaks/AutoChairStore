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

class CatalogueSearchBaseSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchBaseSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchBaseSeatV() = default;

    void addFilters(const QVector<displayData::BaseSeat> &products);

signals:
    void filterClicked(const QVector<QString> &brands, const QVector<QString> &suitedFors, 
                       const QVector<QString> &colors, const QVector<QString> &materials, const QVector<QString> &types);
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
    QListWidget *m_typeListWidget;

    // Labels
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_colorLabel;
    QLabel *m_materialLabel;
    QLabel *m_typeLabel;

    // Buttons
    QPushButton *m_filterButton;
    QPushButton *m_clearButton;
};