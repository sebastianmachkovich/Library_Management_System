#ifndef REGISTER_NEW_USER_H
#define REGISTER_NEW_USER_H
#include <string>
using namespace std;

class RegisterNewUser
{
public:
  void registerUser();

private:
  bool isValidEmail(const string &email);
  bool isValidPhone(const string &phone);
  string generateLibraryID();
};

#endif
