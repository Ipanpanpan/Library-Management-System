#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Library.h" // Include the header file
#include "Admin.h"
#include "Utility.h"

void Admin::addbook(ID, title, author, category, availability){
    adminobj.add_books(ID,title,author,category,availability);
}

void Admin::editbook(ID,title, author, category, availability){
    adminobj.edit_book(ID,title,author,category,availability);
}

void Admin::deletebook(ID){
    adminobj.remove_book(ID);
}

void Admin::get_all_book(sortedby = NULL){
    if (sorteddby = 1){
        mergeSort(adminobj.books, 0, adminobj.books.size()-1);
    }
    else if (sortedby = 2){
        //title (Bubble Sort)

    }
    else{
        // print all (function from book import)
    }
}

void Admin::get_all_transaction(){
    // selection sort
}

void Admin::search_transaction_receipt(user_id){
    // binary search
}

