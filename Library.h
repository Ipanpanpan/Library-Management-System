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
    Library(std::string book_data_path_ = "books_info.csv", std::string account_data_path_ = "account_data.csv");

    //Getter
    std::vector<Account*> get_accounts();
    std::vector<Book> get_books() const;
    std::vector<Transaction> get_transactions() const;
    Account& get_account(std::string username, std::string password);


    void add_accounts(std::string username, std::string password, std::string acc_type);
    void add_books(std::string ISBN, std::string book_name, std::string author, int quantity, int year_publish);
    void add_transactions(std::string ISBN, std::string username);




private:
    //Private Function
    void remove_account(std::string username);
    void remove_book(std::string ISBN);
    void remove_transaction_record(int transaction_id);

    void edit_book(std::string ISBN, std::string book_name = NULL, std::string author = NULL, int quantity = NULL, int year_publish = NULL);

    //Checking
    bool is_book_exist(std::string ISBN) const;
    bool is_account_exist(std::string username) const;


    //File Import
    void importAccountFromCSV(std::string file_path);
    void importTransactionFromCSV(std::string file_path);
    vector<string> split(const std::string& line, char delimiter = ',');



    //Class Attributes
    std::vector<Account*> accounts;
    std::vector<Book> books;
    std::vector<Transaction> transactions;
    //data path
    std::string book_data_path;
    std::string account_data_path;

};

#endif // LIBRARY_H
