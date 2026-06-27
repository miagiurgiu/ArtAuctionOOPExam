//
// Created by Maria on 27/06/2026.
//

#include "Service.h"
#include <QDate>
Service::Service(Repository &repo):repo{repo} {
}

std::vector<Item> Service::getItems() const {
    return repo.getItems();
}

std::vector<User> Service::getUsers() const {
    return repo.getUsers();
}

std::vector<Item> Service::getItemsSorted() const {
    auto items=repo.getItems();
    std::sort(items.begin(),items.end(),[](const Item& i1,const Item& i2) {
        return i1.getPrice()<i2.getPrice();
    });
    return items;
}

void Service::addItem(const std::string &name, const std::string &category, int price,
    const std::vector<std::tuple<int, std::string, int>> &offers) {
    if (name.empty())
        throw std::runtime_error("empty name");
    if (price<=0)
        throw std::runtime_error("invalid price");
    Item newItem{name,category,price,offers};
    repo.addItem(newItem);
    notify();
}



std::vector<std::tuple<int, std::string, int>> Service::getOffersForItemSorted(const Item &item) const {
    auto offers=item.getListOfOffers();
    std::sort(offers.begin(),offers.end(),[](const auto& o1,const auto& o2) {
        return std::get<1>(o1)>std::get<1>(o2);
    });
    return offers;
}

void Service::bid(const Item &item, int userId,int offeredSum) {
    /*
    if (offeredSum<item.getPrice())
        throw std::runtime_error("offered sum less than current price");
        */
    std::string date=QDate::currentDate().toString("yyyy-MM-dd").toStdString();
    repo.bid(item,userId,date,offeredSum);
    notify();
}
