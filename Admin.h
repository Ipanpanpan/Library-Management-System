#ifndef ADMIN_H
#define ADMIN_H
#include "Library.h"



class Admin : Account{
private:
public:

    Admin(const std::string& user, const std::string& pass, Library& lib);

    void addbook(string ID, string title, string author, string category, bool availability, int yearPublish);
    void searchbook(string ID);
    void editbook(string ID, string title, string author, string category, bool availability, int yearPublish);
    void deletebook(string ID);
    void get_all_book (int sortedby = NULL);
    void get_all_transaction();
    void search_transaction_receipt(string user_id);
};

#endif // ACCOUNT_H
