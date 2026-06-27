//
// Created by Maria on 27/06/2026.
//

#include "Repository.h"
#include <fstream>
#include <sstream>

Repository::Repository(const std::string &usersFile, const std::string &itemsFile):usersFile{usersFile}, itemsFile{itemsFile}{
    loadItems();
    loadUsers();
}

std::vector<Item> Repository::getItems() const {
    return items;
}

std::vector<User> Repository::getUsers() const {
    return users;
}

void Repository::loadUsers() {
    std::ifstream fin(usersFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name,idString,type;
        std::getline(ss,name,',');
        std::getline(ss,idString,',');
        std::getline(ss,type,',');

        int id=std::stoi(idString);
        users.emplace_back(name,id,type);
    }
    fin.close();
}

void Repository::loadItems() {
    std::ifstream fin(itemsFile);

    if (!fin.is_open())
        throw std::runtime_error("could not open file");

    std::string line;

    while (std::getline(fin,line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string name, category, priceString, offersString;

        std::getline(ss, name, ',');
        std::getline(ss, category, ',');
        std::getline(ss, priceString, ',');
        std::getline(ss, offersString);

        int price = std::stoi(priceString);

        std::vector<std::tuple<int,std::string,int>> offers;

        std::stringstream sss(offersString);
        std::string offerToken;

        while (std::getline(sss, offerToken, ';')) {
            if (offerToken.empty())
                continue;

            std::stringstream ssss(offerToken);

            std::string userIdString, date, sumString;

            std::getline(ssss, userIdString, '|');
            std::getline(ssss, date, '|');
            std::getline(ssss, sumString, '|');

            int userId = std::stoi(userIdString);
            int sum = std::stoi(sumString);

            offers.push_back(std::make_tuple(userId, date, sum));
        }
        items.emplace_back(name, category, price, offers);
    }

    fin.close();
}

void Repository::save() {
    std::ofstream fout(itemsFile);
    if (!fout.is_open())
        throw std::runtime_error("could not open file");
    for (const auto& item:items) {
        fout<<item.getName()<<","
        <<item.getCategory()<<","
        <<item.getPrice()<<",";
        auto offers=item.getListOfOffers();
        for (int i=0;i<offers.size();i++) {
            fout<<std::get<0>(offers[i])<<"|"
            <<std::get<1>(offers[i])<<"|"
            <<std::get<2>(offers[i]);
            if (i!=offers.size()-1)
                fout<<";";
        }
        fout<<"\n";
    }
    fout.close();
}

void Repository::addItem(const Item &newItem) {
    items.push_back(newItem);
    save();
}

void Repository::bid(const Item &item, int userId, const std::string &date, int offeredSum) {
    for (auto& i:items) {
        if (i.getName()==item.getName()) {
            i.setPrice(offeredSum);
            i.addOffer(userId,date,offeredSum);
            save();
            return;
        }
    }
    throw std::runtime_error("item not found");
}
