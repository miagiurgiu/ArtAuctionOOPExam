//
// Created by Maria on 27/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Service& service,const User& user,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},user{user} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(user.getName()));
    connectSignalsAndSlots();
    GUI::update();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::update() {
    populateList();
}

void GUI::connectSignalsAndSlots() {
    return;
}

void GUI::populateList() {
    ui->itemsListWidget->clear();
    auto items=service.getItemsSorted();
    for (const auto& i:items) {
        ui->itemsListWidget->addItem(QString::fromStdString(i.toString()));
    }
}

