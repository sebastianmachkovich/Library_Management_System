#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

using namespace std;

class Admin
{
private:
  string username;
  bool isLoggedIn;

public:
  Admin() : isLoggedIn(false) {}

  // Authentication
  bool login(const string &username, const string &password);
  void logout() { isLoggedIn = false; }

  // Inventory management
  bool addInventoryItem(const string &title, const string &author, const string &type);
  bool deleteInventoryItem(const string &itemId);
  bool editInventoryItem(const string &itemId, const string &field, const string &newValue);

  // User account management
  bool addUserAccount(const string &userData);
  bool deleteUserAccount(const string &libraryId);
  bool editUserDetails(const string &libraryId, const string &field, const string &newValue);
  int getActiveUserCount() const;

  // Borrowing management
  bool processBorrowing(const string &bookId, const string &userId);
  bool processReturn(const string &bookId);
  bool editBorrowingRecord(const string &borrowingId, const string &field, const string &newValue);
};

#endif 