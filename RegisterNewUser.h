// RegisterNewUser.h - Declaration of the RegisterNewUser class
// Handles registration and validation for new users
#ifndef REGISTER_NEW_USER_H
#define REGISTER_NEW_USER_H
#include <string>
using namespace std;

// RegisterNewUser class provides user registration and validation methods
class RegisterNewUser
{
public:
  void registerUser(); // Register a new user

private:
  bool isValidEmail(const string &email); // Validate email format
  bool isValidPhone(const string &phone); // Validate phone number
  string generateLibraryID();             // Generate a unique library ID (no ctime)
};

#endif
