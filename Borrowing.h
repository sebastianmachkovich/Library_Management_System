#ifndef BORROWING_H
#define BORROWING_H

#include <string>
#include <vector>
// Only essential includes for clarity

// Borrowing class handles book borrowing operations
class Borrowing
{
private:
  static const int MAX_BOOKS = 4;

public:
  // Borrowing operations
  bool borrowBook(const std::string &bookId, const std::string &userId);
  bool returnBook(const std::string &bookId);
  bool updateInventory(const std::string &bookId, bool isReturning);
  bool editBorrowingRecord(const std::string &borrowId);

  // Record management
  std::vector<std::string> getBorrowerHistory(const std::string &userId) const;
  int getCurrentBorrowCount(const std::string &userId) const;
  bool isBorrowingLimitReached(const std::string &userId) const;
};

#endif