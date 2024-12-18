#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Library.h"
#include "Admin.h"
#include "Utility.h"
#include "BookImport.h"

Admin::Admin(const std::string& user, const std::string& pass, Library* lib) :
    Account(user, pass, lib) {}

void Admin::addBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int yearPublish) {
    library->addBook(ID, title, author, category, availability, yearPublish);
}

void Admin::searchBook(const std::string& title) {
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

void Admin::editBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int yearPublish) {
    library->editBook(ID, title, author, category, availability, yearPublish);
}

void Admin::deleteBook(const std::string& ID) {
    library->deleteBook(ID);
}

void Admin::getAllBooks(int sortedby) {
    std::vector<Book> books = library->getBooks();
    if (sortedby == 1) {
        // Wrap function pointer in std::function
        mergeSort(books, 0, books.size() - 1, std::function<bool(const Book&, const Book&)>(compareBookByID));
        std::cout << "Sorted Books by ID (Using Merge Sort):" << std::endl;
    } else if (sortedby == 2) {
        // Wrap function pointer in std::function
        bubbleSort(books, std::function<bool(const Book&, const Book&)>(compareBookByTitle));
        std::cout << "Sorted Books by Title (Using Bubble Sort):" << std::endl;
    } else {
        std::cout << "Show All Current Books:" << std::endl;
    }
    std::cout << "ID\t" << "Title\t" << "Author\t" << "Category\t" << "Availability\t" << "Year Published\t" << std::endl;
    for (const auto& book : books) {
        std::cout << book.ID << "\t" << book.title << "\t" << book.author << "\t" << book.category << "\t" << book.availability << "\t" << book.year_publish << std::endl;
    }
}



void Admin::getAllTransactions() {
    // Implementation for getting all transactions
    std::cout << "All Transactions:" << std::endl;
    // ... (Logic to retrieve and display transactions)
}

void Admin::searchTransactionReceipt(const std::string& user_id) {
    // Implementation for searching transaction receipts by user ID
    std::cout << "Searching for transaction receipts for user ID: " << user_id << std::endl;
    // ... (Logic to search and display transactions)
}
