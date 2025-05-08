// Admin.h - Declaration of the Admin class
// Handles librarian/admin operations in the Library Management System
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;

// Admin class provides methods for managing books, users, and borrowing records
class Admin
{
public:
  string loggedInUsername;     // Stores the username of the logged-in admin
  bool login();                // Handles admin login
  void adminMenu();            // Displays the admin menu and handles choices
  void addBook();              // Add a new book
  void deleteBook();           // Delete a book
  void editBook();             // Edit book details
  void addUser();              // Add a new user
  void deleteUser();           // Delete a user
  void editUser();             // Edit user details
  void viewTotalActiveUsers(); // View total number of active users
  void searchInventory();      // Search for books
  void searchUsers();          // Search for users
};

#endif
