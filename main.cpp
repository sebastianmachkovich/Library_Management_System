// Library Management System Entry Point
#include "Admin.h"
#include "User.h"
#include "Book.h"
#include "LibraryAccountManager.h"
#include "Borrowing.h"
#include "Search.h"
using namespace std; 

int main()
{
  // TODO: Implement main menu and program loop
  // 1. Register New Users
  // 2. Admin (Librarian) Login
  // 3. User Login
  // 4. Exit
  
int userInput;
  cout << "Welcome to the Library Managment System!" << endl;
  cout << "Choose an option: " << endl;
  cout << "1. Register New Users" << endl;
  cout << "2. Admin (Librarian) Login" << endl;
  cout << "3. User Login" << endl;
  cout << "4. Exit" << endl;
  cin >> userInput;
  
  if(userInput < 1 || userInput > 4){
    cout << "Please enter a number between 1 and 4" << endl;
    cin >> userInput;
  }

  if(userInput == 1){
  
  }
  else if(userInput == 2){
  
  }
  else if(userInput == 3){
  
  }
  else {
  cout << "Thank you for useing the Library Managment System, have a great day!" << endl;
  }
  return 0;
}
