#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
using namespace std;

class UserLogin
{
public:
  bool login(string &userId);
  void userOptions(const string &userId);
  void printUserSummary(const string &userId);
  void borrowingHistory(const string &userId);
  Void currentlyBorrowed(const string &userId);
};

#endif
