#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "validator.h"
using namespace std;

// This file contains all the functions which validate the input string from the user in multiple field types.


bool isPositiveInteger(const string& s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
	return true;
}
bool isEmpty(const string& s) {
	if (s.length() == 0) return true;
	return false;
}
vector<string> getExistedIDs() {
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("Member.txt");
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
	vector<string> existedIds;
	//add existed id into a vector
	for (int i = 0; i < content.size(); i++)
	{
		existedIds.push_back(content[i][0]);
		//cout << content[i][0] << " ";
		//cout << "\n";
	}
	return existedIds;
}
vector<string> getExistedPhoneNumbers() {
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("Member.txt");
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
	vector<string> existedPhoneNumbers;
	//add existed id into a vector
	for (int i = 0; i < content.size(); i++)
	{
		existedPhoneNumbers.push_back(content[i][2]);
	}
	return existedPhoneNumbers;
}
vector<string> getExistedLocations() {
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("Member.txt");
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
	vector<string> existedLocations;
	//add existed id into a vector
	for (int i = 0; i < content.size(); i++)
	{
		existedLocations.push_back(content[i][3]);
	}
	return existedLocations;
}
bool ifMemberIdExisted(const string& s) {
	vector<string> existedIds = getExistedIDs();
	//check if the id has already existed, if yes input again	
	for (int i = 0; i < existedIds.size(); i++) {
		if (s.compare(existedIds[i]) == 0)
			return true;
	}
	return false;
}
bool ifPhoneNumberExisted(const string& s) {
	vector<string> existedPhoneNumbers = getExistedPhoneNumbers();
	//check if the id has already existed, if yes input again	
	for (int i = 0; i < existedPhoneNumbers.size(); i++) {
		if (s.compare(existedPhoneNumbers[i]) == 0)
			return true;
	}
	return false;
}
bool isValidPhoneNumberFormat(const string& s) {
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
	if (s.length() != 10) return false;
	return true;
}
bool ifLocationExisted(const string& s) {
	vector<string> existedLocations = getExistedLocations();
	//check if the id has already existed, if yes input again	
	for (int i = 0; i < existedLocations.size(); i++) {
		if (s.compare(existedLocations[i]) == 0)
			return true;
	}
	return false;
}