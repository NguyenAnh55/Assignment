#include "Member.h"
using namespace std;

//Default structor
Member::Member() {
    id = "ID";
    name = "Name";
    phone_number = "phone";
    address = "address";
    house_type = "None";
    credit = 500;
    occupier_rating = 0;
    request_quantity =0;
    vector<string> requests = {};
}
//copy constructor
Member::Member(Member& m) {
    this->id = m.id;
    this->name = m.name;
    this->phone_number = m.phone_number;
    this->address = m.address;
    this->house_type =m.house_type;
    this->credit = m.credit;
    this->occupier_rating = m.occupier_rating;
    this->request_quantity = m.request_quantity;
    this->requests = m.requests;

}
//Parameterized constructor
Member::Member(string id, string name, string phone_number, string address, string house_type, double credit, double occupier_rating, int request_quantity, vector<string> requests) {
    this->id = id;
    this->name = name;
    this->phone_number = phone_number;
    this->address = address;
    this->house_type = house_type;
    this->credit = credit;
    this->occupier_rating= occupier_rating;
    this->request_quantity = request_quantity;
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
string Member::getAddress() {
    return this->address;
}
string Member::getHouse_type() {
    return this->house_type;
}
double Member::getCred() {
    return this->credit;
}
double Member::getOcc_rate() {
    return this->occupier_rating;
}
int Member::getR_quan() {
    return this->request_quantity;
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
void Member::setAddress(string address) {
    this->address = address;
}
void Member::setHouse_type(string house_type) {
    this->house_type = house_type;
}
void Member::setCred(double credit) {
    this->credit = credit;
}
void Member::setOcc_rate(double occupier_rating) {
    this->occupier_rating = occupier_rating;
}
void Member::setR_quan(int request_quantity) {
    this->request_quantity = request_quantity;
}
void Member::setRequest(vector<string> requests) {
    this->requests = requests;
}
//Set all
void Member::setInfo(string id, string name, string phone_number, string address,string house_type, double credit, double occupier_rating, int request_quantity,vector<string> requests) {
    Member::setId(id);
    Member::setName(name);
    Member::setPhone(phone_number);
    Member::setAddress(address);
    Member::setHouse_type(house_type);
    Member::setCred(credit);
    Member::setOcc_rate(occupier_rating);
    Member::setR_quan(request_quantity);
    Member::setRequest(requests);
}
void Member::printInfo() {
    int num_item = 0;
    num_item = requests.size();
    cout << id << ", " << name << ", " << phone_number << ", " << address << ", " << house_type << ", " << credit << ", " << occupier_rating << ", " << request_quantity << endl;
    for (int i = 0; i < num_item; i++) {
        cout << requests[i] << endl;
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
