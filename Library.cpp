#include "Library.h"
#include "BookImport.h"
#include "Account.h"
#include "Admin.h"
#include "User.h"
#include "Transaction.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>


Library::Library(const std::string& book_data_path_, const std::string& account_data_path_)
    : book_data_path(book_data_path_), account_data_path(account_data_path_) {
    books = importBooksFromCSV(book_data_path_);
    importAccountsFromCSV(account_data_path_);
}

Library::~Library() {
    for (Account* acc : accounts) {
        delete acc;
    }
}

std::vector<Account*>& Library::getAccounts() {
    return accounts;
}

std::vector<Book>& Library::getBooks() {
    return books;
}

std::vector<Transaction>& Library::getTransactions() {
    return transactions;
}

Account* Library::getAccount(const std::string& username, const std::string& password) {
    for (Account* acc : accounts) {
        if (acc->getUsername() == username && acc->getPassword() == password) {
            return acc;
        }
    }
    return nullptr;
}
std::vector<Book> Library::searchBooksByTitle(const std::string& title) {
    std::vector<Book> foundBooks;
    for (const auto& book : books) {
        if (book.title.find(title) != std::string::npos) {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

void Library::addAccount(const std::string& username, const std::string& password, const std::string& acc_type) {
    if (isAccountExist(username)) {
        throw std::invalid_argument("Username already exists");
    }

    Account* acc = nullptr;
    if (acc_type == "user") {
        acc = new User(username, password, this);
    } else if (acc_type == "admin") {
        acc = new Admin(username, password, this);
    } else {
        throw std::invalid_argument("Invalid account type");
    }

    accounts.push_back(acc);
}

void Library::addBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int year_publish) {
    if (isBookExist(ID)) {
        throw std::invalid_argument("Book with this ID already exists");
    }

    Book book(ID, title, author, category, availability, year_publish);
    books.push_back(book);
    std::sort(books.begin(), books.end(), compareBookByID);
}

void Library::addTransaction(const std::string& bookId, const std::string& username) {
    int transactionId = transactions.empty() ? 1 : transactions.back().getTransactionID() + 1;
    Transaction transaction(transactionId, bookId, username);
    transactions.push_back(transaction);
}

void Library::editBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int year_publish) {
    for (auto& book : books) {
        if (book.ID == ID) {
            book.title = title;
            book.author = author;
            book.category = category;
            book.availability = availability;
            book.year_publish = year_publish;
            return;
        }
    }
    throw std::invalid_argument("Book not found");
}

void Library::deleteBook(const std::string& ID) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->ID == ID) {
            books.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Book not found");
}

void Library::removeTransaction(int transactionId) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->getTransactionID() == transactionId) {
            transactions.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Transaction not found");
}

bool Library::isBookExist(const std::string& ID) const {
    for (const auto& book : books) {
        if (book.ID == ID) {
            return true;
        }
    }
    return false;
}

bool Library::isAccountExist(const std::string& username) const {
    for (const auto& acc : accounts) {
        if (acc->getUsername() == username) {
            return true;
        }
    }
    return false;
}

void Library::importAccountsFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string username, password, acc_type;
        if (std::getline(ss, username, ',') &&
            std::getline(ss, password, ',') &&
            std::getline(ss, acc_type, ',')) {
            try {
                addAccount(username, password, acc_type);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error adding account: " << e.what() << std::endl;
            }
        }
    }

    file.close();
}

void Library::importTransactionsFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string transactionId_str, bookId, borrowerId;
        if (std::getline(ss, transactionId_str, ',') &&
            std::getline(ss, bookId, ',') &&
            std::getline(ss, borrowerId, ',')) {
            try {
                int transactionId = std::stoi(transactionId_str);
                addTransaction(bookId, borrowerId);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error adding transaction: " << e.what() << std::endl;
            }
        }
    }

    file.close();
}
