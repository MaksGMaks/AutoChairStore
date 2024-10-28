#pragma once

#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QStackedWidget>

#include "IView.hpp"
#include "Ui/ViewModels/AccountViewModel.hpp"
#include "SubViews/BaseSeatPage.hpp"
#include "SubViews/ChildSeatPage.hpp"
#include "SubViews/SportSeatPage.hpp"
#include "SubViews/LuxurySeatPage.hpp"

class PurchaseOrderInfoV : public IView {
    Q_OBJECT
public:
    explicit PurchaseOrderInfoV(AccountViewModel *viewModel, QWidget *parent = nullptr);
    ~PurchaseOrderInfoV() = default;

signals:
    void vmCancelOrder(const QString &id);
    void vmLoadSeat(const QString &id);
    void goBack();

public slots:
    void onLoadOrder(const QString &id);

private slots:
    void onCancelOrderButtonClicked();
    void onBackButtonClicked();

    void onBaseSeatLoaded(const displayData::BaseSeat &seat);
    void onChildSeatLoaded(const displayData::ChildSeat &seat);
    void onSportSeatLoaded(const displayData::SportSeat &seat);
    void onLuxurySeatLoaded(const displayData::LuxurySeat &seat);

    void onCancelOrder();
    void onGoBack();

private:
    void setupUi();
    void setupProductInfo();
    void setupConnections();

    AccountViewModel *m_purchaseOrderVM;
    QString orderId;

    // Pages
    BaseSeatPage *m_baseSeatPage;
    ChildSeatPage *m_childSeatPage;
    SportSeatPage *m_sportSeatPage;
    LuxurySeatPage *m_luxerySeatPage;

    // Labels
    QLabel *m_titleLabel;
    QLabel *m_packageIdLabel;
    QLabel *m_paidInfoLabel;
    QLabel *m_destinationLabel;
    QLabel *m_dateLabel;
    QLabel *m_statusLabel;

    // Line Edits
    QLineEdit *m_packageIdLineEdit;
    QLineEdit *m_paidInfoLineEdit;
    QLineEdit *m_destinationLineEdit;
    QLineEdit *m_dateLineEdit;
    QLineEdit *m_statusLineEdit;

    // Buttons
    QPushButton *m_backButton;
    QPushButton *m_cancelOrderButton;
    
    // Spacers
    QSpacerItem *m_spacer;

    // Layouts
    QHBoxLayout *m_titleLayout;
    QHBoxLayout *m_packageIdLayout;
    QHBoxLayout *m_paidInfoLayout;
    QHBoxLayout *m_destinationLayout;
    QHBoxLayout *m_dateLayout;
    QHBoxLayout *m_statusLayout;
    
    QVBoxLayout *m_leftHalfLayout;
    QVBoxLayout *m_rightHalfLayout;

    QHBoxLayout *m_purchaseOrderLayout;
    QVBoxLayout *m_mainLayout;

    // Scroll Area
    QScrollArea *m_scrollArea;
    QStackedWidget *m_stackedWidget;

    // Product Info
    QWidget *m_productInfoWidget;

    // Labels
    QLabel *m_imageLabel;
    QLabel *m_discountLabel;
    QLabel *m_totalPriceLabel;
    QLabel *m_unitPriceLabel;
    QLabel *m_priceLabel;

    QFont m_priceFont;

    // Spacers
    QSpacerItem *m_vUSpacer;
    QSpacerItem *m_vDSpacer;
    QSpacerItem *m_hLSpacer;
    QSpacerItem *m_hRSpacer;

    // Layouts
    QHBoxLayout *m_totalPriceLayout;
    QHBoxLayout *m_priceLayout;
    QVBoxLayout *m_priceInfoLayout;
    QHBoxLayout *m_productInfoLayout;
    QVBoxLayout *m_productInfoMainLayout;

};