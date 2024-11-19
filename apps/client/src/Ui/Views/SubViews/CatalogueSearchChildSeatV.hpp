#pragma once

#include <iostream>
#include <QWidget>
#include <QListWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

class CatalogueSearchChildSeatV : public QWidget {
    Q_OBJECT
public:
    explicit CatalogueSearchChildSeatV(QWidget *parent = nullptr);
    ~CatalogueSearchChildSeatV() = default;

private:
    void setupUI();

    // Layout
    QVBoxLayout *m_layout;

    // test data
    QListWidget *m_brandListWidget;
    QListWidget *m_ageListWidget;
    QListWidget *m_weightListWidget;
    QListWidget *m_heightListWidget;
    QListWidget *m_safetyKeyListWidget;
    QListWidget *m_fasteningListWidget;
    QListWidget *m_drivewayListWidget;
};