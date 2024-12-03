#include "Library.h"

#include "BookImport.h"

Library::Library(string book_data_path_, string account_data_path_):
    book_data_path(book_data_path_), account_data_path(account_data_path_){

    books = importBooksFromCSV(book_data_path_);
    accounts = importAccountFromCSV(account_data_path_)
}
