#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BookImport.h"  // Include the header file

using namespace std;

Book::Book(string name, string author, string isbn, int qty, int year)
    : book_name(name), author(author), ISBN(isbn), quantity(qty), year_publish(year) {}

void Book::displayBookInfo() const {
    cout << "Book Name: " << book_name << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Year Published: " << year_publish << endl;
    cout << "----------------------------" << endl;
}

vector<Book> importBooksFromCSV(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        // Skip the header line
        getline(file, line);

        // Read the rest of the lines
        while (getline(file, line)) {
            stringstream ss(line);
            string book_name, author, ISBN, quantity_str, year_str;

            // Parse the CSV line
            getline(ss, book_name, ',');
            getline(ss, author, ',');
            getline(ss, ISBN, ',');
            getline(ss, quantity_str, ',');
            getline(ss, year_str, ',');

            // Convert quantity and year to integers
            int quantity = stoi(quantity_str);
            int year = stoi(year_str);

            // Create Book object and add to vector
            books.push_back(Book(book_name, author, ISBN, quantity, year));
        }
        file.close();
    } else {
        cerr << "Error opening file!" << endl;
    }

    return books;
}
