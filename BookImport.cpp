#include "BookImport.h"
#include <sstream>
#include <fstream>        // For file operations
#include <iostream>       // For display purposes
#include <exception>

// Constructor implementation
Book::Book(string id, string title, string author, string category, int qty, int year)
    : ID(id), title(title), author(author), category(category), quantity(qty), year_publish(year) {
    availability = (quantity > 0); // Initialize availability based on quantity
}

// Method to display book details
void Book::displayBookInfo() const {
    cout << "ID: " << ID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Category: " << category << endl;         // Display category
    cout << "Quantity: " << quantity << endl;
    cout << "Year Published: " << year_publish << endl;
    cout << "Available: " << (availability ? "Yes" : "No") << endl; // Display availability
}

// Function to parse CSV and populate the list of Book objects
vector<Book> importBooksFromCSV(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("Cannot open file: " + filename);
    }

    string line;
    bool isFirstLine = true;

    while (getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false; // Skip the header line
            continue;
        }

        if (line.empty()) continue; // Skip empty lines
        stringstream ss(line);
        string id, title, author, category, qty_str, year_str;

        // CSV format: ID,Title,Author,Category,Quantity,Year Published
        if (!getline(ss, id, ',')) {
            cerr << "Warning: Missing ID in line: " << line << endl;
            continue;
        }
        if (!getline(ss, title, ',')) {
            cerr << "Warning: Missing Title in line: " << line << endl;
            continue;
        }
        if (!getline(ss, author, ',')) {
            cerr << "Warning: Missing Author in line: " << line << endl;
            continue;
        }
        if (!getline(ss, category, ',')) {
            cerr << "Warning: Missing Category in line: " << line << endl;
            continue;
        }
        if (!getline(ss, qty_str, ',')) {
            cerr << "Warning: Missing Quantity in line: " << line << endl;
            continue;
        }
        if (!getline(ss, year_str, ',')) {
            cerr << "Warning: Missing Year Published in line: " << line << endl;
            continue;
        }

        // Trim whitespace from extracted strings (optional but recommended)
        auto trim = [](string& s) {
            size_t start = s.find_first_not_of(" \t\r\n");
            size_t end = s.find_last_not_of(" \t\r\n");
            if (start == string::npos || end == string::npos)
                s = "";
            else
                s = s.substr(start, end - start + 1);
        };

        trim(id);
        trim(title);
        trim(author);
        trim(category);
        trim(qty_str);
        trim(year_str);

        // Convert Quantity and Year Published to integers
        int quantity;
        int year_publish;
        try {
            quantity = stoi(qty_str);
            year_publish = stoi(year_str);
        }
        catch (const invalid_argument& e) {
            cerr << "Warning: Invalid number format in line: " << line << endl;
            continue; // Skip invalid lines
        }

        // Create and add the Book object
        books.emplace_back(id, title, author, category, quantity, year_publish);
    }

    file.close();
    return books;
}
