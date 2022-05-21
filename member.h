#include <iostream>
#include "house.h"

using std::string;

#ifndef MEMBER_H
#define MEMBER_H

class Member 
{
    private:
        string username;
        string pwd;
        House house;
        double credit;
        double Occupier_rate;

    public:
        string phone;
        bool status;

    Member (){}
    Member (string username, string pwd);
};

#endif
