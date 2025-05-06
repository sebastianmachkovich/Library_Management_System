#include "User.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>
#include <iostream>

using namespace std;

bool UserLogin::authenticate(const string &libraryID, const string &password)
{
  ifstream file("users.csv");
  string line;
  bool firstLine = true;

  while (getline(file, line))
  {
    if (firstLine)
    { // Skip header
      firstLine = false;
      continue;
    }

    stringstream ss(line);
    string id, pass;

    getline(ss, id, ',');
    getline(ss, pass, ',');

    if (libraryID == id && password == pass)
    {
      return true;
    }
  }
  return false;
}

void UserLogin::logout()
{
  // Clear any session data
  libraryID.clear();
  password.clear();
}

void UserLogin::printUserSummary() const
{
  ifstream userFile("users.csv");
  ifstream borrowingFile("borrowing.csv");
  string line;

  // Find and print user details
  while (getline(userFile, line))
  {
    if (line.find(libraryID) == 0)
    {
      stringstream ss(line);
      string field;
      vector<string> fields;

      while (getline(ss, field, ','))
      {
        fields.push_back(field);
      }

      cout << "\nUser Information:\n";
      cout << "Library ID: " << fields[0] << "\n";
      cout << "Name: " << fields[2] << " " << fields[3] << "\n";
      cout << "Email: " << fields[5] << "\n";
      cout << "Type: " << fields[8] << "\n";
      break;
    }
  }

  // Print borrowing history
  cout << "\nBorrowing History:\n";
  while (getline(borrowingFile, line))
  {
    if (line.find(libraryID) != string::npos)
    {
      cout << line << "\n";
    }
  }
}

bool RegisterNewUsers::validateInformation(const string &email, const string &phone) const
{
  // Email validation using regex
  const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  if (!regex_match(email, emailPattern))
  {
    return false;
  }

  // Phone validation (assuming format: XXX-XXX-XXXX or XXXXXXXXXX)
  const regex phonePattern("\\d{10}|\\d{3}[-.]\\d{3}[-.]\\d{4}");
  if (!regex_match(phone, phonePattern))
  {
    return false;
  }

  return true;
}

string RegisterNewUsers::generateLibraryID() const
{
  // Generate a unique library ID based on timestamp and random number
  time_t now = time(0);
  return "LIB" + to_string(now % 10000) + to_string(rand() % 1000);
}

bool RegisterNewUsers::registerUser(const string &firstName, const string &lastName,
                                    const string &address, const string &phone,
                                    const string &email, const string &password,
                                    const string &institutionalID, UserType type)
{
  if (!validateInformation(email, phone))
  {
    return false;
  }

  string libraryID = generateLibraryID();
  string userData = libraryID + "," + password + "," + firstName + "," + lastName + "," +
                    address + "," + email + "," + phone + "," + institutionalID + "," +
                    (type == UserType::STUDENT ? "STUDENT" : type == UserType::FACULTY ? "FACULTY"
                                                                                       : "STAFF");

  return saveUserToFile(userData);
}

bool RegisterNewUsers::saveUserToFile(const string &userData) const
{
  ofstream file("users.csv", ios::app);
  if (!file.is_open())
  {
    return false;
  }

  file << userData << "\n";
  file.close();
  return true;
}