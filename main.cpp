#include <QApplication>

#include "gui/gui.h"
#include "repo/Repository.h"
#include "service/Service.h"
//
// Created by Maria on 27/06/2026.
//
int main(int argc,char* argv[]) {
    QApplication app(argc,argv);
    Repository repo{"../users.txt","../items.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& u:service.getUsers()) {
        GUI* gui=new GUI{service,u};
        gui->show();
        windows.push_back(gui);
    }
    return app.exec();
}