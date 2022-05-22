#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

class Member {
private:
    string id, name, phone_number, address, house_type;
    double credit, occupier_rating;
    int request_quantity;
    vector<string>requests;
public:
    //Default constructor
    Member();
    //copy constructor
    Member(Member& c);
    //Parameterized constructor
    Member(string id, string name, string phone_number, string address, string house_type, double credit, double occupier_rating, int request_quantity,vector<string> requests);
    // Default destructor
    ~Member();
    //Getters
    string getId();
    string getName();
    string getPhone();
    string getAddress();
    string getHouse_type();
    double getCred();
    double getOcc_rate();
    int getR_quan();
    vector<string> getRequests();
    //setters
    void setId(string id);
    void setName(string name);
    void setPhone(string phone_number);
    void setAddress(string address);
    void setHouse_type(string house_type);
    void setCred(double credit);
    void setOcc_rate(double occupier_rating);
    void setR_quan(int request_quantity);
    void setRequest(vector<string> requests);
    //Set all
    void setInfo(string id, string name, string phone_number, string address, string house_type, double credit, double occupier_rating, int request_quantity, vector<string> requests);
    void printInfo();
    void printRequests();
};

#endif
