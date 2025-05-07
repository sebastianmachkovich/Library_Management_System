#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;

class Admin
{
public:
  bool login();
  void adminMenu();
  void addBook();
  void deleteBook();
  void editBook();
  void addUser();
  void deleteUser();
  void editUser();
  void viewTotalActiveUsers();
  void searchInventory();
  void searchUsers();
};

#endif
