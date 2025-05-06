#include "Book.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

Book::Book(const string &title, const string &author,
           const string &publisher, ItemType type)
    : title(title), author(author), publisher(publisher), type(type), isAvailable(true)
{
  // Generate a simple ID based on title and author
  id = title.substr(0, 3) + author.substr(0, 3) + to_string(rand() % 1000);
}

void Book::saveToFile(const Book &book)
{
  ofstream file("books.csv", ios::app);
  if (file.is_open())
  {
    file << book.id << ","
         << book.title << ","
         << book.author << ","
         << book.publisher << ","
         << static_cast<int>(book.type) << ","
         << book.isAvailable << "\n";
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