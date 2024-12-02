#include <iostream>
#include <vector>
#include "BookImport.h"  // Include the header file to access the Book class and importBooksFromCSV function

using namespace std;

int main() {
    string filename = "C:\\Users\\Ivan Nathanael\\Uni\\DSA\\Project\\books_info.csv"; // Correct file path with double backslashes
    vector<Book> books = importBooksFromCSV(filename);

    // Display all the books in the list
    for (const auto& book : books) {
        book.displayBookInfo();
    }
    cout << "halo" << endl;
    return 0;
}
