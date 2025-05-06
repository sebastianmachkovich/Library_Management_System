#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include <string>
#include <vector>

using namespace std;

class SearchFunction
{
public:
  // Inventory search methods
  vector<string> searchByTitle(const string &title) const;
  vector<string> searchByAuthor(const string &author) const;
  vector<string> searchByPublisher(const string &publisher) const;

  // User search methods (admin only)
  vector<string> searchUsers(const string &query) const;

  // Format and display results
  void displaySearchResults(const vector<string> &results) const;
};

#endif 