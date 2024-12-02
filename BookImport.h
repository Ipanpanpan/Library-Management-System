#ifndef BOOK_IMPORT_H
#define BOOK_IMPORT_H

#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string book_name;
    string author;
    string ISBN;
    int quantity;
    int year_publish;

    // Constructor to initialize a Book object
    Book(string name, string author, string isbn, int qty, int year);

    // Method to display book details
    void displayBookInfo() const;
};

// Function to parse CSV and populate the list of Book objects
vector<Book> importBooksFromCSV(const string& filename);

#endif
