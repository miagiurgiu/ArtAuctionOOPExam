//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_REPOSITORY_H
#define ARTAUCTIONOOPEXAM_REPOSITORY_H
#include <string>

#include "Item.h"
#include "User.h"
#include <vector>

class Repository {
private:
    std::string usersFile;
    std::string itemsFile;
    std::vector<Item> items;
    std::vector<User> users;
public:
    Repository(const std::string& usersFile,const std::string& itemsFile);
    std::vector<Item> getItems() const;
    std::vector<User> getUsers() const;
    void loadUsers();
    void loadItems();
    void save();
};



#endif //ARTAUCTIONOOPEXAM_REPOSITORY_H
