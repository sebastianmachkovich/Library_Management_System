#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>
#include "User.h"
#include "Book.h"
#include "Admin.h"
// Only essential includes for clarity

// LibrarySystem class manages the main application flow
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