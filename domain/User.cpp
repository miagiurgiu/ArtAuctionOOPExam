//
// Created by Maria on 27/06/2026.
//

#include "User.h"

User::User(const std::string &name, int id, const std::string &type):name{name},id{id},type{type} {
}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}

std::string User::getType() const {
    return type;
}
