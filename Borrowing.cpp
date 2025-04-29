#include "Borrowing.h"

Borrowing::Borrowing(const std::string &userID) : userID(userID) {}

Borrowing::~Borrowing() {}

bool Borrowing::borrowBook(const std::string &bookID)
{
  if (borrowedBookIDs.size() >= 4)
    return false;
  borrowedBookIDs.push_back(bookID);
  // TODO: Update inventory and file
  return true;
}

bool Borrowing::returnBook(const std::string &bookID)
{
  for (auto it = borrowedBookIDs.begin(); it != borrowedBookIDs.end(); ++it)
  {
    if (*it == bookID)
    {
      borrowedBookIDs.erase(it);
      // TODO: Update inventory and file
      return true;
    }
  }
  return false;
}

std::vector<std::string> Borrowing::getBorrowedBooks() const
{
  return borrowedBookIDs;
}

// TODO: Implement admin edit/search and file I/O methods