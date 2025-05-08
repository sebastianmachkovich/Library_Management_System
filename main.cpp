// main.cpp - Entry point for the Library Management System
// Handles the main menu and user/admin navigation
#include <iostream>
#include "RegisterNewUser.h"
#include "Admin.h"
#include "UserLogin.h"
using namespace std;

// Function prototypes for menu actions
void registerNewUser(); // Register a new user
void adminLogin();      // Admin login and menu
void userLogin();       // User login and menu

int main()
{
  int choice;
  while (true)
  {
    // Main menu for the system
    cout << "\n===== Library Management System =====" << endl;
    cout << "1. Register New Users" << endl;
    cout << "2. Admin (Librarian) Login" << endl;
    cout << "3. User Login" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
      registerNewUser(); // Register a new user
      break;
    case 2:
      adminLogin(); // Admin login and menu
      break;
    case 3:
      userLogin(); // User login and menu
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

// Calls the registration process for a new user
void registerNewUser()
{
  RegisterNewUser reg;
  reg.registerUser();
}

// Handles admin login and, if successful, shows the admin menu
void adminLogin()
{
  Admin admin;
  if (admin.login())
  {
    admin.adminMenu();
  }
}

// Handles user login and, if successful, shows the user menu
void userLogin()
{
  Person *user = new UserLogin(); // Use base class pointer for polymorphism
  string userId; 
  UserLogin *userLogin = dynamic_cast<UserLogin *>(user);
  if (userLogin && userLogin->login(userId))
  {
    user->printUserSummary();
    userLogin->userOptions(userId); 
  }
  delete user; 
}
