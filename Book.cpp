#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() : year(0), copies(0) {}

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

void Book::print() const
{
  cout << "ID: " << id << ", Title: " << title << ", Author: " << author
       << ", Publisher: " << publisher << ", Year: " << year
       << ", Copies: " << copies << endl;
}
