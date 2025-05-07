#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book
{
public:
  string id;
  string title;
  string author;
  string publisher;
  int year;
  int copies;
  Book();
  void input();
  void print() const;
};

#endif
