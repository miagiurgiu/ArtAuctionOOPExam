//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_GUI_H
#define ARTAUCTIONOOPEXAM_GUI_H

#include <QWidget>

#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget,public Observer {
Q_OBJECT

public:
    explicit GUI(Service& service,const User& user,QWidget *parent = nullptr);
    ~GUI() override;
    void update() override;

private:
    Ui::GUI *ui;
    Service& service;
    User user;
    void connectSignalsAndSlots();
    void populateList();
    void seeItemsInSelectedCategory();
    void addItem();
    void populateOffersList();
    std::vector<Item> getCurrentDisplayed();
};


#endif //ARTAUCTIONOOPEXAM_GUI_H
