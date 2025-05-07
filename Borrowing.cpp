#include <fstream>
#include <sstream>
// Only essential includes for file and string operations

// Borrow a book if user is under the limit
bool Borrowing::borrowBook(const std::string &bookId, const std::string &userId)
{
  if (isBorrowingLimitReached(userId))
    return false;
  std::ofstream file("borrowing.csv", std::ios::app);
  if (file.is_open())
  {
    file << bookId << "," << userId << ",0,0\n"; // 0 for date/returned for simplicity
    file.close();
    return updateInventory(bookId, false);
  }
  return false;
}

// Return a borrowed book
bool Borrowing::returnBook(const std::string &bookId)
{
  std::ifstream inFile("borrowing.csv");
  std::ofstream outFile("borrowing_temp.csv");
  std::string line;
  bool found = false;
  while (std::getline(inFile, line))
  {
    std::stringstream ss(line);
    std::string bId, uId, borrowDate, returned;
    std::getline(ss, bId, ',');
    std::getline(ss, uId, ',');
    std::getline(ss, borrowDate, ',');
    std::getline(ss, returned, ',');
    if (bId == bookId && returned == "0")
    {
      outFile << bId << "," << uId << "," << borrowDate << ",1\n";
      found = true;
    }
    else
    {
      outFile << line << "\n";
    }
  }
  inFile.close();
  outFile.close();
  if (found)
  {
    std::remove("borrowing.csv");
    std::rename("borrowing_temp.csv", "borrowing.csv");
    return updateInventory(bookId, true);
  }
  std::remove("borrowing_temp.csv");
  return false;
}

// Update book availability in inventory
bool Borrowing::updateInventory(const std::string &bookId, bool isReturning)
{
  std::ifstream inFile("books.csv");
  std::ofstream outFile("books_temp.csv");
  std::string line;
  bool found = false;
  while (std::getline(inFile, line))
  {
    std::stringstream ss(line);
    std::string id;
    std::getline(ss, id, ',');
    if (id == bookId)
    {
      size_t lastComma = line.find_last_of(',');
      outFile << line.substr(0, lastComma + 1) << (isReturning ? "1" : "0") << "\n";
      found = true;
    }
    else
    {
      outFile << line << "\n";
    }
  }
  inFile.close();
  outFile.close();
  if (found)
  {
    std::remove("books.csv");
    std::rename("books_temp.csv", "books.csv");
  }
  else
  {
    std::remove("books_temp.csv");
  }
  return found;
}

// Get borrowing history for a user
std::vector<std::string> Borrowing::getBorrowerHistory(const std::string &userId) const
{
  std::vector<std::string> history;
  std::ifstream file("borrowing.csv");
  std::string line;
  while (std::getline(file, line))
  {
    if (line.find(userId) != std::string::npos)
    {
      history.push_back(line);
    }
  }
  return history;
}

// Get current borrow count for a user
int Borrowing::getCurrentBorrowCount(const std::string &userId) const
{
  std::ifstream file("borrowing.csv");
  std::string line;
  int count = 0;
  while (std::getline(file, line))
  {
    std::stringstream ss(line);
    std::string bookId, uId, borrowDate, returned;
    std::getline(ss, bookId, ',');
    std::getline(ss, uId, ',');
    std::getline(ss, borrowDate, ',');
    std::getline(ss, returned, ',');
    if (uId == userId && returned == "0")
    {
      count++;
    }
  }
  return count;
}

// Check if user has reached borrowing limit
bool Borrowing::isBorrowingLimitReached(const std::string &userId) const
{
  return getCurrentBorrowCount(userId) >= MAX_BOOKS;
}