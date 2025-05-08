// Person.h - Abstract base class for users in the Library Management System
// Provides an interface for user summary printing
#ifndef PERSON
#define PERSON
using namespace std;

// Abstract Person class; other user classes inherit from this
class Person
{
public:
    virtual ~Person() {}                 // Virtual destructor for safe polymorphic deletion
    virtual void printUserSummary() = 0; // Pure virtual function for printing user summary
};

#endif
