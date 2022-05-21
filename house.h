#include <iostream>
using std::string;

#ifndef HOUSE_H
#define HOUSE_H

class House {
    private:
        string id;
        string owner;
        
    public:
        double house_credit;
        bool status;
        double rating_score;
        string type;

        House (){}
        House (string id, bool status, string type);
};

#endif