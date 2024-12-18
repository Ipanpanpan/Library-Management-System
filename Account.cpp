#include "Account.h"
#include <algorithm>
#include <iostream>

Account::Account(const std::string& user, const std::string& pass, Library& lib)
    : username(user), password(pass),library(&lib) {}

std::string Account::getUsername() const { return username; }
void Account::setUsername(const std::string& user) { username = user; }

std::string Account::getPassword() const { return password; }
void Account::setPassword(const std::string& pass) { password = pass; }


void Account::searchBook(const std::string& title, const std::vector<std::string>& books) {
    bool found = false;
    std::cout << "Searching for books with title containing: " << title << std::endl;
    for (const auto& book : books) {
        if (book.find(title) != std::string::npos) {
            std::cout << "Found: " << book << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found with the title: " << title << std::endl;
    }
}

void Account::getAllUsers(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    std::string line;
    std::cout << "--- User Accounts ---" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void Account::getAllBooks(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    std::string line;
    std::cout << "--- Books Available ---" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
