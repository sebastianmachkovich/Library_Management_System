#pragma once
#include "AbstractPerson.h"
#include <string>

class User : public AbstractPerson
{
protected:
  std::string firstName, lastName, address, phone, email, password, institutionalID, libraryID;
  static int userCount;

public:
  User();
  User(const std::string &firstName, const std::string &lastName, const std::string &address, const std::string &phone, const std::string &email, const std::string &password, const std::string &institutionalID);
  User(const User &);
  virtual ~User();
  virtual std::string getName() const override;
  virtual std::string getID() const override;
  static int getUserCount();
  void setAddress(const std::string &addr);
  std::string getAddress() const;
  void setPhone(const std::string &ph);
  std::string getPhone() const;
  // TODO: Add more getters/setters and file I/O methods
};