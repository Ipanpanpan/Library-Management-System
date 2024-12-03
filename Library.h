#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "Account.h"
#include "BookImport.h"
#include "Transaction.h"
#include "Admin.h"
#include <string>

class Library {
public:
    friend class Admin;

    //Constructor
    Library(string book_data_path_ = "books_info.csv", string account_data_path_ = "account_data.csv");

    //Getter
    vector<Account> get_accounts() const;
    vector<Book> get_books() const;
    vector<Transaction> get_transactions() const;

    void add_account(string username, string password, string acc_type = "user");
    void add_book(string ISBM, string book_name, string author, int quantity, int year_publish);
    void add_transaction(Transaction transaction);


private:
    //Private Function
    void remove_account(int account_id);
    void remove_book(string ISBN);
    void remove_transaction_record(int transaction_id);

    void edit_book(string ISBN, string book_name = NULL, string author = NULL, int quantity = NULL, int year_publish = NULL);

    //File Import
    void importAccountFromCSV(string file_path);

    //Class Attributes
    vector<Account> accounts;
    vector<Book> books;
    vector<Transaction> transactions;
    //data path
    string book_data_path;
    string account_data_path;

};

#endif // LIBRARY_H
