#include <iostream>
#include <vector>
#include <limits> // Required for numeric_limits
#include "BookImport.h"
#include "Account.h"
#include "Library.h"
#include "User.h"
#include "Admin.h"

int main() {
    std::string bookFilename = "books_info.csv";
    std::string accountFilename = "account_data.csv";
    Library library(bookFilename, accountFilename);

    Account* currentAccount = nullptr;
    std::string username, password;
    bool loggedIn = false;

    while (true) {
        while (!loggedIn) {
            std::cout << "\nLibrary Management System Login\n";
            std::cout << "1. Login as Admin\n";
            std::cout << "2. Login as User\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;

            if (choice == 3) {
                std::cout << "Exiting...\n";
                return 0;
            }

            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            currentAccount = library.getAccount(username, password);

            if (currentAccount != nullptr) {
                loggedIn = true;
                std::cout << "Login successful.\n";
            } else {
                std::cout << "Invalid username or password.\n";
            }
        }

        if (dynamic_cast<Admin*>(currentAccount) != nullptr) {
            // Admin menu
            Admin* admin = dynamic_cast<Admin*>(currentAccount);
            int adminChoice;
            do {
                std::cout << "\nAdmin Menu\n";
                std::cout << "1. Add Book\n";
                std::cout << "2. Search Book\n";
                std::cout << "3. Edit Book\n";
                std::cout << "4. Delete Book\n";
                std::cout << "5. View All Books (with sorting options)\n";
                std::cout << "6. View All Transactions\n";
                std::cout << "7. Search Transaction by User ID\n";
                std::cout << "8. Logout\n";
                std::cout << "Enter your choice: ";
                std::cin >> adminChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (adminChoice) {
                    case 1: {
                        std::string ID, title, author, category;
                        int yearPublish;
                        bool availability;
                        std::cout << "Enter Book ID: ";
                        std::getline(std::cin, ID);
                        std::cout << "Enter Title: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter Author: ";
                        std::getline(std::cin, author);
                        std::cout << "Enter Category: ";
                        std::getline(std::cin, category);
                        std::cout << "Enter Year Published: ";
                        std::cin >> yearPublish;
                        std::cout << "Is the book available? (1 for Yes, 0 for No): ";
                        std::cin >> availability;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        admin->addBook(ID, title, author, category, availability, yearPublish);
                        std::cout << "Book added successfully.\n";
                        break;
                    }
                    case 2: {
                        std::string title;
                        std::cout << "Enter the title or part of the title to search: ";
                        std::getline(std::cin, title);
                        admin->searchBook(title);
                        break;
                    }
                    case 3: {
                        std::string ID, title, author, category;
                        int yearPublish;
                        bool availability;
                        std::cout << "Enter Book ID to edit: ";
                        std::getline(std::cin, ID);
                        std::cout << "Enter New Title: ";
                        std::getline(std::cin, title);
                        std::cout << "Enter New Author: ";
                        std::getline(std::cin, author);
                        std::cout << "Enter New Category: ";
                        std::getline(std::cin, category);
                        std::cout << "Enter New Year Published: ";
                        std::cin >> yearPublish;
                        std::cout << "Is the book available? (1 for Yes, 0 for No): ";
                        std::cin >> availability;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        admin->editBook(ID, title, author, category, availability, yearPublish);
                        std::cout << "Book updated successfully.\n";
                        break;
                    }
                    case 4: {
                        std::string ID;
                        std::cout << "Enter Book ID to delete: ";
                        std::getline(std::cin, ID);
                        admin->deleteBook(ID);
                        std::cout << "Book deleted successfully.\n";
                        break;
                    }
                    case 5: {
                        int sortOption;
                        std::cout << "Sort books by:\n";
                        std::cout << "1. ID (Merge Sort)\n";
                        std::cout << "2. Title (Bubble Sort)\n";
                        std::cout << "3. No sorting\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> sortOption;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        admin->getAllBooks(sortOption);
                        break;
                    }
                    case 6: {
                        admin->getAllTransactions();
                        break;
                    }
                    case 7: {
                        std::string userID;
                        std::cout << "Enter User ID to search for transactions: ";
                        std::getline(std::cin, userID);
                        admin->searchTransactionReceipt(userID);
                        break;
                    }
                    case 8: {
                        loggedIn = false;
                        currentAccount = nullptr;
                        std::cout << "Logged out.\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
            } while (adminChoice != 8);
        } else if (dynamic_cast<User*>(currentAccount) != nullptr) {
            // User menu
            User* user = dynamic_cast<User*>(currentAccount);
            int userChoice;
            do {
                std::cout << "\nUser Menu\n";
                std::cout << "1. Search Book\n";
                std::cout << "2. Borrow Book\n";
                std::cout << "3. Return Book\n";
                std::cout << "4. Logout\n";
                std::cout << "Enter your choice: ";
                std::cin >> userChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (userChoice) {
                    case 1: {
                        std::string title;
                        std::cout << "Enter the title or part of the title to search: ";
                        std::getline(std::cin, title);
                        user->searchBook(title);
                        break;
                    }
                    case 2: {
                        std::string bookId;
                        int quantity;
                        std::cout << "Enter the ID of the book to borrow: ";
                        std::getline(std::cin, bookId);
                        std::cout << "Enter the quantity to borrow: ";
                        std::cin >> quantity;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        user->borrowBook(bookId, quantity);
                        break;
                    }
                    case 3: {
                        int transactionId;
                        std::cout << "Enter the transaction ID to return the book: ";
                        std::cin >> transactionId;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        user->returnBook(transactionId);
                        break;
                    }
                    case 4: {
                        loggedIn = false;
                        currentAccount = nullptr;
                        std::cout << "Logged out.\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
            } while (userChoice != 4);
        }
    }

    return 0;
}
