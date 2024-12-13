#ifndef USER_H
#define USER_H

#include "Library.h"
#include <string>
#include <vector>

// Function to handle book borrowing
void borrowBook(int bookId, Library &library, const string &userName);

// Function to handle book returning
void returnBooks(vector<Book> &inventory, vector<Transaction> &transactions, const string &userName);

#endif // USER_H
