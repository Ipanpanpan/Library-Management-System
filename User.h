#ifndef USER_H
#define USER_H

#include "Account.h"
#include "Library.h"
#include <string>

class User : public Account {
private:
    Library* library;
public:
    User(const std::string& user, const std::string& pass, Library* lib);
    void searchBook(const std::string& title) override;
    void borrowBook(const std::string& bookId, int quantity);
    void returnBook(int transactionId);
};

#endif // USER_H
