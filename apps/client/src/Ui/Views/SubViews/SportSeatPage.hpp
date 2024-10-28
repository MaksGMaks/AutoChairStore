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

class SportSeatPage : public QTabWidget {
    Q_OBJECT
public:
    explicit SportSeatPage(QTabWidget *parent = nullptr);
    ~SportSeatPage() = default;

    void loadSeat(const displayData::SportSeat &seat);

private:
    void setupUI();

    // Description
    QTextEdit *m_descriptionEdit;

    // Parameters
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_shellTypeLabel;
    QLabel *m_shellMaterialLabel;
    QLabel *m_coverMaterialLabel;
    QLabel *m_colorLabel;

    // Lines
    QLineEdit *m_brandEdit;
    QLineEdit *m_suitedForEdit;
    QLineEdit *m_shellTypeEdit;
    QLineEdit *m_shellMaterialEdit;
    QLineEdit *m_coverMaterialEdit;
    QLineEdit *m_colorEdit;

    // Layout
    QHBoxLayout *m_brandLayout;
    QHBoxLayout *m_suitedForLayout;
    QHBoxLayout *m_shellTypeLayout;
    QHBoxLayout *m_shellMaterialLayout;
    QHBoxLayout *m_coverMaterialLayout;
    QHBoxLayout *m_colorLayout;

    QVBoxLayout *m_parametersLayout;
};