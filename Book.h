#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

using namespace std;

enum class ItemType
{
  BOOK,
  MAGAZINE,
  JOURNAL
};

class Book
{
private:
  string id;
  string title;
  string author;
  string publisher;
  ItemType type;
  bool isAvailable;
  string currentBorrower;

public:
  Book(const string &title, const string &author,
       const string &publisher, ItemType type);

  // Getters
  string getID() const { return id; }
  string getTitle() const { return title; }
  string getAuthor() const { return author; }
  bool getAvailability() const { return isAvailable; }

  // Setters
  void setAvailability(bool available) { isAvailable = available; }
  void setBorrower(const string &borrowerId) { currentBorrower = borrowerId; }

  // Static functions for inventory management
  static void saveToFile(const Book &book);
  static vector<Book> searchBooks(const string &query);
  static bool removeBook(const string &bookId);
};

#endif 