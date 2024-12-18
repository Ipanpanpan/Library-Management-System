#ifndef BOOKIMPORT_H
#define BOOKIMPORT_H

#include <string>
#include <vector>
#include <iostream>
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
    bool operator<(const Book& other) const;  // Overloaded < operator

};

vector<Book> importBooksFromCSV(const string& filename);

#endif
