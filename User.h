#ifndef USER_H
#define USER_H

#include "Library.h"
#include "Account.h"
#include <string>
#include <vector>

class User : Account{

public:
    // Function to handle book borrowing
    void borrowBook(int bookId);

    // Function to handle book returning
    void returnBooks(vector<Book> &inventory, vector<Transaction> &transactions);

    // Function to get user's transaction history
    void getTransactionHistory(const std::vector<Transaction>& transactions) const;

};

#endif // USER_H
