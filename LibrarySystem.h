#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include "Admin.h"
#include "User.h"
#include "Book.h"

class LibrarySystem
{
private:
  Admin admin;
  User *currentUser;

  // Private menu handlers
  void handleAdminLogin();
  void handleUserLogin();
  void handleRegistration();
  void handleAdminMenu();
  void handleUserMenu();

public:
  LibrarySystem() : currentUser(nullptr) {}
  ~LibrarySystem() { delete currentUser; }

  void run();
  void displayMainMenu() const;
};

#endif 