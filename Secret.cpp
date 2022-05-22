#include "Secret.h"//
// Created by user on 22/05/2022.
using namespace std;
//Default constructor
Secret::Secret() {
    id = "ID";
    user_name = "User";
    pwd= "Pass";
}
//copy constructor
Secret::Secret(Secret& s) {
    this->id = s.id;
    this->user_name = s.user_name;
    this->pwd = s.pwd;
}
//Parameterized constructor
Secret::Secret(string id, string user_name, string pwd) {
    this->id = id;
    this->user_name = user_name;
    this->pwd = pwd;
}
//Default deconstructor
Secret::~Secret() {}

//Getter
string Secret::getID() {
    return this->id;
}
string Secret::getUser_name() {
    return this->user_name;
}
string Secret::getPwd() {
    return this->pwd;
}
//Setter
void Secret::setID(string id) {
    this->id = id;
}
void Secret::setUser_name(string user_name) {
    this->user_name = user_name;
}
void Secret::setPwd(string pwd) {
    this->pwd = pwd;
}

//Set Item
void Secret::setAll(string id, string user_name, string pwd) {
    setID(id);
    setUser_name(user_name);
    setPwd(pwd);
}
//Print out
// Created by user on 21/05/2022.
//


