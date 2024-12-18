#ifndef USER_H
#define USER_H

#include "Library.h"
#include <string>
#include <vector>

class User : Account{


public:
// Function to handle book borrowing
void borrowBook(int bookId);

// Function to handle book returning
void returnBooks(vector<Book> &inventory, vector<Transaction> &transactions);


};

#endif // USER_H
