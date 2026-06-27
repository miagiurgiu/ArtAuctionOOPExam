//
// Created by Maria on 27/06/2026.
//

#include "Item.h"

#include <list>

Item::Item(const std::string &name, const std::string &category, int price,
           const std::vector<std::tuple<int, std::string, int>> &listOfOffers):name{name},category{category},price{price},listOfOffers{listOfOffers} {
}

std::string Item::getName() const {
    return name;
}

std::string Item::getCategory() const {
    return category;
}

int Item::getPrice() const {
    return price;
}

std::vector<std::tuple<int, std::string, int>> Item::getListOfOffers() const {
    return listOfOffers;
}

std::string Item::toString() const {
    return name+","+category+","+std::to_string(price);
}

void Item::setPrice(int newPrice) {
    price=newPrice;
}

void Item::addOffer(int userId, const std::string &date, int offeredSum) {
    listOfOffers.push_back(std::make_tuple(userId,date,offeredSum));
}
