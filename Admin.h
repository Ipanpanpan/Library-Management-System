#ifndef ADMIN_H
#define ADMIN_H
#include "Library.h"



class Admin{
private:
    Library adminobj;

public:
    void addbook(ID, title, author, category, availability);
    void searchbook(ID);
    void editbook(ID, title, author, category, availability);
    void deletebook(ID);
    void get_all_book (sortedby = NULL);
    void get_all_transaction();
    void search_transaction_receipt(user_id);
};

#endif // ACCOUNT_H
