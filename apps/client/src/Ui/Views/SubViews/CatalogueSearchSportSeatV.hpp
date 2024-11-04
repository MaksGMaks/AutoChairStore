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

    QCheckBox *m_checkBox1;
    QCheckBox *m_checkBox2;
    QCheckBox *m_checkBox3;
    QCheckBox *m_checkBox4;
    QCheckBox *m_checkBox5;
    QCheckBox *m_checkBox6;
    QCheckBox *m_checkBox7;
    QCheckBox *m_checkBox8;
    QCheckBox *m_checkBox9;
    QCheckBox *m_checkBox10;
    QCheckBox *m_checkBox11;
    QCheckBox *m_checkBox12;


};