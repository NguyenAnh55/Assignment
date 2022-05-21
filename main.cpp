#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Member.h"
#include "House.h"
#include "Member.cpp"
#include "House.cpp"

using namespace std;
string file_txt_name;



void all_customer(Member* m, int num) {
    cout << "Here are all the customers:" << endl;
    int index = 1;
    for (int i = 0; i < num; i++) {
        cout << "Customer number " << index << " :";
        m[i].printInfo();	//Print by using the function in Customer class
        index++;
    }
}

int read_file(string file_name) {
    int row = 0;
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        getline(file,line);
        while (!file.eof()) {
            getline(file, line);
            row++;
        }
    }
    else {
        file.close();
        cerr << "Error: File cannot be read";
        exit(1);
    }
    cout << "Hello";
    file.close();
    return row;
}

void store_member_data() {
    //Create empty variable to store data later
    string id, name, p_number, h_location, credit, occ_rating, request;
    file_txt_name="Member.txt";
    int row = read_file(file_txt_name);
    int index = 0;
    vector<string> id_list;
    vector<string> name_list;
    vector<string> p_list;
    vector<string> h_location_list;
    vector<double> credit_list;
    vector<double> occ_rating_list;
    vector<string> request_list;
    Member* m = new Member[row];

    ifstream file(file_txt_name);
    if (file.is_open()) {
        string line;
        getline(file,line);
        while (!file.eof())
        {//Begin append
            getline(file, id, ',');
            id_list.push_back(id);

            getline(file, name, ',');
            name_list.push_back(name);

            getline(file, p_number, ',');
            p_list.push_back(p_number);

            getline(file, h_location, ',');
            h_location_list.push_back(h_location);

            getline(file, credit, ',');
            credit_list.push_back(stod(credit));

            getline(file, occ_rating, ',');
            occ_rating_list.push_back(stod(occ_rating));

            getline(file, request, '\n');
            request_list.push_back(request);

            m[index] = Member(id_list[index], name_list[index], p_list[index], h_location_list[index], credit_list[index], occ_rating_list[index], request_list);
            request_list.clear();
            index++;
        }
        file.close();
        all_customer(m, row);
    }
    else {
        file.close();
        cerr << "Unable to open file!" << endl;
    }
    //Calling main_menu function with includes all program's functions
}

//Function to store customers data on an array
void store_house_data() {
    //Create empty variable to store data later
    string id, owner, location, h_type, rating, status;
    file_txt_name = "house.txt";
    int row = read_file(file_txt_name);
    vector<string> id_list;
    vector<string> owner_list;
    vector<string> location_list;
    vector<string> type_list;
    vector<double> rating_list;
    vector<string> status_list;
    House* h = new House[row];

    int i = 0;
    int index = 0;
    ifstream file(file_txt_name);
    if (file.is_open()) {

        while (!file.eof())
        {
            getline(file, id, ',');
            id_list.push_back(id);
            getline(file, owner, ',');
            owner_list.push_back(owner);
            getline(file, location, ',');
            location_list.push_back(location);
            getline(file, h_type, ',');
            type_list.push_back(h_type);
            getline(file, rating, ',');
            rating_list.push_back(stod(rating));
            getline(file, status, '\n');
            status_list.push_back(status);
            h[index] = House(id_list[index], owner_list[index], location_list[index], type_list[index], rating[index], status_list[index]);
            index++;
        }
        file.close();
    }

    else {
        cerr << "Unable to open file!" << endl;
    }
}


int main(){
    //cout << "Testing";
    store_member_data();
    return 0;
}