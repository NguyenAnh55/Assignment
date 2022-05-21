#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

class Member {
private:
    string id, name, phone_number, house_location;
    double credit, occupier_rating;
    vector<string>requests;
public:
    //Default constructor
    Member();
    //copy constructor
    Member(Member& c);
    //Parameterized constructor
    Member(string id, string name, string phone_number, string house_location, double credit, double occupier_rating, vector<string> requests);
    // Default destructor
    ~Member();
    //Getters
    string getId();
    string getName();
    string getPhone();
    string getHouse_local();
    double getCred();
    double getOcc_rate();
    vector<string> getRequests();
    //setters
    void setId(string id);
    void setName(string name);
    void setPhone(string phone_number);
    void setHouse_local(string house_location);
    void setCred(double credit);
    void setOcc_rate(double occupier_rating);
    void setRequest(vector<string> requests);
    //Set all
    void setInfo(string id, string name, string phone_number, string house_location, double credit, double occupier_rating, vector<string> requests);
    void printInfo();
    void printRequests();
};

#endif