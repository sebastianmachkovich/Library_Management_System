#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

class Search
{
public:
  Search();
  ~Search();
  std::vector<Book> searchBooksByTitle(const std::vector<Book> &books, const std::string &title) const;
  std::vector<Book> searchBooksByAuthor(const std::vector<Book> &books, const std::string &author) const;
  std::vector<User> searchUsersByName(const std::vector<User> &users, const std::string &name) const;
  // TODO: Add more search methods and user-friendly output
};
