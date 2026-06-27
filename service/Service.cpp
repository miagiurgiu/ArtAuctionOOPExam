//
// Created by Maria on 27/06/2026.
//

#include "Service.h"

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
