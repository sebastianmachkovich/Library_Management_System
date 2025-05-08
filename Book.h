// Book.h - Declaration of the Book class for the Library Management System
// Represents a book and its attributes
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

// Book class holds information about a single book
class Book
{
public:
  string id;          // Unique identifier for the book
  string title;       // Title of the book
  string author;      // Author of the book
  string publisher;   // Publisher of the book
  int year;           // Year of publication
  int copies;         // Number of copies available
  Book();             // Constructor
  void input();       // Input book details from user
  void print() const; // Print book details
};

#endif
