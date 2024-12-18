#include "BookImport.h"
#include <sstream>
#include <fstream>        // For file operations
#include <iostream>       // For display purposes
#include <exception>

// Constructor implementation
Book::Book(string id, string title, string author, string category, bool availability, int year)
    : ID(id), title(title), author(author), category(category), availability(availability), year_publish(year) {
}

// Method to display book details
void Book::displayBookInfo() const {
    cout << "ID: " << ID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Category: " << category << endl;
    cout << "Year Published: " << year_publish << endl;
    cout << "Available: " << (availability ? "Yes" : "No") << endl;
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
        string id, title, author, category, availability_str, year_str;

        // CSV format: ID,Title,Author,Category,Availability,Year Published
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
        if (!getline(ss, availability_str, ',')) {
             cerr << "Warning: Missing Availability in line: " << line << endl;
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
        trim(availability_str);
          trim(year_str);
        // Convert Availability and Year Published to respective types
        bool availability;
        int year_publish;
        try {
           availability = (availability_str == "1"); // Convert "1" to true, "0" to false
           year_publish = stoi(year_str);
        }
         catch (const invalid_argument& e) {
            cerr << "Warning: Invalid number or format in line: " << line << endl;
            continue; // Skip invalid lines
        }

        // Create and add the Book object
        books.emplace_back(id, title, author, category, availability, year_publish);
    }

    file.close();
    return books;
}

//Ini buat compare_book_by_id ya bel yak ada
bool compare_book_by_id(const Book& l, const Book& r){
    return l.ID < r.ID;
}

//Ini buat compare_book_by_title ya bel yak ada
bool compare_book_by_title(const Book& l, const Book& r){
    return l.title < r.title;
}
