#pragma once

#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

#include "IView.hpp"
#include "Ui/ViewModels/PurchaseOrderInfoVM.hpp"

class BasketView : public IView {
    Q_OBJECT
public:
    explicit BasketView(PurchaseOrderInfoVM *viewModel, QWidget *parent = nullptr);
    ~BasketView() = default;

private:
    void setupConnections();
    void setupUi();

    PurchaseOrderInfoVM *m_basketVM;

    // ComboBoxes
    QComboBox *m_paidMethodComboBox;
    QComboBox *m_deliveryMethodComboBox;

    // Labels
    QLabel *m_totalPriceLabel;
    QLabel *m_totalPriceValueLabel;
    QLabel *m_priceUnitLabel;
    QLabel *m_deliveryPriceLabel;
    QLabel *m_deliveryPriceValueLabel;
    QLabel *m_deliveryPriceUnitLabel;
    QLabel *m_adressLabel;
    QLabel *m_paymentMethodLabel;
    QLabel *m_deliveryMethodLabel;

    // Line Edits
    QLineEdit *m_adressLineEdit;

    // Buttons
    QPushButton *m_buyButton;
    QPushButton *m_cancelButton;

    // Table
    QTableWidget *m_ordersTable;
};