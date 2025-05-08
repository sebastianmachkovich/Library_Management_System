// Borrowing.cpp - Implementation of the Borrowing class for the Library Management System
// Handles borrowing, returning, editing, and searching borrowing records
#include "Borrowing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

// Checks if a user can borrow more books (limit: 4 active borrowings)
bool userCanBorrow(const string &userId)
{
  ifstream file("borrowings.csv");
  string line;
  int count = 0;
  while (getline(file, line))
  {
    stringstream ss(line);
    string uid, bid, date, returned;
    getline(ss, uid, ',');
    getline(ss, bid, ',');
    getline(ss, date, ',');
    getline(ss, returned, ',');
    if (uid == userId && returned != "Y")
      count++;
  }
  return count < 4;
}

// Checks if a book is available (copies > 0)
bool bookAvailable(const string &bookId)
{
  ifstream file("books.csv");
  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    string id, title, author, publisher, year, copies;
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, publisher, ',');
    getline(ss, year, ',');
    getline(ss, copies, ',');
    if (id == bookId && stoi(copies) > 0)
      return true;
  }
  return false;
}

// Updates the number of copies for a book by delta (can be positive or negative)
void updateBookCopies(const string &bookId, int delta)
{
  ifstream inFile("books.csv");
  ofstream outFile("books_tmp.csv");
  string line;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string id, title, author, publisher, year, copies;
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, publisher, ',');
    getline(ss, year, ',');
    getline(ss, copies, ',');
    if (id == bookId)
    {
      int newCopies = stoi(copies) + delta;
      if (newCopies < 0)
        newCopies = 0;
      outFile << id << ',' << title << ',' << author << ',' << publisher << ',' << year << ',' << newCopies << '\n';
    }
    else
    {
      outFile << line << '\n';
    }
  }
  inFile.close();
  outFile.close();
  remove("books.csv");
  rename("books_tmp.csv", "books.csv");
}

// Allows a user to borrow a book if eligible and available
void Borrowing::borrowBook()
{
  string userId, bookId;
  cout << "Enter Library ID: ";
  getline(cin, userId);
  cout << "Enter Book ID: ";
  getline(cin, bookId);
  if (!userCanBorrow(userId))
  {
    cout << "User has already borrowed 4 books." << endl;
    return;
  }
  if (!bookAvailable(bookId))
  {
    cout << "Book not available." << endl;
    return;
  }
  // Get current date
  time_t t = time(0);
  tm *now = localtime(&t);
  char dateStr[11];
  strftime(dateStr, 11, "%Y-%m-%d", now);
  ofstream file("borrowings.csv", ios::app);
  file << userId << ',' << bookId << ',' << dateStr << ",N\n";
  file.close();
  updateBookCopies(bookId, -1);
  cout << "Book borrowed successfully!" << endl;
}

// Allows a user to return a borrowed book
void Borrowing::returnBook()
{
  string userId, bookId;
  cout << "Enter Library ID: ";
  getline(cin, userId);
  cout << "Enter Book ID: ";
  getline(cin, bookId);
  ifstream inFile("borrowings.csv");
  ofstream outFile("borrowings_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string uid, bid, date, returned;
    getline(ss, uid, ',');
    getline(ss, bid, ',');
    getline(ss, date, ',');
    getline(ss, returned, ',');
    if (uid == userId && bid == bookId && returned != "Y")
    {
      outFile << uid << ',' << bid << ',' << date << ",Y\n";
      found = true;
    }
    else
    {
      outFile << line << '\n';
    }
  }
  inFile.close();
  outFile.close();
  remove("borrowings.csv");
  rename("borrowings_tmp.csv", "borrowings.csv");
  if (found)
  {
    updateBookCopies(bookId, 1);
    cout << "Book returned successfully!" << endl;
  }
  else
  {
    cout << "No active borrowing record found for this user and book." << endl;
  }
}

// Allows editing the return status of a borrowing record
void Borrowing::editBorrowing()
{
  string userId, bookId;
  cout << "Enter Library ID to edit: ";
  getline(cin, userId);
  cout << "Enter Book ID to edit: ";
  getline(cin, bookId);
  ifstream inFile("borrowings.csv");
  ofstream outFile("borrowings_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string uid, bid, date, returned;
    getline(ss, uid, ',');
    getline(ss, bid, ',');
    getline(ss, date, ',');
    getline(ss, returned, ',');
    if (uid == userId && bid == bookId)
    {
      found = true;
      cout << "Current return status: " << returned << endl;
      cout << "Enter new return status (Y/N): ";
      string newStatus;
      getline(cin, newStatus);
      if (newStatus != "Y" && newStatus != "N")
      {
        cout << "Invalid status. Keeping old status." << endl;
        newStatus = returned;
      }
      outFile << uid << ',' << bid << ',' << date << ',' << newStatus << '\n';
    }
    else
    {
      outFile << line << '\n';
    }
  }
  inFile.close();
  outFile.close();
  remove("borrowings.csv");
  rename("borrowings_tmp.csv", "borrowings.csv");
  if (found)
    cout << "Borrowing record updated." << endl;
  else
    cout << "Borrowing record not found." << endl;
}

// Allows searching borrowing records by Library ID or Book ID
void Borrowing::searchBorrowing()
{
  cout << "Search by: 1. Library ID  2. Book ID\nEnter option: ";
  int option;
  cin >> option;
  cin.ignore();
  string query;
  if (option == 1)
  {
    cout << "Enter Library ID: ";
    getline(cin, query);
  }
  else if (option == 2)
  {
    cout << "Enter Book ID: ";
    getline(cin, query);
  }
  else
  {
    cout << "Invalid option." << endl;
    return;
  }
  ifstream file("borrowings.csv");
  string line;
  bool found = false;
  while (getline(file, line))
  {
    stringstream ss(line);
    string uid, bid, date, returned;
    getline(ss, uid, ',');
    getline(ss, bid, ',');
    getline(ss, date, ',');
    getline(ss, returned, ',');
    if ((option == 1 && uid == query) || (option == 2 && bid == query))
    {
      cout << "Library ID: " << uid << ", Book ID: " << bid << ", Date: " << date << ", Returned: " << returned << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No matching borrowing records found." << endl;
  }
}
