#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

// Forward declaration to break circular dependency
class Library;

class Account {
protected:
    std::string username;
    std::string password;
    Library* library;

public:
    Account(const std::string& user, const std::string& pass, Library* lib);

    virtual ~Account() {} // Add a virtual destructor

    std::string getUsername() const;
    void setUsername(const std::string& user);

    std::string getPassword() const;
    void setPassword(const std::string& pass);

    virtual void displayAccountInfo() const;

    // Pure virtual function for searching books
    virtual void searchBook(const std::string& title) = 0;
};

#endif // ACCOUNT_H
