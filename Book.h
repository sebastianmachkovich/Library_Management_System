#pragma once
#include <string>

class Book
{
  std::string title, author, publisher, id;
  bool isBorrowed;

public:
  Book();
  Book(const std::string &title, const std::string &author, const std::string &publisher, const std::string &id);
  Book(const Book &);
  ~Book();
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getPublisher() const;
  std::string getID() const;
  bool getIsBorrowed() const;
  void setIsBorrowed(bool status);
  // TODO: Add file I/O and more inventory management methods
};
