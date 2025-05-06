#include "Admin.h"
#include "Book.h"#include "SearchFunction.h"
#include <fstream>
#include <sstream>

using namespace std;

bool Admin::login(const string &username, const string &password)
{
  ifstream file("librarians.csv");
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
    string storedUsername, storedPassword;

    getline(ss, storedUsername, ',');
    getline(ss, storedPassword, ',');

    if (username == storedUsername && password == storedPassword)
    {
      this->username = username;
      this->isLoggedIn = true;
      return true;
    }
  }
  return false;
}

bool Admin::addInventoryItem(const string &title, const string &author, const string &type)
{
  if (!isLoggedIn)
    return false;

  ItemType itemType;
  if (type == "BOOK")
    itemType = ItemType::BOOK;
  else if (type == "MAGAZINE")
    itemType = ItemType::MAGAZINE;
  else if (type == "JOURNAL")
    itemType = ItemType::JOURNAL;
  else
    return false;

  Book book(title, author, "Unknown", itemType);
  Book::saveToFile(book);
  return true;
}

bool Admin::deleteInventoryItem(const string &itemId)
{
  if (!isLoggedIn)
    return false;
  return Book::removeBook(itemId);
}

bool Admin::editInventoryItem(const string &itemId, const string &field, const string &newValue)
{
  if (!isLoggedIn)
    return false;

  ifstream inFile("books.csv");
  ofstream outFile("books_temp.csv");
  string line;
  bool found = false;
  vector<string> headers;
  bool isHeader = true;

  while (getline(inFile, line))
  {
    stringstream ss(line);
    string fieldVal;
    vector<string> fields;
    while (getline(ss, fieldVal, ','))
      fields.push_back(fieldVal);

    if (isHeader)
    {
      headers = fields;
      outFile << line << "\n";
      isHeader = false;
      continue;
    }

    if (fields[0] == itemId)
    {
      for (size_t i = 0; i < headers.size(); ++i)
      {
        if (headers[i] == field)
        {
          fields[i] = newValue;
          found = true;
        }
      }
    }
    outFile << fields[0];
    for (size_t i = 1; i < fields.size(); ++i)
      outFile << "," << fields[i];
    outFile << "\n";
  }
  inFile.close();
  outFile.close();

  if (found)
  {
    remove("books.csv");
    rename("books_temp.csv", "books.csv");
  }
  else
  {
    remove("books_temp.csv");
  }
  return found;
}

bool Admin::editUserDetails(const string &libraryId, const string &field, const string &newValue)
{
  if (!isLoggedIn)
    return false;

  ifstream inFile("users.csv");
  ofstream outFile("users_temp.csv");
  string line;
  bool found = false;
  vector<string> headers;
  bool isHeader = true;

  while (getline(inFile, line))
  {
    stringstream ss(line);
    string fieldVal;
    vector<string> fields;
    while (getline(ss, fieldVal, ','))
      fields.push_back(fieldVal);

    if (isHeader)
    {
      headers = fields;
      outFile << line << "\n";
      isHeader = false;
      continue;
    }

    if (fields[0] == libraryId)
    {
      for (size_t i = 0; i < headers.size(); ++i)
      {
        if (headers[i] == field)
        {
          fields[i] = newValue;
          found = true;
        }
      }
    }
    outFile << fields[0];
    for (size_t i = 1; i < fields.size(); ++i)
      outFile << "," << fields[i];
    outFile << "\n";
  }
  inFile.close();
  outFile.close();

  if (found)
  {
    remove("users.csv");
    rename("users_temp.csv", "users.csv");
  }
  else
  {
    remove("users_temp.csv");
  }
  return found;
}

int Admin::getActiveUserCount() const
{
  if (!isLoggedIn)
    return -1; 

  ifstream file("users.csv");
  string line;
  int count = -1; // Start at -1 to account for header

  while (getline(file, line))
  {
    count++;
  }

  return count;
}

bool Admin::addUserAccount(const string &userData)
{
  if (!isLoggedIn)
    return false;

  ofstream file("users.csv", ios::app);
  if (file.is_open())
  {
    file << userData << "\n";
    file.close();
    return true;
  }
  return false;
}

bool Admin::deleteUserAccount(const string &libraryId)
{
  if (!isLoggedIn)
    return false;

  ifstream inFile("users.csv");
  ofstream outFile("users_temp.csv");
  string line;
  bool found = false;

  while (getline(inFile, line))
  {
    if (line.substr(0, line.find(',')) != libraryId)
    {
      outFile << line << "\n";
    }
    else
    {
      found = true;
    }
  }

  inFile.close();
  outFile.close();

  if (found)
  {
    remove("users.csv");
    rename("users_temp.csv", "users.csv");
  }
  else
  {
    remove("users_temp.csv");
  }

  return found;
}