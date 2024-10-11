#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

class CatalogueSearchSV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchSV(QWidget *parent = nullptr);
    virtual ~CatalogueSearchSV() = default;

private:
    void setupUI();

    // Layout
    QVBoxLayout *m_layout;

    // test data
    QListWidget *m_listWidget1;
    QListWidget *m_listWidget2;
    QListWidget *m_listWidget3;

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