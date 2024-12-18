#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

using namespace std;

class Transaction {
private:
    int receipt_number;  // Unique transaction ID that includes the borrow date & time
    string isbn;         // ID of the borrowed book
    string username;     // User ID of the borrower
    string borrow_date;  // Date and time of the transaction
    bool is_borrow_action; // True for borrow, false for return

public:
    // Constructor to initialize a transaction
    Transaction(int receipt_number, const std::string& username, const std::string& borrow_date, bool is_borrow)
        : receipt_number(receipt_number), username(username), borrow_date(borrow_date), is_borrow_action(is_borrow) {}

    // Function to get the current date and time as a string (YYYY-MM-DD HH:MM:SS)
    string getCurrentDateTime() const;

    // Function to display transaction details
    void displayTransactionInfo() const;

    int getReceiptNumber() const { return receipt_number; }
    string getUsername() const { return username; }
    string getBorrowDate() const { return borrow_date; }
    bool isBorrowAction() const { return is_borrow_action; }

};

#endif
