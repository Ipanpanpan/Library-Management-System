#ifndef BOOKIMPORT_H
#define BOOKIMPORT_H

#include <string>
#include <vector>
#include <iostream> // Make sure iostream is included
using namespace std;
class Book {
public:
    string ID;
    string title;
    string author;
    string category;
    bool availability;
    int year_publish;

    Book(string id, string title, string author, string category, bool availability, int year); // Modified constructor

    void displayBookInfo() const;
};

vector<Book> importBooksFromCSV(const string& filename);

#endif
