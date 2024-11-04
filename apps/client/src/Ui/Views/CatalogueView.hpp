#pragma once

#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVector>
#include <QStackedWidget>

#include "IView.hpp"
#include "Ui/ViewModels/CatalogueViewModel.hpp"
#include "SubViews/CatalogueMenuSV.hpp"
#include "SubViews/CatalogueProductSV.hpp"
#include "SubViews/CatalogueSearchBaseSeatV.hpp"
#include "SubViews/CatalogueSearchChildSeatV.hpp"
#include "SubViews/CatalogueSearchSportSeatV.hpp"
#include "SubViews/CatalogueSearchLuxurySeatV.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

class CatalogueView : public IView {
    Q_OBJECT
public:
    explicit CatalogueView(CatalogueViewModel *viewModel, QWidget *parent = nullptr);
    ~CatalogueView() = default;

    void fetchProducts();
    void openRefresh();

signals:
    void openProductPage(const QString &productId);
    void addToBasket(const QString &productId);
    void buyProduct(const QString &productId);

    void vmFetchProducts();

private slots:
    void onProductsFetched();

private:
    void setupUI();
    void setupConnections();

    void getProductList(const int &id, const QVector<displayData::Products> &products);

    // View Models
    CatalogueViewModel *m_productsVM;
    
    // Subs: Menu
    CatalogueMenuSV *m_catalogueMenu;
        
    // Subs: Search engine
    CatalogueSearchBaseSeatV *m_baseSeatSearch;
    CatalogueSearchChildSeatV *m_childSeatSearch;
    CatalogueSearchSportSeatV *m_sportSeatSearch;
    CatalogueSearchLuxurySeatV *m_luxurySeatSearch;

    // Catalogue List
    QListWidget *m_baseSeatCatalogueList;
    QListWidget *m_childSeatCatalogueList;
    QListWidget *m_sportSeatCatalogueList;
    QListWidget *m_luxurySeatCatalogueList;
    QStackedWidget *m_catalogueStackedWidget;

    // Widgets
    QWidget *m_baseSeatWidget;
    QWidget *m_childSeatWidget;
    QWidget *m_sportSeatWidget;
    QWidget *m_luxurySeatWidget;

    // Layouts
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_baseSeatLayout;
    QHBoxLayout *m_childSeatLayout;
    QHBoxLayout *m_sportSeatLayout;
    QHBoxLayout *m_luxurySeatLayout;
};