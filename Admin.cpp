#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Library.h" // Include the header file
#include "Admin.h"

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
        //id (Merge Sort)
    }
    else if (sortedby = 2){
        //title (Bubble Sort)
    }
    else{
        // print all (function from book import)
    }
}

vector<Transaction> Admin::get_all_transaction(){
    // selection sort
    vector<Transaction> = transactions = adminobj.get_transactions();
    int amount = transactions.size();

    for (int i = 0; i < amount-1; i++) {
        int min = i;

        for (int j = i+1; j < amount; j++){
            if (transactions[j] < transactions[min]) min = j;
            swap(transactions[i], transactions[min]);
        }
    }
}

void Admin::search_transaction_receipt(string id){
    // binary search
    vector<Transaction> users = adminobj.get_transactions();
    int amount = users.size();

    int low = 0;
    int high = amount-1;
    int mid;
    int index;

    while (low <= high){
        mid = (low + high)/2;
        if (users[mid] == id){
            users[mid].get_transaction();
            break;
        }
        else if (users[mid] < id){
            low = mid + 1;
        }
        else if (users[mid] > id){
            high = mid - 1;
        }
        else{
            cout<<"User ID does not exist.";
            break;
        }
}


}

