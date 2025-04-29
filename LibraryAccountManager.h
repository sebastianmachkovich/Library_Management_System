#pragma once
#include "User.h"
#include "Admin.h"
#include <vector>
#include <string>

class LibraryAccountManager
{
public:
  LibraryAccountManager();
  ~LibraryAccountManager();
  bool registerUser(const User &user);
  bool removeUser(const std::string &libraryID);
  User *findUserByID(const std::string &libraryID);
  // TODO: Add methods for admin management, file I/O, and login
private:
  std::vector<User> users;
  std::vector<Admin> admins;
};
