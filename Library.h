#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "BookImport.h"
#include "Transaction.h"

// Forward declarations
class Account;
class Admin;
class User;

class Library {
public:
    Library(const std::string& book_data_path_ = "books_info.csv", const std::string& account_data_path_ = "account_data.csv");
    ~Library();

    std::vector<Account*>& getAccounts();
    std::vector<Book>& getBooks();
    std::vector<Transaction>& getTransactions();
    Account* getAccount(const std::string& username, const std::string& password);

    void addAccount(const std::string& username, const std::string& password, const std::string& acc_type);
    void addBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int year_publish);
    void addTransaction(const std::string& bookId, const std::string& username);
    std::vector<Book> searchBooksByTitle(const std::string& title);

    void editBook(const std::string& ID, const std::string& title, const std::string& author, const std::string& category, bool availability, int year_publish);
    void deleteBook(const std::string& ID);
    void removeTransaction(int transactionId);

    bool isBookExist(const std::string& ID) const;
    bool isAccountExist(const std::string& username) const;

    void importAccountsFromCSV(const std::string& filePath);
    void importTransactionsFromCSV(const std::string& filePath);

private:
    std::vector<Account*> accounts;
    std::vector<Book> books;
    std::vector<Transaction> transactions;

    std::string book_data_path;
    std::string account_data_path;
};

#endif // LIBRARY_H
