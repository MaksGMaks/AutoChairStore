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

class ChildSeatPage : public QTabWidget {
    Q_OBJECT
public:
    explicit ChildSeatPage(QTabWidget *parent = nullptr);
    ~ChildSeatPage() = default;

    void loadSeat(const displayData::ChildSeat &seat);
    
private:
    void setupUI();

    // Description
    QTextEdit *m_descriptionEdit;

    // Parameters
    QLabel *m_brandLabel;
    QLabel *m_ageLabel;
    QLabel *m_weightLabel;
    QLabel *m_heightLabel;
    QLabel *m_safetyStandardLabel;
    QLabel *m_fasteningLabel;
    QLabel *m_drivewayLabel;

    // Lines
    QLineEdit *m_brandEdit;
    QLineEdit *m_ageEdit;
    QLineEdit *m_weightEdit;
    QLineEdit *m_heightEdit;
    QLineEdit *m_safetyStandardEdit;
    QLineEdit *m_fasteningEdit;
    QLineEdit *m_drivewayEdit;

    // Layout
    QHBoxLayout *m_brandLayout;
    QHBoxLayout *m_ageLayout;
    QHBoxLayout *m_weightLayout;
    QHBoxLayout *m_heightLayout;
    QHBoxLayout *m_safetyStandardLayout;
    QHBoxLayout *m_fasteningLayout;
    QHBoxLayout *m_drivewayLayout;

    QVBoxLayout *m_parametersLayout;
};