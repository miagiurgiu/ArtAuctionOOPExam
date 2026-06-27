//
// Created by Maria on 27/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QComboBox>
#include <QMessageBox>

GUI::GUI(Service& service,const User& user,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},user{user} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(user.getName()));
    ui->comboBox->addItem("All");
    auto items=service.getItemsSorted();
    for (const auto& i:items) {
        QString category=QString::fromStdString(i.getCategory());
        if (ui->comboBox->findText(category)==-1) // if this category is not already in the combo, add it now.
            ui->comboBox->addItem(category);
    }
    connectSignalsAndSlots();
    GUI::update();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::update() {
    //populateList();
    seeItemsInSelectedCategory();
}

void GUI::connectSignalsAndSlots() {
    connect(ui->comboBox,&QComboBox::currentTextChanged,this,&GUI::seeItemsInSelectedCategory);
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addItem);
    connect(ui->itemsListWidget,&QListWidget::itemSelectionChanged,this,&GUI::populateOffersList);
}

void GUI::populateList() {
    ui->itemsListWidget->clear();
    auto items=service.getItemsSorted();
    for (const auto& i:items) {
        ui->itemsListWidget->addItem(QString::fromStdString(i.toString()));
    }
}

void GUI::seeItemsInSelectedCategory() {
    ui->itemsListWidget->clear();
    ui->offersListWidget->clear();
    //QString category=ui->comboBox->currentText();
    auto items=getCurrentDisplayed();
    for (const auto&i:items) {
        ui->itemsListWidget->addItem(QString::fromStdString(i.toString()));
    }
}

void GUI::addItem() {
    if (user.getType()!="administrator") {
        QMessageBox::critical(this,"ERROR","only administrators can add");
        return;
    }
    std::string name=ui->nameLineEdit->text().toStdString();
    std::string category=ui->categoryLineEdit->text().toStdString();
    int price=ui->priceLineEdit->text().toInt();
    std::vector<std::tuple<int,std::string,int>> offers;
    try {
        service.addItem(name,category,price,offers);
        ui->nameLineEdit->clear();
        ui->categoryLineEdit->clear();
        ui->priceLineEdit->clear();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::populateOffersList() {
    ui->offersListWidget->clear();
    auto selection=ui->itemsListWidget->selectedItems();
    if (selection.empty())
        return;
    int index=ui->itemsListWidget->currentRow();
    auto items=getCurrentDisplayed();
    auto item=items[index];
    auto offers=service.getOffersForItemSorted(item);
    for (const auto& o:offers) {
        std::string text=std::to_string(std::get<0>(o))+","+
            std::get<1>(o)+","+
                std::to_string(std::get<2>(o));
        ui->offersListWidget->addItem(QString::fromStdString(text));
    }
}

std::vector<Item> GUI::getCurrentDisplayed() {
    std::vector<Item> result;
    QString category=ui->comboBox->currentText();
    auto items=service.getItemsSorted();
    for (const auto&i:items) {
        if (category=="All" || QString::fromStdString(i.getCategory())==category)
            result.push_back(i);
    }
    return result;
}

