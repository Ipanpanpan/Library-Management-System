// User.cpp
#include "Library.h"
#include "User.h"
#include "Transaction.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Function to generate a random receipt number
int generateReceiptNumber() {
    receipt_number = rand() % 100000 + 10000
    return receipt_number;
}

// Function to calculate a due date (7 days from the current date)
std::string calculateDueDate() {
    time_t now = time(0); // Get current time
    tm *ltm = localtime(&now);

    ltm->tm_mday += 7;    // Add 7 days to the current date
    mktime(ltm);          // Normalize the time structure

    // Format the date as YYYY-MM-DD
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return std::string(buffer);
}

void User::borrowBook(int bookId, Library &library) {
    std::vector<Book> &inventory = library.books; // Access the books inventory
    std::vector<Transaction> &transactions = library.transactions; // Access transaction history

    // Locate the book in the inventory
    int bookIndex = -1;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex != -1) { // If book is found
        Book &book = inventory[bookIndex];
        int quantity;
        std::cout << "Book found: " << book.title << " (Available: " << book.quantity << ")\n";
        std::cout << "Enter the quantity to borrow: ";
        std::cin >> quantity;

        if (quantity > 0 && quantity <= book.quantity) {
            book.quantity -= quantity;

            // Generate receipt number and calculate due date
            int receipt_number = rand() % 100000 + 10000; // Generate a unique receipt number
            std::string currentDateTime = Transaction::getCurrentDateTime(); // Get the current date/time
            std::string dueDate = calculateDueDate(); // Calculate the due date

            // Log the borrowing transaction
            transactions.emplace_back(receiptNumber, "N/A", getUsername(), currentDateTime);

             // Display the receipt
            std::cout << "\nTransaction Receipt:\n";
            std::cout << "Receipt Number: " << receiptNumber << "\n";
            std::cout << "Borrower: " << getUsername() << "\n";
            std::cout << "Borrow Date: " << currentDateTime << "\n";
            std::cout << "Due Date: " << dueDate << "\n";

            // Sort borrowed books by ID (Quick Sort)
            std::sort(transactions.begin(), transactions.end(), [](const Transaction &a, const Transaction &b) {
                return a.getReceiptNumber() < b.getReceiptNumber();
            });

            std::cout << "Would you like to borrow more books? (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                return; // Prompt for borrowing more books
            }
        } else {
            std::cout << "Invalid quantity. Please try again.\n";
        }
    } else {
        std::cout << "Book with ID " << bookId << " not found.\n";
    }
}
}

// Return books implementation
void returnBooks(vector<Book> &inventory, vector<Transaction> &transactions) {
    int receipt_number;
    std::cout << "\nEnter your receipt number: ";
    std::cin >> receipt_number;

    int transactionIndex = -1;
    for (int i = 0; i < transactions.size(); ++i) {
        if (transactions[i].getReceiptNumber() == receiptNumber &&
            transactions[i].getUserName() == getUserName()) {
            transactionIndex = i;
            break;
        }
    }

    if (transactionIndex != -1) {
        std::cout << "\nBooks being returned:\n";

        for (const Book &returnedBook : booksToReturn) {
            for (int j = 0; j < inventory.size(); ++j) {
                if (inventory[j].id == returnedBook.id) {
                    inventory[j].quantity += returnedBook.quantity;
                    std::cout << "  - " << returnedBook.title << " (ID: " << returnedBook.id << ", Quantity: " << returnedBook.quantity << ")\n";
                    break;
                }
            }
        }
        // Remove the transaction
        transactions.erase(transactions.begin() + transactionIndex);
        std::cout << "\nBooks returned successfully.\n";
    } else {
        std::cout << "Invalid receipt number or user name. Please try again.\n";
    }
}    if (transactionIndex != -1) {
        // Update inventory and log the return action
        const std::string returnDate = Transaction::getCurrentDateTime();
        transactions.emplace_back(-receiptNumber, "N/A", getUsername(), returnDate); // Use negative receipt number for return

        std::cout << "Return successful! Receipt logged.\n";
    } else {
        std::cout << "Invalid receipt number or username.\n";
    }
}

void User::getTransactionHistory(const std::vector<Transaction>& transactions) const {
    std::string currentUsername = getUsername();
    std::cout << "Transaction History for User: " << currentUsername << "\n";
    std::cout << "-----------------------------------------------\n";

    bool hasTransactions = false;

    for (const auto& transaction : transactions) {
        if (transaction.getUsername() == currentUsername) {
            hasTransactions = true;

            // Display transaction details
            std::cout << "Receipt Number: " << transaction.getReceiptNumber() << "\n";
            std::cout << "Borrow Date: " << transaction.getBorrowDate() << "\n";
            std::cout << "Due Date: " << transaction.getDueDate() << "\n";
            std::cout << "-----------------------------------------------\n";
        }
    }

    if (!hasTransactions) {
        std::cout << "No transactions found for this user.\n";
    }
}
