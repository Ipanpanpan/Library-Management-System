#include "BookImport.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Book::Book()
    : ID("-99"), title("default"), author("ivan"), category("default"), availability(false), year_publish(1000) {}

Book::Book(const std::string& id, const std::string& title, const std::string& author, const std::string& category, bool availability, int year)
    : ID(id), title(title), author(author), category(category), availability(availability), year_publish(year) {}

void Book::displayBookInfo() const {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Year Published: " << year_publish << std::endl;
    std::cout << "Available: " << (availability ? "Yes" : "No") << std::endl;
}

std::vector<Book> importBooksFromCSV(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id, title, author, category, availability_str, year_str;

        if (!std::getline(ss, id, ',') ||
            !std::getline(ss, title, ',') ||
            !std::getline(ss, author, ',') ||
            !std::getline(ss, category, ',') ||
            !std::getline(ss, availability_str, ',') ||
            !std::getline(ss, year_str, ',')) {
            std::cerr << "Warning: Incomplete data in line: " << line << std::endl;
            continue;
        }

        auto trim = [](std::string& s) {
            s.erase(0, s.find_first_not_of(" \t\r\n"));
            s.erase(s.find_last_not_of(" \t\r\n") + 1);
        };

        trim(id);
        trim(title);
        trim(author);
        trim(category);
        trim(availability_str);
        trim(year_str);

        bool availability;
        int year_publish;
        try {
            availability = (availability_str == "1");
            year_publish = std::stoi(year_str);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Warning: Invalid format in line: " << line << std::endl;
            continue;
        }

        books.emplace_back(id, title, author, category, availability, year_publish);
    }

    file.close();
    return books;
}

bool compareBookByID(const Book& l, const Book& r) {
    return l.ID < r.ID;
}

bool compareBookByTitle(const Book& l, const Book& r) {
    return l.title < r.title;
}
