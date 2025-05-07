#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
using namespace std;

class UserLogin
{
public:
  bool login(string &userId);
  void printUserSummary(const string &userId);
};

#endif
