//
// Created by Maria on 27/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QComboBox>

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
    QString category=ui->comboBox->currentText();
    auto items=service.getItemsSorted();
    for (const auto&i:items) {
        if (category=="All" || QString::fromStdString(i.getCategory())==category){
            ui->itemsListWidget->addItem(QString::fromStdString(i.toString()));
        }
    }
}

