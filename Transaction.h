#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

using namespace std;

class Transaction {
private:
    int transaction_id;  // Unique transaction ID that includes the borrow date & time
    string isbn;         // ID of the borrowed book
    string username;     // User ID of the borrower
    string borrow_date;  // Date and time of the transaction

public:
    // Constructor to initialize a transaction
    Transaction(int trans_id, string isbn, string username);

    // Function to get the current date and time as a string (YYYY-MM-DD HH:MM:SS)
    string getCurrentDateTime() const;

    // Function to display transaction details
    void displayTransactionInfo() const;
};

#endif
