#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
using namespace std;

class UserLogin
{
public:
  string *firstName;
  string *lastName;
  UserLogin();
  UserLogin(const UserLogin &other);
  ~UserLogin();
  bool login(string &userId);
  void userOptions(const string &userId);
  void printUserSummary(const string &userId);
  void borrowingHistory(const string &userId);
  void currentlyBorrowed(const string &userId);
};

#endif
