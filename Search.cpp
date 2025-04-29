#include "Search.h"
#include <algorithm>

Search::Search()
{
  // TODO: Implement if needed
}

Search::~Search()
{
  // TODO: Implement if needed
}

std::vector<Book> Search::searchBooksByTitle(const std::vector<Book> &books, const std::string &title) const
{
  std::vector<Book> results;
  for (const auto &book : books)
  {
    if (book.getTitle().find(title) != std::string::npos)
    {
      results.push_back(book);
    }
  }
  return results;
}

std::vector<Book> Search::searchBooksByAuthor(const std::vector<Book> &books, const std::string &author) const
{
  std::vector<Book> results;
  for (const auto &book : books)
  {
    if (book.getAuthor().find(author) != std::string::npos)
    {
      results.push_back(book);
    }
  }
  return results;
}

std::vector<User> Search::searchUsersByName(const std::vector<User> &users, const std::string &name) const
{
  std::vector<User> results;
  for (const auto &user : users)
  {
    if (user.getName().find(name) != std::string::npos)
    {
      results.push_back(user);
    }
  }
  return results;
}
// TODO: Add more search/filter methods and user-friendly output