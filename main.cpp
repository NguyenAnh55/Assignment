#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include "Member.h"
#include "House.h"
#include "validator.h"

using namespace std;
string file_txt_name;

vector<string> Register() {
    //create new member
    string input;

    vector<string> account;
    //validate user id
    cout << "Enter your user id:";
    getline(cin, input);
    while (isEmpty(input)) {
        cout << "\n" <<"Please choose an id:";
        getline(cin, input);
    }
    while (!isPositiveInteger(input)) {
        cout << "\n" << "Id must be a positive integer:";
        getline(cin, input);
    }
    while (ifMemberIdExisted(input)) {
        cout << "\n" << "This id has been taken, choose another one:";
        getline(cin, input);
    }
    account.push_back(input);
    input.clear();
    //input user name
    cout << "\n" << "Enter your user name:";
    getline(cin, input);
    while (isEmpty(input)) {
        cout << "\n" << "Please enter a name";
        getline(cin, input);
    }
    account.push_back(input);
    input.clear();
    //validate phone number
    cout << "\n" << "Enter your phone number:";
    getline(cin, input);
    while (isEmpty(input)) {
        cout << "\n" << "Please enter a phone number:";
        getline(cin, input);
    }
    while (!isValidPhoneNumberFormat(input)) {
        cout << "\n" << "Wrong format (10 digits):";
        getline(cin, input);
    }
    while (ifPhoneNumberExisted(input)) {
        cout << "\n" << "This number has been taken, use another one:";
        getline(cin, input);
    }
    account.push_back(input);
    input.clear();
    //validate location
    cout << "\n" << "Enter the house location:";
    getline(cin, input);
    while (isEmpty(input)) {
        cout << "\n" << "House location is required:";
        getline(cin, input);
    }
    while (ifLocationExisted(input)) {
        cout << "\n" << "This location has bees registered, enter another one:";
        getline(cin, input);
    }
    account.push_back(input);
    input.clear();
    //input house type
    cout << "\n" << "Enter the house type:";
    getline(cin, input);
    while (isEmpty(input)) {
        cout << "\n" << "House type is required:";
        getline(cin, input);
    }
    account.push_back(input);
    input.clear();

    return account;
}
string join(vector<string> const& strings, string delim)
{
    stringstream ss;
    copy(strings.begin(), strings.end(),
         ostream_iterator<string>(ss, delim.c_str()));
    return ss.str();
}
string toCSV() {
    Member* j = new Member;
    vector<string> account = Register();
    string delim = ",";
    string str = join(account, delim);
    string cred = to_string(j->getCred());
    string occ_rate = to_string(j->getOcc_rate());
    string reques_quan = to_string(j->getR_quan());
    string request = "None";
    string total = cred + ',' + occ_rate + ',' + reques_quan + ',' + request;
    //cout << str << endl;
    return str + total;
}
int apppendToCSV() {
    string newline = toCSV();
    ofstream foutput;
    ifstream finput;

    finput.open("Member.txt");
    foutput.open("Member.txt", ios::app);

    if (finput.is_open()) {
        foutput << newline << "\n";
    }
    finput.close();
    foutput.close();
    cout << "your account has been succesfully created" << endl;
    return 0;
}

void all_member(Member* m, int num) {
    cout << "Here are all the customers:" << endl;
    int index = 1;
    for (int i = 0; i < num; i++) {
        cout << "Customer number " << index << " :";
        m[i].printInfo();	//Print by using the function in Customer class
        index++;
    }
}

void all_house(House* h, int num) {
    cout << "Here are all house information: " << endl;
    int index = 1;
    for(int i =0; i < num; i++) {
        cout << "House number " << index << ":";
        cout << h[i];
        index++;
    }
}

void admin_menu(Member* m,int mem_num, House* h, int house_quant) {
    string username = "kell";
    string pwd = "12345";
    string username_input, pwd_input;
    int choice;
    cout << "Please enter admin username:";
    cin >> username_input;
    cin.ignore();
    cout << "Please enter admin password:";
    cin >> pwd_input;
    cin.ignore();
    while (username != username_input || pwd != pwd_input) {
        cout << "Wrong username or password!" << endl;
        cout << "Re-input username here:";
        cin >> username_input;
        cin.ignore();
        cout << "Re-input password here:";
        cin >> pwd_input;
        cin.ignore();
    }
    while (choice !=3) {
        cout << "\n" << "Here is the menu for admin:" << endl;
        cout << "1. View all users\n" << "2. View all houses\n" << "3. Log out" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                all_member(m, mem_num);
                break;
            case 2:
                all_house(h, house_quant);
                break;
            case 3:
                cout << "Bye bye!" << endl;
                break;
            default:
                cout << "Error: Please choose the number in the range from 1 to 3. \n";
                cout << "Please re-type your choice here:";
                cin >> choice;
                cin.ignore();
                break;
        }
    }
}

