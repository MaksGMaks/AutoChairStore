#pragma once

#include <iostream>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Ui/DisplayData/DisplayData.hpp"

class BaseSeatPage : public QTabWidget {
    Q_OBJECT
public:
    explicit BaseSeatPage(QTabWidget *parent = nullptr);
    ~BaseSeatPage() = default;

    void loadSeat(const displayData::BaseSeat &seat);

private:
    void setupUI();

    // Description
    QTextEdit *m_descriptionEdit;

    // Parameters
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_colorLabel;
    QLabel *m_materialLabel;
    QLabel *m_typeLabel;

    // Lines
    QLineEdit *m_brandEdit;
    QLineEdit *m_suitedForEdit;
    QLineEdit *m_colorEdit;
    QLineEdit *m_materialEdit;
    QLineEdit *m_typeEdit;

    // Layout
    QHBoxLayout *m_brandLayout;
    QHBoxLayout *m_suitedForLayout;
    QHBoxLayout *m_colorLayout;
    QHBoxLayout *m_materialLayout;
    QHBoxLayout *m_typeLayout;

    QVBoxLayout *m_parametersLayout;

};