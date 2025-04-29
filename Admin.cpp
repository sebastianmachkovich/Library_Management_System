#include "Admin.h"

Admin::Admin() : name(""), password("") {}

Admin::Admin(const std::string &n, const std::string &p) : name(n), password(p) {}

Admin::~Admin() {}

std::string Admin::getName() const { return name; }
std::string Admin::getID() const { return name; }

bool Admin::authenticate(const std::string &inputName, const std::string &inputPassword) const
{
  return (inputName == name && inputPassword == password);
}

// TODO: Implement admin-specific methods for inventory and user management