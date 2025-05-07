#include "RegisterNewUser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cctype>

using namespace std;

bool RegisterNewUser::isValidEmail(const string &email)
{
  return email.find('@') != string::npos && email.find('.') != string::npos;
}

bool RegisterNewUser::isValidPhone(const string &phone)
{
  if (phone.length() < 7 || phone.length() > 15)
    return false;
  for (char c : phone)
    if (!isdigit(c))
      return false;
  return true;
}

string RegisterNewUser::generateLibraryID()
{
  srand(time(0));
  string id = "LIB";
  for (int i = 0; i < 5; ++i)
    id += to_string(rand() % 10);
  return id;
}

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
