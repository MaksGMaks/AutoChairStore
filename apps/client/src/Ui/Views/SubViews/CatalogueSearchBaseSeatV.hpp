#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

class CatalogueSearchBaseSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchBaseSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchBaseSeatV() = default;

private:
    void setupUI();

    // Layout
    QVBoxLayout *m_layout;

    // test data
    QListWidget *m_brandListWidget;
    QListWidget *m_suitedForListWidget;
    QListWidget *m_colorListWidget;
    QListWidget *m_materialListWidget;
    QListWidget *m_typeListWidget;

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