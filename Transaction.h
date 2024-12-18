#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include "BookImport.h"

class Transaction {
private:
    int transaction_id;
    std::string book_id;
    std::string username;
    std::string borrow_date;
    std::vector<Book> books;

public:
    Transaction(int trans_id, const std::string& book_id, const std::string& username);
    std::string getCurrentDateTime() const;
    void displayTransactionInfo() const;
    int getTransactionID() const { return transaction_id; }
    std::string getUserName() const { return username; }
    const std::vector<Book>& getBooks() const { return books; }
};

#endif // TRANSACTION_H
