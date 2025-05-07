#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
// Only essential includes for clarity

// Enum for user types
enum class UserType
{
  STUDENT,
  FACULTY,
  STAFF
};

// User class represents a library user
class User
{
private:
  std::string libraryID;
  std::string firstName;
  std::string lastName;
  std::string address;
  std::string phone;
  std::string email;
  std::string password;
  UserType type;

public:
  User(const std::string &id, const std::string &fName, const std::string &lName,
       const std::string &addr, const std::string &ph, const std::string &mail,
       const std::string &pwd, UserType t)
      : libraryID(id), firstName(fName), lastName(lName),
        address(addr), phone(ph), email(mail),
        password(pwd), type(t) {}

  // Getters
  std::string getLibraryID() const { return libraryID; }
  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  UserType getUserType() const { return type; }

  // Authentication method
  bool authenticate(const std::string &pwd) const { return password == pwd; }
};

// Handles user login
class UserLogin
{
private:
  std::string libraryID;
  std::string password;

public:
  static bool authenticate(const std::string &libraryID, const std::string &password);
  void logout();
  void printUserSummary() const;
};

// Handles new user registration
class RegisterNewUsers
{
public:
  bool registerUser(const std::string &firstName, const std::string &lastName,
                    const std::string &address, const std::string &phone,
                    const std::string &email, const std::string &password,
                    const std::string &institutionalID, UserType type);

private:
  bool validateInformation(const std::string &email, const std::string &phone) const;
  std::string generateLibraryID() const;
  bool saveUserToFile(const std::string &userData) const;
};

#endif