#include "Member.h"
using namespace std;

//Default structor
Member::Member() {
    id = "ID";
    name = "Name";
    phone_number = "phone";
    house_location = "location";
    credit = 0;
    occupier_rating = 0;
    vector<string> requests = {};
}
//copy constructor
Member::Member(Member& m) {
    this->id = m.id;
    this->name = m.name;
    this->phone_number = m.phone_number;
    this->house_location = m.house_location;
    this->credit = m.credit;
    this->occupier_rating = m.occupier_rating;
    this->requests = m.requests;

}
//Parameterized constructor
Member::Member(string id, string name, string phone_number, string house_location, double credit, double occupier_rating, vector<string> requests) {
    this->id = id;
    this->name = name;
    this->phone_number = phone_number;
    this->house_location = house_location;
    this->credit = credit;
    this->occupier_rating= occupier_rating;
    this->requests = requests;
}
// Default destructor
Member::~Member() {}

//Getters
string Member::getId() {
    return this->id;
}
string Member::getName() {
    return this->name;
}
string Member::getPhone() {
    return this->phone_number;
}
string Member::getHouse_local() {
    return this->house_location;
}
double Member::getCred() {
    return this->credit;
}
double Member::getOcc_rate() {
    return this->occupier_rating;
}

vector<string> Member::getRequests() {
    return this->requests;
}
//setters
void Member::setId(string id) {
    this->id = id;
}
void Member::setName(string name) {
    this->name = name;
}
void Member::setPhone(string phone) {
    this->phone_number = phone_number;
}
void Member::setHouse_local(string house_location) {
    this->house_location = house_location;
}
void Member::setCred(double credit) {
    this->credit = credit;
}
void Member::setOcc_rate(double occupier_rating) {
    this->occupier_rating = occupier_rating;
}
void Member::setRequest(vector<string> requests) {
    this->requests = requests;
}
//Set all
void Member::setInfo(string id, string name, string phone_number, string house_location, double credit, double occupier_rating, vector<string> requests) {
    Member::setId(id);
    Member::setName(name);
    Member::setPhone(phone_number);
    Member::setHouse_local(house_location);
    Member::setCred(credit);
    Member::setOcc_rate(occupier_rating);
    Member::setRequest(requests);
}
void Member::printInfo() {
    int num_item = 0;
    num_item = requests.size();
    cout << id << ", " << name << ", " << phone_number << ", " << house_location << ", " << credit << ", " << occupier_rating;
    for (int i = 0; i < num_item; i++) {
        cout << ", "<< requests[i] << endl;
    }
}

void Member::printRequests() {
    int num_item = 0;
    int index = 1;
    num_item = requests.size();
    for (int i = 0; i < num_item; i++) {
        cout << index << ". " << requests[i] << endl;
        index++;
    }
};
//
// Created by user on 20/05/2022.
//

