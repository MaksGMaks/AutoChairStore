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

class LuxurySeatPage : public QTabWidget {
    Q_OBJECT
public:
    explicit LuxurySeatPage(QTabWidget *parent = nullptr);
    ~LuxurySeatPage() = default;

    void loadSeat(const displayData::LuxurySeat &seat);
    
private:
    void setupUI();

    // Description
    QTextEdit *m_descriptionEdit;

    // Parameters
    QLabel *m_brandLabel;
    QLabel *m_suitedForLabel;
    QLabel *m_colorLabel;
    QLabel *m_materialLabel;
    QLabel *m_comfortLevelLabel;
    QLabel *m_customDesignLabel;

    // Lines
    QLineEdit *m_brandEdit;
    QLineEdit *m_suitedForEdit;
    QLineEdit *m_colorEdit;
    QLineEdit *m_materialEdit;
    QLineEdit *m_comfortLevelEdit;
    QLineEdit *m_customDesignEdit;

    // Layout
    QHBoxLayout *m_brandLayout;
    QHBoxLayout *m_suitedForLayout;
    QHBoxLayout *m_colorLayout;
    QHBoxLayout *m_materialLayout;
    QHBoxLayout *m_comfortLevelLayout;
    QHBoxLayout *m_customDesignLayout;

    QVBoxLayout *m_parametersLayout;
};