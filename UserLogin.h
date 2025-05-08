// UserLogin.h - Declaration of the UserLogin class
// Handles user login, account management, and borrowing history
#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
#include "Person.h"
using namespace std;

// UserLogin class inherits from Person and manages user login and options
class UserLogin : public Person
{
public:
  static int userCount;                         // Tracks number of UserLogin objects
  string *firstName;                            // Pointer to user's first name
  string *lastName;                             // Pointer to user's last name
  UserLogin();                                  // Default constructor
  UserLogin(const UserLogin &other);            // Copy constructor
  ~UserLogin();                                 // Destructor
  bool login(string &userId);                   // Handles user login
  void userOptions(const string &userId);       // User menu/options
  void printUserSummary() override;             // Print summary for current user
  void printUserSummary(const string &userId);  // Print summary for given userId
  void borrowingHistory(const string &userId);  // Show borrowing history
  void currentlyBorrowed(const string &userId); // Show currently borrowed books
};

#endif
