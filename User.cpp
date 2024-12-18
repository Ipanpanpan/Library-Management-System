#include "User.h"
#include "Library.h"
#include <iostream>
#include <stdexcept>

User::User(const std::string& user, const std::string& pass, Library* lib)
    : Account(user, pass, lib) {}

void User::searchBook(const std::string& title) {
    std::vector<Book> foundBooks = library->searchBooksByTitle(title);
    if (foundBooks.empty()) {
        std::cout << "No books found with the title: " << title << std::endl;
    } else {
        std::cout << "Found books:" << std::endl;
        for (const auto& book : foundBooks) {
            book.displayBookInfo();
        }
    }
}

void User::borrowBook(const std::string& bookId, int quantity) {
    for (Book& book : library->getBooks()) {
        if (book.ID == bookId) {
            if (book.availability && quantity > 0) {
                book.availability = false; // Assuming borrowing one at a time
                library->addTransaction(bookId, getUsername());
                std::cout << "Book borrowed successfully.\n";
                return;
            } else {
                std::cout << "Book is not available or invalid quantity.\n";
                return;
            }
        }
    }
    std::cout << "Book not found.\n";
}

void User::returnBook(int transactionId) {
    for (Transaction& trans : library->getTransactions()) {
        if (trans.getTransactionID() == transactionId && trans.getUserName() == getUsername()) {
            for (Book& book : library->getBooks()){
                if (book.ID == trans.getUserName()){
                    book.availability = true;
                }
            }
             library->removeTransaction(transactionId);
            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    std::cout << "Transaction not found.\n";
}
