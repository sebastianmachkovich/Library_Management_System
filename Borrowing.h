#ifndef BORROWING_H
#define BORROWING_H

#include <string>
#include <vector>

using namespace std;

class Borrowing
{
private:
  static const int MAX_BOOKS = 4;

public:
  // Borrowing operations
  bool borrowBook(const string &bookId, const string &userId);
  bool returnBook(const string &bookId);
  bool updateInventory(const string &bookId, bool isReturning);
  bool editBorrowingRecord(const string &borrowId);

  // Record management
  vector<string> getBorrowerHistory(const string &userId) const;
  int getCurrentBorrowCount(const string &userId) const;
  bool isBorrowingLimitReached(const string &userId) const;
};

#endif 