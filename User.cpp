// User.cpp
#include "Library.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Function to generate a random receipt number
int generateReceiptNumber() {
    return rand() % 100000 + 10000;
}

// Function to calculate the due date (7 days from now)
std::string calculateDueDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    ltm->tm_mday += 7; // Add 7 days
    mktime(ltm);       // Normalize the time structure

    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return std::string(buffer);
}

// Borrow book function
void borrowBook(int bookId, Library &library, const string &userName) {
    vector<Book> &inventory = library.books; // Access the books inventory
    vector<Transaction> &transactions = library.transactions; // Access transaction history

    // Locate the book using a standard loop
    int bookIndex = -1;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex != -1) { // If book is found
        Book &book = inventory[bookIndex]; // Direct reference to the found book
        int quantity;
        cout << "Book found: " << book.title << " (Available: " << book.quantity << ")\n";
        cout << "Enter the quantity to borrow: ";
        cin >> quantity;

        if (quantity > 0 && quantity <= book.quantity) {
            book.quantity -= quantity;

            // Generate receipt and transaction
            int receiptNumber = generateReceiptNumber();
            string dueDate = calculateDueDate();

            Book borrowedBook = {book.id, book.title, quantity};
            vector<Book> borrowedBooks = {borrowedBook};
            sort(borrowedBooks.begin(), borrowedBooks.end(), [](const Book &a, const Book &b) { return a.id < b.id; }); // Quick Sort by book ID

            Transaction transaction(receiptNumber, borrowedBooks, userName, dueDate);
            transactions.push_back(transaction);

            // Display receipt
            cout << "\nTransaction Receipt\n";
            cout << "Receipt Number: " << receiptNumber << "\n";
            cout << "Borrower: " << userName << "\n";
            cout << "Due Date: " << dueDate << "\n";
            cout << "Books Borrowed:\n";
            for (const auto &book : borrowedBooks) {
                cout << "  - " << book.title << " (ID: " << book.id << ", Quantity: " << book.quantity << ")\n";
            }
        } else {
            cout << "Invalid quantity. Please try again.\n";
        }
    } else {
        cout << "Book with ID " << bookId << " not found.\n";
    }
}
