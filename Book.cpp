// Book.cpp - Implementation of the Book class for the Library Management System
// Handles book data input and output
#include "Book.h"
#include <iostream>
using namespace std;

// Default constructor initializes year and copies to 0
Book::Book() : year(0), copies(0) {}

// Prompts the user to input book details
void Book::input()
{
  cout << "Enter Book ID: ";
  getline(cin, id);
  cout << "Enter Title: ";
  getline(cin, title);
  cout << "Enter Author: ";
  getline(cin, author);
  cout << "Enter Publisher: ";
  getline(cin, publisher);
  cout << "Enter Year: ";
  cin >> year;
  cout << "Enter Number of Copies: ";
  cin >> copies;
}

// Prints the book's details to the console
void Book::print() const
{
  cout << "ID: " << id << ", Title: " << title << ", Author: " << author
       << ", Publisher: " << publisher << ", Year: " << year
       << ", Copies: " << copies << endl;
}
