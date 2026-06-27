//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_SERVICE_H
#define ARTAUCTIONOOPEXAM_SERVICE_H
#include "Subject.h"
#include "repo/Repository.h"


class Service:public Subject {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Item> getItems() const;
    std::vector<User> getUsers() const;
    std::vector<Item> getItemsSorted() const;
    void addItem(const std::string& name,const std::string& category,int price,const std::vector<std::tuple<int,std::string,int>>& offers);
    std::vector<std::tuple<int,std::string,int>> getOffers() const;
    std::vector<std::tuple<int,std::string,int>> getOffersForItemSorted(const Item& item) const;
};



#endif //ARTAUCTIONOOPEXAM_SERVICE_H
