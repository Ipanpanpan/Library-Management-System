#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Constructor to initialize a transaction
Transaction::Transaction(int trans_id, int book_id, int borrower_id) {
    this->transaction_id = trans_id;  // Set unique transaction ID
    this->book_id = book_id;          // Set the book ID
    this->borrower_id = borrower_id;  // Set the borrower ID (can be user_id)
    this->borrow_date = getCurrentDateTime();  // Record current date and time as borrow date
}

// Function to get the current date and time as a string (YYYY-MM-DD HH:MM:SS)
string Transaction::getCurrentDateTime() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << 1900 + ltm->tm_year << "-"
       << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-"
       << setfill('0') << setw(2) << ltm->tm_mday << " "
       << setfill('0') << setw(2) << ltm->tm_hour << ":"
       << setfill('0') << setw(2) << ltm->tm_min << ":"
       << setfill('0') << setw(2) << ltm->tm_sec;

    return ss.str();  // Return formatted date and time
}

// Function to display transaction details
void Transaction::displayTransactionInfo() const {
    cout << "Transaction ID: " << transaction_id << endl;
    cout << "Borrower ID: " << borrower_id << endl;
    cout << "Book ID: " << book_id << endl;
    cout << "Transaction Date & Time: " << borrow_date << endl;
    cout << "----------------------------" << endl;
}
