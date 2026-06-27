//
// Created by Maria on 27/06/2026.
//

#ifndef ARTAUCTIONOOPEXAM_USER_H
#define ARTAUCTIONOOPEXAM_USER_H
#include <string>


class User {
private:
    std::string name;
    int id;
    std::string type; // collector/administrator
public:
    User(const std::string& name,int id, const std::string& type);
    std::string getName() const;
    int getId() const;
    std::string getType() const;
};



#endif //ARTAUCTIONOOPEXAM_USER_H