void non_mem_menu(Member* m,int mem_num, House* h, int house_quant) {
    int choice;
    while (choice !=3) {
        cout << "\n" << "Here is the menu for admin:" << endl;
        cout << "1. View all houses\n" << "2. Register member\n" << "3. Log out" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                cin.ignore();
                all_house(h, house_quant);
                break;
            case 2:
                cin.ignore();
                apppendToCSV();
                break;
            case 3:
                cin.ignore();
                cout << "Bye bye!" << endl;
                break;
            default:
                cout << "Error: Please choose the number in the range from 1 to 3. \n";
                cout << "Please re-type your choice here:";
                cin >> choice;
                cin.ignore();
                break;
        }
    }
}


void menu(Member* m,int mem_num, House* h, int house_quant) {
    int choice;
    int user_input = 0;
    string customer_type = "";
    cout << "EEET2482/COSC2082 ASSIGNMEN\nVACATION HOUSE EXCHANGE APPLICATION \n" << endl;
    //Display the menu and alow user choose the option
    cout << "Instructor: Mr. Linh Tran" << endl;
    cout << "Group: Group 30" << endl;
    cout << "s3803566, Ho Buu Quoc Phong." << endl;
    cout << "s3818484, Van Phuong Truc." << endl;
    cout << "s3877913, Nguyen Xuan Huy." << endl;
    cout << "s3924711, Nguyen Hong Anh." << endl;
    cout << "Use the app as: 1. Guest | 2. Member | 3. Admin\n";
    cout << "Enter your choice:";
    cin >> choice;
    cin.ignore(); //clear buffer before taking new line;
    while (choice < 1 || choice > 3) {
        cout << "Error: Please choose the number in the range from 1 to 3. \n";
        cout << "Please re-type your choice here:";
        cin >> choice;
        cin.ignore();
    }
    if (choice == 1) {
        non_mem_menu(m, mem_num,h,house_quant);
    }
    else if (choice == 2) {

    }else {
        admin_menu(m, mem_num,h,house_quant);
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
    file.close();
    return row;
}


void store_member_data(House* h, int house_num) {
    //Create empty variable to store data later
    string id, name, p_number, address, house_type, credit, occ_rating, request_quantity,request;
    file_txt_name="Member.txt";
    int row = read_file(file_txt_name);
    int index = 0;
    vector<string> id_list;
    vector<string> name_list;
    vector<string> p_list;
    vector<string> address_list;
    vector<string> house_type_list;
    vector<double> credit_list;
    vector<double> occ_rating_list;
    vector<int> request_quantity_list;
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

            getline(file, address, ',');
            address_list.push_back(address);

            getline(file, house_type, ',');
            house_type_list.push_back(house_type);

            getline(file, credit, ',');
            credit_list.push_back(stod(credit));

            getline(file, occ_rating, ',');
            occ_rating_list.push_back(stod(occ_rating));

            getline(file, request_quantity, ',');
            request_quantity_list.push_back(stoi(request_quantity));

            if (request_quantity_list[index] > 0) {
                for(int i=1; i <= request_quantity_list[index]; i++) {
                    if(i == request_quantity_list[index]) {
                        getline(file, request, '\n');
                        request_list.push_back(request);
                    }
                    else {
                        getline(file, request, ',');
                        request_list.push_back(request);
                    }
                }
                m[index] = Member(id_list[index], name_list[index], p_list[index], address_list[index], house_type_list[index], credit_list[index], occ_rating_list[index], request_quantity_list[index], request_list);
                request_list.clear();
                index++;
            } else{
                getline(file, request, '\n');
                m[index] = Member(id_list[index], name_list[index], p_list[index], address_list[index], house_type_list[index], credit_list[index], occ_rating_list[index], request_quantity_list[index], request_list);
                index++;
            }

        }
        file.close();
        menu(m,row,h,house_num);
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
    file_txt_name = "House.txt";
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
        string line;
        getline(file,line);
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
        store_member_data(h, row);
    }

    else {
        cerr << "Unable to open file!" << endl;
    }
}


int main(){
    store_house_data();
    return 0;
}
