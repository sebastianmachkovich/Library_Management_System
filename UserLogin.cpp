#include "UserLogin.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool UserLogin::login(string &userId)
{
  string email, password;
  cout << "\n[User Login]" << endl;
  cout << "Email: ";
  getline(cin, email);
  cout << "Password: ";
  getline(cin, password);
  ifstream file("users.csv");
  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    string type, first, last, address, phone, userEmail, userPass, instID, libID;
    getline(ss, type, ',');
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, address, ',');
    getline(ss, phone, ',');
    getline(ss, userEmail, ',');
    getline(ss, userPass, ',');
    getline(ss, instID, ',');
    getline(ss, libID, ',');
    if (userEmail == email && userPass == password)
    {
      userId = libID;
      cout << "Login successful!" << endl;
      return true;
    }
  }
  cout << "Invalid credentials." << endl;
  return false;
}

void UserLogin::printUserSummary(const string &userId)
{
  ifstream file("users.csv");
  string line;
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
    if (libID == userId)
    {
      cout << "\n===== User Summary =====" << endl;
      cout << "Name: " << first << " " << last << endl;
      cout << "Library ID: " << libID << endl;
      cout << "Type: " << type << endl;
      cout << "Address: " << address << endl;
      cout << "Phone: " << phone << endl;
      cout << "Email: " << email << endl;
      cout << "Institutional ID: " << instID << endl;
      cout << "\nBorrowing history: (Not implemented yet)" << endl;
      cout << "Currently borrowed books: (Not implemented yet)" << endl;
      return;
    }
  }
  cout << "User not found." << endl;
}
