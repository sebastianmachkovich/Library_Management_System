#include "Book.h"

Book::Book() : title(""), author(""), publisher(""), id(""), isBorrowed(false) {}

Book::Book(const std::string &t, const std::string &a, const std::string &p, const std::string &i)
    : title(t), author(a), publisher(p), id(i), isBorrowed(false) {}

Book::Book(const Book &other)
{
  title = other.title;
  author = other.author;
  publisher = other.publisher;
  id = other.id;
  isBorrowed = other.isBorrowed;
}

Book::~Book() {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getPublisher() const { return publisher; }
std::string Book::getID() const { return id; }
bool Book::getIsBorrowed() const { return isBorrowed; }
void Book::setIsBorrowed(bool status) { isBorrowed = status; }
// TODO: Implement file I/O and more inventory management methods