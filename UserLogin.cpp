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
      firstName = first;
      lastName = last;
      cout << "Login successful!" << endl;
      return true;
    }
  }
  cout << "Invalid credentials." << endl;
  return false;
}

void UserLogin::userOptions(const string &userId)
{
  int choice;
  while (true)
  {
    cout << "\n===== User Portal =====" << endl;
    cout << "Welcome " << firstName << " " << lastName << endl;
    cout << "1. Account information" << endl;
    cout << "2. Borrowing history" << endl;
    cout << "3. Currently borrowed books" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 4)
      return; // Exit immediately, no cin.ignore()
    cin.ignore();

    switch (choice)
    {
    case 1:
      UserLogin::printUserSummary(userId);
      break;
    case 2:
      UserLogin::borrowingHistory(userId);
      break;
    case 3:
      UserLogin::currentlyBorrowed(userId);
      break;
    default:
      cout << "Invalid choice. Try again." << endl;
    }
  }
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
      return;
    }
  }
  cout << "User not found." << endl;
}

void UserLogin::borrowingHistory(const string &userId)
{
  bool found = false;
  if (found)
  {
    cout << "You have borrowed: " << endl;
  }
  ifstream file("borrowings.csv");
  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    string userID, bookID, dateBorrowed, isReturned;
    getline(ss, userID, ',');
    getline(ss, bookID, ',');
    getline(ss, dateBorrowed, ',');
    getline(ss, isReturned, ',');

    if (userId == userID)
    {
      found = true;
      // Lookup book title
      ifstream booksFile("books.csv");
      string bookLine, bookTitle = "Unknown Title";
      while (getline(booksFile, bookLine))
      {
        stringstream bookSS(bookLine);
        string id, title;
        getline(bookSS, id, ',');
        getline(bookSS, title, ',');
        if (id == bookID)
        {
          bookTitle = title;
          break;
        }
      }
      booksFile.close();
      cout << bookTitle << " (ID: " << bookID << ") on " << dateBorrowed;
      if (isReturned == "Y")
      {
        cout << " and it is returned" << endl;
      }
      else
      {
        cout << " and it is not returned" << endl;
      }
    }
  }
  if (!found)
  {
    cout << "You have no borrowing history." << endl;
  }
}

void UserLogin::currentlyBorrowed(const string &userId)
{
  bool found = false;
  if (found)
  {
    cout << "You are currently borrowing: " << endl;
  }
  ifstream file("borrowings.csv");
  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    string userID, bookID, dateBorrowed, isReturned;
    getline(ss, userID, ',');
    getline(ss, bookID, ',');
    getline(ss, dateBorrowed, ',');
    getline(ss, isReturned, ',');

    if (userId == userID && isReturned == "N")
    {
      found = true;
      // Lookup book title
      ifstream booksFile("books.csv");
      string bookLine, bookTitle = "Unknown Title";
      while (getline(booksFile, bookLine))
      {
        stringstream bookSS(bookLine);
        string id, title;
        getline(bookSS, id, ',');
        getline(bookSS, title, ',');
        if (id == bookID)
        {
          bookTitle = title;
          break;
        }
      }
      booksFile.close();
      cout << bookTitle << " (ID: " << bookID << ") on " << dateBorrowed << endl;
    }
  }
  if (!found)
  {
    cout << "You are not currently borrowing any books." << endl;
  }
}
