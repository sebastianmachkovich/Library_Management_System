#pragma once
#include <string>

class AbstractPerson
{
public:
  virtual std::string getName() const = 0;
  virtual std::string getID() const = 0;
  virtual ~AbstractPerson() {}
};
