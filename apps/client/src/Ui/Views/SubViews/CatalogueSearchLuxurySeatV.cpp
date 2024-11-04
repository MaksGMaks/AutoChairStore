#include "CatalogueSearchLuxurySeatV.hpp"

CatalogueSearchLuxurySeatV::CatalogueSearchLuxurySeatV(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void CatalogueSearchLuxurySeatV::setupUI() {
    std::cout << "[CatalogueSearchLuxurySeatV::setupUI] Setting up UI" << std::endl;

    m_checkBox1 = new QCheckBox("CheckBox 1");
    m_checkBox2 = new QCheckBox("CheckBox 2");
    m_checkBox3 = new QCheckBox("CheckBox 3");
    m_checkBox4 = new QCheckBox("CheckBox 4");
    m_checkBox5 = new QCheckBox("CheckBox 5");
    m_checkBox6 = new QCheckBox("CheckBox 6");
    m_checkBox7 = new QCheckBox("CheckBox 7");
    m_checkBox8 = new QCheckBox("CheckBox 8");
    m_checkBox9 = new QCheckBox("CheckBox 9");
    m_checkBox10 = new QCheckBox("CheckBox 10");
    m_checkBox11 = new QCheckBox("CheckBox 11");
    m_checkBox12 = new QCheckBox("CheckBox 12");

    std::vector<QCheckBox *> checkBoxes1 = {m_checkBox1, m_checkBox2, m_checkBox3, m_checkBox4};
    std::vector<QCheckBox *> checkBoxes2 = {m_checkBox5, m_checkBox6, m_checkBox7};
    std::vector<QCheckBox *> checkBoxes3 = {m_checkBox8, m_checkBox9, m_checkBox10, m_checkBox11, m_checkBox12};

//     m_listWidget1 = new QListWidget();
//     m_listWidget2 = new QListWidget();
//     m_listWidget3 = new QListWidget();

//     m_listWidget1->setFixedSize(200, 200);
//     m_listWidget2->setFixedSize(200, 200);
//     m_listWidget3->setFixedSize(200, 200);

//     for (auto checkBox : checkBoxes1) {
//     QListWidgetItem *item = new QListWidgetItem(m_listWidget1);
//     m_listWidget1->setItemWidget(item, checkBox);
// }

// for (auto checkBox : checkBoxes2) {
//     QListWidgetItem *item = new QListWidgetItem(m_listWidget2);
//     m_listWidget2->setItemWidget(item, checkBox);
// }

// for (auto checkBox : checkBoxes3) {
//     QListWidgetItem *item = new QListWidgetItem(m_listWidget3);
//     m_listWidget3->setItemWidget(item, checkBox);
// }


    m_layout = new QVBoxLayout();
    // m_layout->addWidget(m_listWidget1);
    // m_layout->addWidget(m_listWidget2);
    // m_layout->addWidget(m_listWidget3);
    setLayout(m_layout);
}