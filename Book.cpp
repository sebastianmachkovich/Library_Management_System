#include "Book.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Helper to convert ItemType to string
static std::string itemTypeToString(ItemType type)
{
  switch (type)
  {
  case ItemType::BOOK:
    return "Fiction";
  case ItemType::MAGAZINE:
    return "Magazine";
  case ItemType::JOURNAL:
    return "Journal";
  default:
    return "Unknown";
  }
}

// Helper to get next unique numeric id from books.csv
static std::string getNextBookId()
{
  std::ifstream file("books.csv");
  std::string line, lastId = "0";
  getline(file, line); // skip header
  while (getline(file, line))
  {
    std::stringstream ss(line);
    std::string id;
    getline(ss, id, ',');
    lastId = id;
  }
  int nextId = std::stoi(lastId) + 1;
  return std::to_string(nextId);
}

Book::Book(const string &title, const string &author,
           const string &publisher, ItemType type)
    : title(title), author(author), publisher(publisher), type(type), isAvailable(true)
{
  // Generate a simple ID based on title and author (first 3 letters of each, lowercase)
  id = title.substr(0, 3) + author.substr(0, 3);
}

// Save book details to file (CSV format)
void Book::saveToFile(const Book &book)
{
  std::ofstream file("books.csv", std::ios::app);
  if (file.is_open())
  {
    std::string id = getNextBookId();
    file << id << ","
         << book.title << ","
         << book.author << ","
         << book.publisher << ","
         << itemTypeToString(book.type) << ","
         << (book.isAvailable ? "true" : "false") << "\n";
    file.close();
  }
}

vector<Book> Book::searchBooks(const string &query)
{
  vector<Book> results;
  ifstream file("books.csv");
  string line;

  while (getline(file, line))
  {
    if (line.find(query) != string::npos)
    {
      stringstream ss(line);
      string id, title, author, publisher, type, available;

      getline(ss, id, ',');
      getline(ss, title, ',');
      getline(ss, author, ',');
      getline(ss, publisher, ',');
      getline(ss, type, ',');
      getline(ss, available, ',');

      Book book(title, author, publisher, static_cast<ItemType>(stoi(type)));
      book.id = id;
      book.isAvailable = (available == "1");
      results.push_back(book);
    }
  }

  return results;
}

bool Book::removeBook(const string &bookId)
{
  ifstream inFile("books.csv");
  ofstream outFile("books_temp.csv");
  string line;
  bool found = false;

  while (getline(inFile, line))
  {
    if (line.substr(0, line.find(',')) != bookId)
    {
      outFile << line << "\n";
    }
    else
    {
      found = true;
    }
  }

  inFile.close();
  outFile.close();

  if (found)
  {
    remove("books.csv");
    rename("books_temp.csv", "books.csv");
  }
  else
  {
    remove("books_temp.csv");
  }

  return found;
}