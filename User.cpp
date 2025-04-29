#include "User.h"
#include <iostream>

int User::userCount = 0;

User::User() : firstName(""), lastName(""), address(""), phone(""), email(""), password(""), institutionalID(""), libraryID("")
{
  ++userCount;
}

User::User(const std::string &f, const std::string &l, const std::string &addr, const std::string &ph, const std::string &em, const std::string &pw, const std::string &instID)
    : firstName(f), lastName(l), address(addr), phone(ph), email(em), password(pw), institutionalID(instID)
{
  // TODO: Generate unique libraryID
  ++userCount;
}

User::User(const User &other)
{
  firstName = other.firstName;
  lastName = other.lastName;
  address = other.address;
  phone = other.phone;
  email = other.email;
  password = other.password;
  institutionalID = other.institutionalID;
  libraryID = other.libraryID;
  ++userCount;
}

User::~User()
{
  --userCount;
}

std::string User::getName() const { return firstName + " " + lastName; }
std::string User::getID() const { return libraryID; }
int User::getUserCount() { return userCount; }
void User::setAddress(const std::string &addr) { address = addr; }
std::string User::getAddress() const { return address; }
void User::setPhone(const std::string &ph) { phone = ph; }
std::string User::getPhone() const { return phone; }
// TODO: Implement file I/O and more member functions