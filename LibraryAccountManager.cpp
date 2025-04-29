#include "LibraryAccountManager.h"

LibraryAccountManager::LibraryAccountManager()
{
  // TODO: Load users and admins from files
}

LibraryAccountManager::~LibraryAccountManager()
{
  // TODO: Save users and admins to files
}

bool LibraryAccountManager::registerUser(const User &user)
{
  users.push_back(user);
  // TODO: Save to file
  return true;
}

bool LibraryAccountManager::removeUser(const std::string &libraryID)
{
  for (auto it = users.begin(); it != users.end(); ++it)
  {
    if (it->getID() == libraryID)
    {
      users.erase(it);
      // TODO: Update file
      return true;
    }
  }
  return false;
}

User *LibraryAccountManager::findUserByID(const std::string &libraryID)
{
  for (auto &user : users)
  {
    if (user.getID() == libraryID)
    {
      return &user;
    }
  }
  return nullptr;
}

// TODO: Implement admin management, login, and file I/O methods