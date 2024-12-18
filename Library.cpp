#include "Library.h"

#include "BookImport.h"
#include "Account.h"
#include <sstream>
#include <exception>
#include <string>

using namespace std;


Library::Library(string book_data_path_, string account_data_path_):
    book_data_path(book_data_path_), account_data_path(account_data_path_){

    books = importBooksFromCSV(book_data_path_);
    importAccountFromCSV(account_data_path_);
}

//Getter
std::vector<Account*> Library::get_accounts() {
    return accounts;
}

std::vector<Book> Library::get_books() const {
    return books;
}

std::vector<Transaction> Library::get_transactions() const {
    return transactions;
}

Account& Library::get_account(std::string username, std::string password) {
    for (int i = 0; i < accounts.size(); i++){
        if (accounts[i]->getUsername() == username)
            return *accounts[i];
    }
    return nullptr;
}


//Adding
void Library::add_accounts(std::string username, std::string password, std::string acc_type) {
    if (!is_account_exist(username))
        throw invalid_argument("username already exist");

    if (acc_type == "user") {
        Account* acc = new User(username, password);
    }
    else if (acc_type == "admin") {
        Account* acc = new Admin(username, password);
    }
    else
        throw invalid_argument("Invalid account type");

    accounts.push_back(acc);
}


void Library::add_books(std::string ID , std::string title, std::string author, std::string category, bool availability, int year_publish){
    Book book = Book(ID, title, author, category, availability, year_publish);

    if (books.size() == 0)
        books.push_back(book);

    else if (books[books.size() - 1] < ID)
        books.push_back(book);

    else if (books[0] > ID)
        books.insert(books.begin(), book);

    //search the index to fit book
    else{
        int index;
        int low = 0;
        int high = books.size()-1;
        while (!(books[index - 1].ID < ID && ID < books[index].ID)){
            index = (low + high) / 2;
            if (books[index].ID > ID)
                high = index;
            else if (books[index].ID < ID)
                low = index;
            else
                throw invalid_argument("Book already exist");
        }
        books.insert(books.begin() + index, book);
    }
}


void Library::add_transactions(std::string ID, std::string username) {
    if (transactions.size() == 0)
        int id = 1;
    else
        int id = transactions[transactions.size() - 1].transaction_id

    Transaction transaction = Transaction(id, ID, username);
    transactions.push_back(transaction);
}

//Edit
void Library::edit_book(std::string ID, std::string title = NULL, std::string author = NULL,
                        int quantity = NULL, int year_publish = NULL){

}


//Remove
void Library::remove_account(string username){
    for (int i = 0; i < accounts.size(); i++){
        if (accounts[i].username == username){
            accounts.erase(accounts.begin() + i);
            return;
        }
    }
    throw invalid_argument("Username not found");
}


void Library::remove_book(string ID){
    int low = 0;
    int high = books.size() -1;
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (books[mid].ID == ID){
            books.erase(books.begin() + mid);
            return;
        }
        else if (books[mid].ID < ID)
            low = mid;
        else
            high = mid;
    }
    throw invalid_argument("Book not found");
}

void Library::remove_transaction_record(int transaction_id) {
    int low = 0;
    int high = transactions.size() - 1;
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (transactions[mid].transaction_id == transaction_id){
            transactions.erase(transactions.begin() + mid);
            return;
        }
        else if (transactions[mid].transaction_id < transaction_id)
            low = mid;
        else
            high = mid;
    }
    throw invalid_argument("Transaction not found");
}

//Checking
bool Library::is_book_exist(string ID) const {
    int low = 0;
    int high = books.size() -1;
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (books[mid].ID == ID){
            return true;
        }
        else if (books[mid].ID < ID)
            low = mid;
        else
            high = mid;
    }
    throw false;
}

bool Library::is_account_exist(string username) const {
    for (int i = 0; i < accounts.size(); i++){
        Account ith_account = *accounts[i];
        if (ith_account.username == username)
            return true;
    }
    return false;
}

//Data loader
void Library::importAccountFromCSV(std::string file_path){
    fstream file;
    if (!file.is_open()){
        throw invalid_argument("Invalid file_path!");
    }
    vector<string> row;
    string line;
    while(getline(file, line)){
        row = split(line);
        string username = row.at(0);
        string password = row.at(1);
        string acc_type = row.at(2);
        add_accounts(username, password, acc_type);
    }
}

void Library::importTransactionFromCSV(string file_path) {
    fstream file;
    if (!file.is_open()){
        throw invalid_argument("Invalid file_path!");
    }
    vector<string> row;
    string line;
    while(getline(file, line)){
        row = split(line);
        string transaction_id = row.at(0);
        string book_id = row.at(1);
        string borrower_id = row.at(2);
        add_accounts(username, password, acc_type);
    }
}


vector<string> Library::split(const string& line, char delimiter) {
    stringstream ss(line)
    vector<string> row;
    string data;

    while(!getline(ss, data, delimiter)){
        row.push_back(data);
    }

    return row;
}

std::vector<Account*> Library::get_accounts() const{
    return accounts
}





