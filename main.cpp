#include <iostream>
#include <vector>
#include "BookImport.h"  // Include the header file to access the Book class and importBooksFromCSV function
#include "Account.h"
#include "Library.h"
#include "User.h"  // Include User.h for borrowBook and returnBook functions

using namespace std;

int main() {
    string bookFilename = "books_info.csv";   // Path to book data file
    string accountFilename = "accounts_info.csv";   // Path to account data file
    Library library(bookFilename, accountFilename); // Initialize the library with books and accounts

    string userName = "SampleUser"; // Example user (can be replaced with actual login logic)
    char choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Display Books\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search for Books\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                // Display all books
                const vector<Book> &books = library.get_books();
                for (const auto &book : books) {
                    book.displayBookInfo();
                }
                break;
            }
            case '2': {
                // Borrow a book
                int bookId;
                cout << "Enter the Book ID to borrow: ";
                cin >> bookId;
                borrowBook(bookId, library, userName); // Call the borrowBook function
                calculateDueDate()// Add due date for the book borrowed
                break;
            }
            case '3': {
                // Return a book
                returnBooks(library.books, library.transactions, userName); // Call the returnBooks function
                break;
            }
            case '4': {
                // Search for books
                string title;
                cout << "Enter the title or part of the title to search: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                vector<string> bookTitles;
                for (const auto &book : library.get_books()) {
                    bookTitles.push_back(book.getTitle()); // Collect book titles
                }
                Account userAccount(userName, ""); // Temporary account instance
                userAccount.searchBook(title, bookTitles); // Call searchBook
                break;
            }
            case '5': {
                // View transaction history
                cout << "--- Transaction History ---\n";
                for (const auto &transaction : library.get_transactions()) {
                    transaction.displayTransactionInfo(); // Display transaction details
                }
                break;
            }
            case '6': {
                cout << "Exiting the Library System. Goodbye!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}
