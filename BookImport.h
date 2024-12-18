#ifndef BOOKIMPORT_H
#define BOOKIMPORT_H

#include <string>
#include <vector>

class Book {
public:
    std::string ID;
    std::string title;
    std::string author;
    std::string category;
    bool availability;
    int year_publish;
    Book();
    Book(const std::string& id, const std::string& title, const std::string& author, const std::string& category, bool availability, int year);
    void displayBookInfo() const;
    std::string getTitle() const { return title; }
};

std::vector<Book> importBooksFromCSV(const std::string& filename);
bool compareBookByID(const Book& l, const Book& r);
bool compareBookByTitle(const Book& l, const Book& r);

#endif // BOOKIMPORT_H
