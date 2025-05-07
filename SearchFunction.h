#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include <string>
#include <vector>
// Only essential includes for clarity

// SearchFunction class provides search utilities for inventory and users
class SearchFunction
{
public:
  // Inventory search methods
  std::vector<std::string> searchByTitle(const std::string &title) const;
  std::vector<std::string> searchByAuthor(const std::string &author) const;
  std::vector<std::string> searchByPublisher(const std::string &publisher) const;

  // User search methods (admin only)
  std::vector<std::string> searchUsers(const std::string &query) const;

  // Format and display results
  void displaySearchResults(const std::vector<std::string> &results) const;
};

#endif