#include "SearchFunction.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SearchFunction::searchByTitle(const string &title) const
{
  vector<string> results;
  ifstream file("books.csv");
  string line;

  while (getline(file, line))
  {
    stringstream ss(line);
    string id, bookTitle;

    getline(ss, id, ',');
    getline(ss, bookTitle, ',');

    // Case-insensitive search
    string titleLower = title;
    string bookTitleLower = bookTitle;
    transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);
    transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);

    if (bookTitleLower.find(titleLower) != string::npos)
    {
      results.push_back(line);
    }
  }

  return results;
}

vector<string> SearchFunction::searchByAuthor(const string &author) const
{
  vector<string> results;
  ifstream file("books.csv");
  string line;

  while (getline(file, line))
  {
    stringstream ss(line);
    string id, title, bookAuthor;

    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, bookAuthor, ',');

    // Case-insensitive search
    string authorLower = author;
    string bookAuthorLower = bookAuthor;
    transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
    transform(bookAuthorLower.begin(), bookAuthorLower.end(), bookAuthorLower.begin(), ::tolower);

    if (bookAuthorLower.find(authorLower) != string::npos)
    {
      results.push_back(line);
    }
  }

  return results;
}

vector<string> SearchFunction::searchByPublisher(const string &publisher) const
{
  vector<string> results;
  ifstream file("books.csv");
  string line;

  while (getline(file, line))
  {
    stringstream ss(line);
    string id, title, author, bookPublisher;

    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, bookPublisher, ',');

    // Case-insensitive search
    string publisherLower = publisher;
    string bookPublisherLower = bookPublisher;
    transform(publisherLower.begin(), publisherLower.end(), publisherLower.begin(), ::tolower);
    transform(bookPublisherLower.begin(), bookPublisherLower.end(), bookPublisherLower.begin(), ::tolower);

    if (bookPublisherLower.find(publisherLower) != string::npos)
    {
      results.push_back(line);
    }
  }

  return results;
}

vector<string> SearchFunction::searchUsers(const string &query) const
{
  vector<string> results;
  ifstream file("users.csv");
  string line;

  while (getline(file, line))
  {
    string lineLower = line;
    string queryLower = query;
    transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);
    transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);

    if (lineLower.find(queryLower) != string::npos)
    {
      results.push_back(line);
    }
  }

  return results;
}

void SearchFunction::displaySearchResults(const vector<string> &results) const
{
  if (results.empty())
  {
    cout << "No results found.\n";
    return;
  }

  cout << "\nSearch Results:\n";
  cout << "===============\n";

  for (const auto &result : results)
  {
    stringstream ss(result);
    string field;
    vector<string> fields;

    while (getline(ss, field, ','))
    {
      fields.push_back(field);
    }

    // Check if this is a book or user record based on the number of fields
    if (fields.size() >= 6)
    { // Book record
      cout << "ID: " << fields[0] << "\n";
      cout << "Title: " << fields[1] << "\n";
      cout << "Author: " << fields[2] << "\n";
      cout << "Publisher: " << fields[3] << "\n";
      cout << "Available: " << (fields[5] == "1" ? "Yes" : "No") << "\n";
    }
    else
    { // User record
      cout << "Library ID: " << fields[0] << "\n";
      cout << "Name: " << fields[2] << " " << fields[3] << "\n";
      cout << "Type: " << fields[8] << "\n";
    }
    cout << "---------------\n";
  }
}