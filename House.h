#pragma once
#include <string>
#include <iostream>
using namespace std;

#ifndef HOUSE_H
#define HOUSE_H

class House {
protected:
    string id;
    string owner;
    string location;
    string h_type;
    double rating;
    string status;

public:
    House();
    House(House& h);
    House(string id, string owner, string location, string h_type, double rating, string status);
    ~House();
    string getID();
    string getOwner();
    string getLocation();
    string getType();
    double getRating();
    string getStatus();

    void setID(string id);
    void setOwner(string owner);
    void setLocation(string location);
    void setType(string h_type);
    void setRating(double rating);
    void setStatus(string status);
    void setAll(string id, string owner, string location, string h_type, double rating, string status);
    friend ostream& operator<< (ostream& out, House& e);
};
#endif