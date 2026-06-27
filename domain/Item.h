//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_ITEM_H
#define ARTAUCTIONOOPEXAM_ITEM_H
#include <string>
#include <vector>

class Item {
private:
    std::string name;
    std::string category;
    int price;
    std::vector<std::tuple<int,std::string,int>> listOfOffers;
public:
    Item(const std::string& name,const std::string& category,int price,const std::vector<std::tuple<int,std::string,int>>& listOfOffers);
    std::string getName() const;
    std::string getCategory() const;
    int getPrice() const;
    std::vector<std::tuple<int,std::string,int>> getListOfOffers() const;
    std::string toString() const;
    void setPrice(int newPrice);
    void addOffer(int userId,const std::string& date,int offeredSum);

};



#endif //ARTAUCTIONOOPEXAM_ITEM_H
