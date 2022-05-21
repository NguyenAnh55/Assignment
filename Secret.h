#pragma once
#include <string>
#include <iostream>
using namespace std;

#ifndef UNTITLED3_SECRET_H
#define UNTITLED3_SECRET_H

class Secret{
protected:
    string id;
    string user_name;
    string pwd;
public:
    Secret();
    Secret(Secret& s);
    Secret(string id, string user_name, string pwd);
    ~Secret();
    string getID();
    string getUser_name();
    string getPwd();

    void setID(string id);
    void setUser_name(string owner);
    void setPwd(string location);

    void setAll(string id, string user_name, string pwd);
};

#endif //UNTITLED3_SECRET_H
