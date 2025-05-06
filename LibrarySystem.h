#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>

// Forward declarations
class User;
class Admin;
class Book;

// Include User.h first since other classes depend on it
#include "User.h"
#include "Book.h"
#include "Admin.h"

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