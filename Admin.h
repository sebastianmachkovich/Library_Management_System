#pragma once
#include "AbstractPerson.h"
#include <string>

class Admin : public AbstractPerson
{
  std::string name, password;

public:
  Admin();
  Admin(const std::string &name, const std::string &password);
  virtual ~Admin();
  virtual std::string getName() const override;
  virtual std::string getID() const override;
  bool authenticate(const std::string &inputName, const std::string &inputPassword) const;
  // TODO: Add admin-specific methods (add/delete inventory, users, etc.)
};
