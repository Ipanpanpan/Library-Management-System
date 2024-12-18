#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Transaction::Transaction(int trans_id, const std::string& book_id, const std::string& username)
    : transaction_id(trans_id), book_id(book_id), username(username) {
    this->borrow_date = getCurrentDateTime();
}

std::string Transaction::getCurrentDateTime() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::stringstream ss;
    ss << 1900 + ltm->tm_year << "-"
       << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-"
       << std::setfill('0') << std::setw(2) << ltm->tm_mday << " "
       << std::setfill('0') << std::setw(2) << ltm->tm_hour << ":"
       << std::setfill('0') << std::setw(2) << ltm->tm_min << ":"
       << std::setfill('0') << std::setw(2) << ltm->tm_sec;

    return ss.str();
}

void Transaction::displayTransactionInfo() const {
    std::cout << "Transaction ID: " << transaction_id << std::endl;
    std::cout << "Borrower Username: " << username << std::endl;
    std::cout << "Book ID: " << book_id << std::endl;
    std::cout << "Transaction Date & Time: " << borrow_date << std::endl;
    std::cout << "----------------------------" << std::endl;
}
