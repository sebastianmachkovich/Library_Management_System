#include "Borrowing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

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

void Borrowing::editBorrowing()
{
  cout << "[Edit Borrowing Record] (Not fully implemented yet)" << endl;
  // To be implemented: search and edit borrowing record
}

void Borrowing::searchBorrowing()
{
  cout << "[Search Borrowing Records] (Not fully implemented yet)" << endl;
  // To be implemented: search borrowing records
}
