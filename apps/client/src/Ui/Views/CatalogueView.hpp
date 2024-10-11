#pragma once

#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>

#include "IView.hpp"
#include "SubViews/CatalogueMenuSV.hpp"
#include "SubViews/CatalogueProductSV.hpp"
#include "SubViews/CatalogueSearchSV.hpp"

#include "Ui/TEST_UTILS.hpp"

class CatalogueView : public IView {
    Q_OBJECT
public:
    explicit CatalogueView(IViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~CatalogueView() = default;

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

    // test data
    QHBoxLayout *m_productLine1;
    QHBoxLayout *m_productLine2;
    QHBoxLayout *m_productLine3;

    CatalogueProductSV *m_product1;
    CatalogueProductSV *m_product2;
    CatalogueProductSV *m_product3;
    CatalogueProductSV *m_product4;
    CatalogueProductSV *m_product5;
    CatalogueProductSV *m_product6;
    CatalogueProductSV *m_product7;
    CatalogueProductSV *m_product8;
    CatalogueProductSV *m_product9;
    CatalogueProductSV *m_product10;
};