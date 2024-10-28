#pragma once

#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVector>

#include "IView.hpp"
#include "SubViews/CatalogueMenuSV.hpp"
#include "SubViews/CatalogueProductSV.hpp"
#include "SubViews/CatalogueSearchSV.hpp"
#include "Ui/DisplayData/DisplayData.hpp"

#include "Ui/TEST_UTILS.hpp"

class CatalogueView : public IView {
    Q_OBJECT
public:
    explicit CatalogueView(IViewModel *viewModel, QWidget *parent = nullptr);
    ~CatalogueView() = default;

signals:
    void openProductPage(const QString &productId);
    void addToBasket(const QString &productId);
    void buyProduct(const QString &productId);

private slots:
    void getProductList(const QVector<displayData::Products> &products);

private:
    void setupUI();
    void setupConnections();

    // View Models
    IViewModel *m_productsVM;
    
    // Subs: Menu
    CatalogueMenuSV *m_catalogueMenu;
        
    // Subs: Search engine
    CatalogueSearchSV *m_catalogueSearch;

    // Catalogue List
    QListWidget *m_catalogueList;

    // Widget
    QWidget *m_catalogueWidget;

    // Layouts
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_catalogueLayout;

    // Test data
    QVector<displayData::Products> m_products;
};