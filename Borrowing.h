// Borrowing.h - Declaration of the Borrowing class for the Library Management System
// Handles borrowing and returning of books
#ifndef BORROWING_H
#define BORROWING_H
#include <string>
using namespace std;

// Borrowing class provides methods for borrowing, returning, editing, and searching borrowing records
class Borrowing
{
public:
  void borrowBook();      // Borrow a book
  void returnBook();      // Return a borrowed book
  void editBorrowing();   // Edit a borrowing record
  void searchBorrowing(); // Search borrowing records
};

#endif
