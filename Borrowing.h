#pragma once
#include <string>
#include <vector>
#include "Book.h"

class Borrowing
{
  std::vector<std::string> borrowedBookIDs;
  std::string userID;

public:
  Borrowing(const std::string &userID);
  ~Borrowing();
  bool borrowBook(const std::string &bookID);
  bool returnBook(const std::string &bookID);
  std::vector<std::string> getBorrowedBooks() const;
  // TODO: Add file I/O and admin edit/search methods
};
