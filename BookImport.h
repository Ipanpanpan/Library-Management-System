#ifndef BOOK_IMPORT_H
#define BOOK_IMPORT_H

#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string ID;           // Renamed from ISBN to ID
    string title;        // Renamed from book_name to title
    string author;
    string category;     // Added category attribute
    int quantity;
    int year_publish;
    bool availability;   // Added availability attribute

    // Constructor to initialize a Book object
    // Updated to include category and initialize availability
    Book(string id, string title, string author, string category, int qty, int year);

    // Method to display book details
    // Updated to display category and availability
    void displayBookInfo() const;
};

// Function to parse CSV and populate the list of Book objects
// Updated to handle category in CSV
vector<Book> importBooksFromCSV(const string& filename);

#endif
