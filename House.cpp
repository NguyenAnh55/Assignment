#include "House.h"

using namespace std;
//Default constructor
House::House() {
    id = "ID";
    owner = "Owner";
    location= "Location";
    h_type = "house type";
    rating = 0;
    status = "false";
}
//copy constructor
House::House(House& h) {
    this->id = h.id;
    this->owner = h.owner;
    this->location = h.location;
    this->h_type = h.h_type;
    this->rating = h.rating;
    this->status = h.status;
}
//Parameterized constructor
House::House(string id, string owner, string location, string h_type, double rating, string status) {
    this->id = id;
    this->owner = owner;
    this->location = location;
    this->h_type = h_type;
    this->rating = rating;
    this->status = status;
}
//Default deconstructor
House::~House() {}

//Getter
string House::getID() {
    return this->id;
}
string House::getOwner() {
    return this->owner;
}
string House::getLocation() {
    return this->location;
}
string House::getType() {
    return this->h_type;
}
double House::getRating() {
    return this->rating;
}
string House::getStatus() {
    return this->status;
}
//Setter
void House::setID(string id) {
    this->id = id;
}
void House::setOwner(string owner) {
    this->owner = owner;
}
void House::setLocation(string location) {
    this->location = location;
}
void House::setType(string h_type) {
    this->h_type = h_type;
}
void House::setRating(double rating) {
    this->rating = rating;
}
void House::setStatus(string status) {
    this->status = status;
}

//Set Item
void House::setAll(string id, string owner, string location, string h_type, double rating, string status) {
    setID(id);
    setOwner(owner);
    setLocation(location);
    setType(h_type);
    setRating(rating);
    setStatus(status);
}
//Print out
ostream& operator<< (ostream& out, House& e) {
    out << e.getID() << ", " << e.getOwner() << ", "
        << e.getLocation() << ", " << e.getType()
        << ", " << e.getRating() << ", " << e.getStatus()
        << endl;
    return out;
}//
// Created by user on 21/05/2022.
//

