#include <iostream>
#include "RegisterNewUser.h"
#include "Admin.h"
#include "UserLogin.h"
using namespace std;

void registerNewUser();
void adminLogin();
void userLogin();

int main()
{
  int choice;
  while (true)
  {
    cout << "\n===== Library Management System =====" << endl;
    cout << "1. Register New Users" << endl;
    cout << "2. Admin (Librarian) Login" << endl;
    cout << "3. User Login" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Add this line to clear the newline after menu input

    switch (choice)
    {
    case 1:
      registerNewUser();
      break;
    case 2:
      adminLogin();
      break;
    case 3:
      userLogin();
      break;
    case 4:
      cout << "Exiting..." << endl;
      return 0;
    default:
      cout << "Invalid choice. Try again." << endl;
    }
  }
  return 0;
}

void registerNewUser()
{
  RegisterNewUser reg;
  reg.registerUser();
}

void adminLogin()
{
  Admin admin;
  if (admin.login())
  {
    admin.adminMenu();
  }
}

void userLogin()
{
  UserLogin userLogin;
  string userId;
  if (userLogin.login(userId))
  {
    userLogin.userOptions(userId);
  }
}
