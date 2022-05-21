#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "Validator.h"


using namespace std;


int showInfor()
{
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("House.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file\n";

	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
vector<string> Register() {
	//create new member
	string input;
	
	vector<string> account;
	//validate user id
	cout << "enter your user id" << endl;
	getline(cin, input);
	while (isEmpty(input)) {
		cout << "please choose an id" << endl;
		getline(cin, input);
	}
	while (!isPositiveInteger(input)) {
		cout << "id must be a positive integer" << endl;
		getline(cin, input);
	}
	while (ifMemberIdExisted(input)) {
		cout << "this id has been taken, choose another one" << endl;
		getline(cin, input);
	}
	account.push_back(input);
	input.clear();
	//input user name
	cout << "enter your user name" << endl;
	getline(cin, input);
	while (isEmpty(input)) {
		cout << "please enter a name" << endl;
		getline(cin, input);
	}
	account.push_back(input);
	input.clear();
	//validate phone number
	cout << "enter your phone number" << endl;
	getline(cin, input);
	while (isEmpty(input)) {
		cout << "please enter a phone number" << endl;
		getline(cin, input);
	}
	while (!isValidPhoneNumberFormat(input)) {
		cout << "wrong format (10 digits)" << endl;
		getline(cin, input);
	}
	while (ifPhoneNumberExisted(input)) {
		cout << "this number has been taken, use another one" << endl;
		getline(cin, input);
	}
	account.push_back(input);
	input.clear();
	//validate location
	cout << "enter the house location" << endl;
	getline(cin, input);
	while (isEmpty(input)) {
		cout << "house location is required" << endl;
		getline(cin, input);
	}
	while (ifLocationExisted(input)) {
		cout << "this location has bees registered, enter another one" << endl;
		getline(cin, input);
	}
	account.push_back(input);
	input.clear();
	//input house type
	cout << "enter the house type" << endl;
	getline(cin, input);
	while (isEmpty(input)) {
		cout << "house type is required" << endl;
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
	vector<string> account = Register();
	string delim = ",";
	string str = join(account, delim);
	//cout << str << endl;
	return str + "500,0, ";
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
void logOut() {
	cout << "you have logged out off the system" << endl;
}

int main() {
	showInfor();
	//apppendToCSV();
	return 0;
}
