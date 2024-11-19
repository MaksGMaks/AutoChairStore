#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

class CatalogueSearchLuxurySeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchLuxurySeatV(QWidget *parent = nullptr);
    ~CatalogueSearchLuxurySeatV() = default;

private:
    void setupUI();

    // Layout
    QVBoxLayout *m_layout;

    // test data
    QListWidget *m_brandListWidget;
    QListWidget *m_suitedForListWidget;
    QListWidget *m_colorListWidget;
    QListWidget *m_materialListWidget;
    QListWidget *m_comfortListWidget;
    QListWidget *m_customDesignListWidget;
};