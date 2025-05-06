#include <iostream>
#include <limits>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Borrowing.h"
#include "SearchFunction.h"
#include "Book.h"

using namespace std;

void displayMainMenu()
{
  cout << "\nLibrary Management System\n";
  cout << "=======================\n";
  cout << "1. Register New Users\n";
  cout << "2. Admin (Librarian) Login\n";
  cout << "3. User Login\n";
  cout << "4. Exit\n";
  cout << "Choice: ";
}

void displayAdminMenu()
{
  cout << "\nAdmin Menu\n";
  cout << "==========\n";
  cout << "1. Add Inventory Item\n";
  cout << "2. Delete Inventory Item\n";
  cout << "3. Edit Inventory Item\n";
  cout << "4. View Active Users\n";
  cout << "5. Search Books\n";
  cout << "6. Search Users\n";
  cout << "7. Process Book Borrowing\n";
  cout << "8. Process Book Return\n";
  cout << "9. Logout\n";
  cout << "Choice: ";
}

void displayUserMenu()
{
  cout << "\nUser Menu\n";
  cout << "=========\n";
  cout << "1. View My Information\n";
  cout << "2. Search Books\n";
  cout << "3. View Borrowing History\n";
  cout << "4. Logout\n";
  cout << "Choice: ";
}

UserType getUserType()
{
  int type;
  cout << "Select user type:\n";
  cout << "1. Student\n";
  cout << "2. Faculty\n";
  cout << "3. Staff\n";
  cout << "Choice: ";
  cin >> type;

  switch (type)
  {
  case 1:
    return UserType::STUDENT;
  case 2:
    return UserType::FACULTY;
  case 3:
    return UserType::STAFF;
  default:
    return UserType::STUDENT;
  }
}

void clearInput()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
  RegisterNewUsers registration;
  UserLogin userLogin;
  Admin admin;
  Borrowing borrowing;
  SearchFunction search;

  int choice;
  bool running = true;

  while (running)
  {
    displayMainMenu();
    cin >> choice;
    clearInput();

    switch (choice)
    {
    case 1:
    {
      string firstName, lastName, address, phone, email, password, institutionalID;

      cout << "Enter First Name: ";
      getline(cin, firstName);
      cout << "Enter Last Name: ";
      getline(cin, lastName);
      cout << "Enter Address: ";
      getline(cin, address);
      cout << "Enter Phone (XXX-XXX-XXXX): ";
      getline(cin, phone);
      cout << "Enter Email: ";
      getline(cin, email);
      cout << "Enter Password: ";
      getline(cin, password);
      cout << "Enter Institutional ID: ";
      getline(cin, institutionalID);

      UserType type = getUserType();

      if (registration.registerUser(firstName, lastName, address, phone,
                                    email, password, institutionalID, type))
      {
        cout << "Registration successful!\n";
      }
      else
      {
        cout << "Registration failed. Please check your information.\n";
      }
      break;
    }
    case 2:
    {
      string username, password;
      cout << "Enter username: ";
      getline(cin, username);
      cout << "Enter password: ";
      getline(cin, password);

      if (admin.login(username, password))
      {
        bool adminSession = true;
        while (adminSession)
        {
          displayAdminMenu();
          int adminChoice;
          cin >> adminChoice;
          clearInput();

          switch (adminChoice)
          {
          case 1:
          {
            string title, author, type;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter type (BOOK/MAGAZINE/JOURNAL): ";
            getline(cin, type);

            if (admin.addInventoryItem(title, author, type))
            {
              cout << "Item added successfully!\n";
            }
            else
            {
              cout << "Failed to add item.\n";
            }
            break;
          }
          case 9:
            adminSession = false;
            admin.logout();
            break;
          default:
            cout << "Invalid choice.\n";
          }
        }
      }
      else
      {
        cout << "Invalid credentials.\n";
      }
      break;
    }
    case 3:
    {
      string libraryID, password;
      cout << "Enter Library ID: ";
      getline(cin, libraryID);
      cout << "Enter password: ";
      getline(cin, password);

      if (UserLogin::authenticate(libraryID, password))
      {
        bool userSession = true;
        UserLogin currentUser;

        while (userSession)
        {
          displayUserMenu();
          int userChoice;
          cin >> userChoice;
          clearInput();

          switch (userChoice)
          {
          case 1:
            currentUser.printUserSummary();
            break;
          case 2:
          {
            string searchTerm;
            cout << "Enter search term: ";
            getline(cin, searchTerm);
            auto results = search.searchByTitle(searchTerm);
            search.displaySearchResults(results);
            break;
          }
          case 4:
            userSession = false;
            currentUser.logout();
            break;
          default:
            cout << "Invalid choice.\n";
          }
        }
      }
      else
      {
        cout << "Invalid credentials.\n";
      }
      break;
    }
    case 4:
      running = false;
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}