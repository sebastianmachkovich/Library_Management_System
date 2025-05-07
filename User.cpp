#include "User.h"
#include <fstream>
#include <sstream>
// Only essential includes for file and string operations

using namespace std;

// Authenticate user by checking credentials in users.csv
bool UserLogin::authenticate(const string &libraryID, const string &password)
{
  ifstream file("users.csv");
  string line;
  bool firstLine = true;
  while (getline(file, line))
  {
    if (firstLine)
    {
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

// Clear session data
void UserLogin::logout()
{
  libraryID.clear();
  password.clear();
}

// Print user summary and borrowing history
void UserLogin::printUserSummary() const
{
  ifstream userFile("users.csv");
  ifstream borrowingFile("borrowing.csv");
  string line;
  bool firstUserLine = true;
  bool firstBorrowingLine = true;
  while (getline(userFile, line))
  {
    if (firstUserLine)
    {
      firstUserLine = false;
      continue;
    }
    if (line.find(libraryID) == 0)
    {
      stringstream ss(line);
      string field;
      vector<string> fields;
      while (getline(ss, field, ','))
      {
        fields.push_back(field);
      }
      // Print user info (replace with return or log if not using cout)
      // cout << "\nUser Information:\n";
      // cout << "Library ID: " << fields[0] << "\n";
      // cout << "Name: " << fields[2] << " " << fields[3] << "\n";
      // cout << "Email: " << fields[5] << "\n";
      // cout << "Type: " << fields[8] << "\n";
      break;
    }
  }
  // Print borrowing history (replace with return or log if not using cout)
  // cout << "\nBorrowing History:\n";
  while (getline(borrowingFile, line))
  {
    if (firstBorrowingLine)
    {
      firstBorrowingLine = false;
      continue;
    }
    if (line.find(libraryID) != string::npos)
    {
      // cout << line << "\n";
    }
  }
}

// Validate email and phone format (simple checks)
bool RegisterNewUsers::validateInformation(const string &email, const string &phone) const
{
  // Basic checks for '@' in email and length of phone
  if (email.find('@') == string::npos)
    return false;
  if (phone.length() < 10)
    return false;
  return true;
}

// Generate a simple library ID (not using time or rand for simplicity)
string RegisterNewUsers::generateLibraryID() const
{
  static int counter = 1000;
  return "LIB" + to_string(counter++);
}

// Register a new user
bool RegisterNewUsers::registerUser(const string &firstName, const string &lastName,
                                    const string &address, const string &phone,
                                    const string &email, const string &password,
                                    const string &institutionalID, UserType type)
{
  if (!validateInformation(email, phone))
    return false;
  string libraryID = generateLibraryID();
  string userData = libraryID + "," + password + "," + firstName + "," + lastName + "," +
                    address + "," + email + "," + phone + "," + institutionalID + "," +
                    (type == UserType::STUDENT ? "STUDENT" : type == UserType::FACULTY ? "FACULTY"
                                                                                       : "STAFF");
  return saveUserToFile(userData);
}

// Save user data to users.csv
bool RegisterNewUsers::saveUserToFile(const string &userData) const
{
  ofstream file("users.csv", ios::app);
  if (!file.is_open())
    return false;
  file << userData << "\n";
  file.close();
  return true;
}