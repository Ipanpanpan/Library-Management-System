#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"
#include "Library.h"
#include <string>

class Admin : public Account {
public:
    Admin(const std::string& user, const std::string& pass, Library* lib);

    void addBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int yearPublish);
    void searchBook(const std::string& title) override;
    void editBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int yearPublish);
    void deleteBook(const std::string& ID);
    void getAllBooks(int sortedby = 0);
    void getAllTransactions();
    void searchTransactionReceipt(const std::string& user_id);
};

#endif // ADMIN_H
