// RegisterNewUser.cpp - Implementation of the RegisterNewUser class
// Handles user registration, email/phone validation, and library ID generation
#include "RegisterNewUser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

// Checks if the provided email contains '@' and '.'
bool RegisterNewUser::isValidEmail(const string &email)
{
  return email.find('@') != string::npos && email.find('.') != string::npos; 
}

// Checks if the phone number is all digits and of valid length
bool RegisterNewUser::isValidPhone(const string &phone)
{
  if (phone.length() < 7 || phone.length() > 15)
    return false;
  for (char c : phone)
    if (!isdigit(c))
      return false;
  return true;
}

// Generates a unique library ID by incrementing the highest existing ID in users.csv
string RegisterNewUser::generateLibraryID()
{
  ifstream file("users.csv");
  string line, lastID = "LIB10000";
  while (getline(file, line))
  {
    stringstream ss(line);
    string type, first, last, address, phone, email, password, instID, libID;
    getline(ss, type, ',');
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, address, ',');
    getline(ss, phone, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');
    getline(ss, instID, ',');
    getline(ss, libID, ',');
    if (libID.rfind("LIB", 0) == 0)
      lastID = libID;
  }
  // Extract numeric part and increment
  int num = stoi(lastID.substr(3));
  num++;
  return "LIB" + to_string(num);
}

// Prompts the user for registration details, validates input, and writes to users.csv
void RegisterNewUser::registerUser()
{
  string type, first, last, address, phone, email, password, instID;
  cout << "Enter user type (student/faculty/staff): ";
  getline(cin, type);
  cout << "First name: ";
  getline(cin, first);
  cout << "Last name: ";
  getline(cin, last);
  cout << "Address: ";
  getline(cin, address);
  do
  {
    cout << "Phone number: ";
    getline(cin, phone);
    if (!isValidPhone(phone))
      cout << "Invalid phone. Try again.\n";
  } while (!isValidPhone(phone));
  do
  {
    cout << "Email: ";
    getline(cin, email);
    if (!isValidEmail(email))
      cout << "Invalid email. Try again.\n";
  } while (!isValidEmail(email));
  cout << "Password: ";
  getline(cin, password);
  cout << "Institutional ID: ";
  getline(cin, instID);
  string libID = generateLibraryID();
  ofstream file("users.csv", ios::app);
  file << type << ',' << first << ',' << last << ',' << address << ',' << phone << ',' << email << ',' << password << ',' << instID << ',' << libID << '\n';
  file.close();
  cout << "Registration successful! Your Library ID is: " << libID << endl;
}
