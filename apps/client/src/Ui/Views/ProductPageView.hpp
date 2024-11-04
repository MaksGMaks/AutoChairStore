#pragma once

#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QStackedWidget>

#include "IView.hpp"
#include "Ui/ViewModels/ProductPageViewModel.hpp"
#include "SubViews/BaseSeatPage.hpp"
#include "SubViews/ChildSeatPage.hpp"
#include "SubViews/SportSeatPage.hpp"
#include "SubViews/LuxurySeatPage.hpp"

class ProductPageView : public IView {
    Q_OBJECT
public:
    explicit ProductPageView(ProductPageViewModel *viewModel, QWidget *parent = nullptr);
    ~ProductPageView() = default;

    void onLoadOrder(const QString &id);

signals:
    void vmLoadSeat(const QString &id);

    void goBack();
    void buyProduct(const QString &id);
    void addToCart(const QString &id);

private slots:
    void onBackButtonClicked();
    void onBuyButtonClicked();
    void onAddToCartButtonClicked();

    void onBaseSeatLoadedSuccess(const displayData::BaseSeat &seat);
    void onChildSeatLoadedSuccess(const displayData::ChildSeat &seat);
    void onSportSeatLoadedSuccess(const displayData::SportSeat &seat);
    void onLuxurySeatLoadedSuccess(const displayData::LuxurySeat &seat);

private:
    void setupConnections();
    void setupUi();

    ProductPageViewModel *m_productPageVM;
    QString productId;

    // Labels
    QLabel *m_imageLabel;
    QLabel *m_discountLabel;
    QLabel *m_totalPriceLabel;
    QLabel *m_unitPriceLabel;
    QLabel *m_priceLabel;
    QLabel *m_titleLabel;

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

    // Buttons
    QPushButton *m_backButton;
    QPushButton *m_buyButton;
    QPushButton *m_addToCartButton;

    // Scroll Area
    QScrollArea *m_scrollArea;
    QStackedWidget *m_stackedWidget;

    // Pages
    BaseSeatPage *m_baseSeatPage;
    ChildSeatPage *m_childSeatPage;
    SportSeatPage *m_sportSeatPage;
    LuxurySeatPage *m_luxerySeatPage;
};