#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

enum class UserType
{
  STUDENT,
  FACULTY,
  STAFF
};

// User Login class
class UserLogin
{
private:
  string libraryID;
  string password;

public:
  static bool authenticate(const string &libraryID, const string &password);
  void logout();
  void printUserSummary() const;
};

// Register New Users class
class RegisterNewUsers
{
public:
  bool registerUser(const string &firstName, const string &lastName,
                    const string &address, const string &phone,
                    const string &email, const string &password,
                    const string &institutionalID, UserType type);

private:
  bool validateInformation(const string &email, const string &phone) const;
  string generateLibraryID() const;
  bool saveUserToFile(const string &userData) const;
};

#endif 