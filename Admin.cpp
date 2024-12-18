#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Library.h" // Include the header file
#include "Admin.h"
#include "Utility.h"
#include "BookImport.h"


Admin::Admin(const std::string& user, const std::string& pass, Library& lib):
    Account(user, pass, lib){};

void Admin::addbook(string ID, string title, string author, string category, bool availability, int yearPublish){
    library->add_books(ID,title,author,category,availability);
}

void Admin::editbook(ID,title, author, category, availability){
    library.edit_book(ID,title,author,category,availability);
}

void Admin::deletebook(ID){
    library.remove_book(ID);
}

void Admin::get_all_book(sortedby = NULL){
    if (sorteddby = 1){
        mergeSort(library.books, 0, library.books.size()-1,compare_book_by_id);
        cout<<"Sorted Books by ID (Using Merge Sort):"<<endl;
        for(auto e:library.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;
    }
    else if (sortedby = 2){
        bubbleSort(library.books,compare_book_by_title);
        cout<<"Sorted Books by ID (Using Merge Sort):"<<endl;
        cout<<"ID\t"<<"Title\t"<<"Author\t"<<"Category\t"<<"Availability\t"<<"Year Published\t"<<endl;
        for(auto e:library.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;

    }
    else{
        cout<<"Show All Current Books:"<<endl;
        cout<<"ID\t"<<"Title\t"<<"Author\t"<<"Category\t"<<"Availability\t"<<"Year Published\t"<<endl;
        for(auto e:library.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;
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

