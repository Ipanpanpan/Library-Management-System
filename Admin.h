#ifndef ADMIN_H
#define ADMIN_H

class Admin{
    void addbook(ID, title, author, category, availability);
    void searchbook(ID);
    void editbook(ID, title, author, category, availability);
    void deletebook(ID);
    void get_all_book (sortedby = NULL);
    void get_all_transaction();
    void search_transaction_receipt(user,Library);
};

#endif // ACCOUNT_H
