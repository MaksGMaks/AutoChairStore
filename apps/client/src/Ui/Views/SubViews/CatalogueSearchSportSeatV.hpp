#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

class CatalogueSearchSportSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchSportSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchSportSeatV() = default;

private:
    void setupUI();

    // Layout
    QVBoxLayout *m_layout;

    // test data
    QListWidget *m_brandListWidget;
    QListWidget *m_suitedForListWidget;
    QListWidget *m_shellTypeListWidget;
    QListWidget *m_shellMaterialListWidget;
    QListWidget *m_coverMaterialListWidget;
    QListWidget *m_colorListWidget;
};