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

    Book(string id, string title, string author, string category, bool availability, int year);
    void displayBookInfo() const;


};

vector<Book> importBooksFromCSV(const string& filename);
bool compare_book_by_id(const Book& l, const Book& r);
bool compare_book_by_title(const Book& l, const Book& r);

#endif
