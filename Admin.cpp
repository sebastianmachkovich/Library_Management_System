#include "Admin.h"
#include "Book.h"
#include "Borrowing.h"
#include "RegisterNewUser.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Admin::login()
{
  string username, password;
  cout << "\n[Admin Login]" << endl;
  cout << "Username: ";
  getline(cin, username);
  cout << "Password: ";
  getline(cin, password);

  ifstream file("librarians.csv");
  if (!file.is_open())
  {
    cout << "Error: Could not open librarians.csv" << endl;
    return false;
  }
  string line;
  getline(file, line); // skip header
  while (getline(file, line))
  {
    stringstream ss(line);
    string user, pass;
    getline(ss, user, ',');
    getline(ss, pass, ',');
    if (user == username && pass == password)
    {
      cout << "Login successful!" << endl;
      loggedInUsername = username; // Store the username
      return true;
    }
  }
  cout << "Invalid credentials." << endl;
  return false;
}

void Admin::addBook()
{
  Book book;
  book.input();
  ofstream file("books.csv", ios::app);
  file << book.id << ',' << book.title << ',' << book.author << ',' << book.publisher << ',' << book.year << ',' << book.copies << '\n';
  file.close();
  cout << "Book added successfully!" << endl;
}

void Admin::deleteBook()
{
  string delId;
  cout << "Enter Book ID to delete: ";
  getline(cin, delId);
  ifstream inFile("books.csv");
  ofstream outFile("books_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string id;
    getline(ss, id, ',');
    if (id != delId)
    {
      outFile << line << '\n';
    }
    else
    {
      found = true;
    }
  }
  inFile.close();
  outFile.close();
  remove("books.csv");
  rename("books_tmp.csv", "books.csv");
  if (found)
    cout << "Book deleted successfully!" << endl;
  else
    cout << "Book ID not found." << endl;
}

void Admin::editBook()
{
  string editId;
  cout << "Enter Book ID to edit: ";
  getline(cin, editId);
  ifstream inFile("books.csv");
  ofstream outFile("books_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string id;
    getline(ss, id, ',');
    if (id == editId)
    {
      Book book;
      book.id = id;
      cout << "Editing book with ID: " << id << endl;
      cout << "Enter new details:" << endl;
      book.input();
      outFile << book.id << ',' << book.title << ',' << book.author << ',' << book.publisher << ',' << book.year << ',' << book.copies << '\n';
      found = true;
    }
    else
    {
      outFile << line << '\n';
    }
  }
  inFile.close();
  outFile.close();
  remove("books.csv");
  rename("books_tmp.csv", "books.csv");
  if (found)
    cout << "Book edited successfully!" << endl;
  else
    cout << "Book ID not found." << endl;
}

void Admin::addUser()
{
  cout << "[Admin Add User]" << endl;
  RegisterNewUser reg;
  reg.registerUser();
}

void Admin::deleteUser()
{
  string delId;
  cout << "Enter Library ID to delete: ";
  getline(cin, delId);
  ifstream inFile("users.csv");
  ofstream outFile("users_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string type, first, last, address, phone, email, password, instID, libID;
    getline(ss, type, ',');
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, address, ',');
    getline(ss, phone, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');
    getline(ss, instID, ',');
    getline(ss, libID, ',');
    if (libID != delId)
    {
      outFile << line << '\n';
    }
    else
    {
      found = true;
    }
  }
  inFile.close();
  outFile.close();
  remove("users.csv");
  rename("users_tmp.csv", "users.csv");
  if (found)
    cout << "User deleted successfully!" << endl;
  else
    cout << "Library ID not found." << endl;
}

void Admin::editUser()
{
  string editId;
  cout << "Enter Library ID to edit: ";
  getline(cin, editId);
  ifstream inFile("users.csv");
  ofstream outFile("users_tmp.csv");
  string line;
  bool found = false;
  while (getline(inFile, line))
  {
    stringstream ss(line);
    string type, first, last, address, phone, email, password, instID, libID;
    getline(ss, type, ',');
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, address, ',');
    getline(ss, phone, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');
    getline(ss, instID, ',');
    getline(ss, libID, ',');
    if (libID == editId)
    {
      cout << "Editing user with Library ID: " << libID << endl;
      RegisterNewUser reg;
      reg.registerUser(); // Overwrite with new info
      found = true;
    }
    else
    {
      outFile << line << '\n';
    }
  }
  inFile.close();
  outFile.close();
  remove("users.csv");
  rename("users_tmp.csv", "users.csv");
  if (found)
    cout << "User edited successfully!" << endl;
  else
    cout << "Library ID not found." << endl;
}

void Admin::viewTotalActiveUsers()
{
  ifstream file("users.csv");
  string line;
  int count = 0;
  while (getline(file, line))
  {
    if (!line.empty())
      count++;
  }
  file.close();
  cout << "Total active users: " << count << endl;
}

void Admin::searchInventory()
{
  string keyword;
  cout << "Enter keyword to search in books (title, author, publisher): ";
  getline(cin, keyword);
  ifstream file("books.csv");
  string line;
  bool found = false;
  while (getline(file, line))
  {
    if (line.find(keyword) != string::npos)
    {
      cout << line << endl;
      found = true;
    }
  }
  if (!found)
    cout << "No matching books found." << endl;
}

void Admin::searchUsers()
{
  string keyword;
  cout << "Enter keyword to search users (name, ID, email): ";
  getline(cin, keyword);
  ifstream file("users.csv");
  string line;
  bool found = false;
  while (getline(file, line))
  {
    if (line.find(keyword) != string::npos)
    {
      cout << line << endl;
      found = true;
    }
  }
  if (!found)
    cout << "No matching users found." << endl;
}

void Admin::adminMenu()
{
  Borrowing borrowing;
  int choice;
  while (true)
  {
    cout << "\n===== Admin Menu =====" << endl;
    cout << "Welcome " << loggedInUsername << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. Edit Book" << endl;
    cout << "4. Add User" << endl;
    cout << "5. Delete User" << endl;
    cout << "6. Edit User" << endl;
    cout << "7. View Total Active Users" << endl;
    cout << "8. Search Inventory" << endl;
    cout << "9. Search Users" << endl;
    cout << "10. Borrow Book" << endl;
    cout << "11. Return Book" << endl;
    cout << "12. Edit Borrowing Record" << endl;
    cout << "13. Search Borrowing Records" << endl;
    cout << "0. Logout" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
      addBook();
      break;
    case 2:
      deleteBook();
      break;
    case 3:
      editBook();
      break;
    case 4:
      addUser();
      break;
    case 5:
      deleteUser();
      break;
    case 6:
      editUser();
      break;
    case 7:
      viewTotalActiveUsers();
      break;
    case 8:
      searchInventory();
      break;
    case 9:
      searchUsers();
      break;
    case 10:
      borrowing.borrowBook();
      break;
    case 11:
      borrowing.returnBook();
      break;
    case 12:
      borrowing.editBorrowing();
      break;
    case 13:
      borrowing.searchBorrowing();
      break;
    case 0:
      cout << "Logging out..." << endl;
      return;
    default:
      cout << "Invalid choice. Try again." << endl;
    }
  }
}
