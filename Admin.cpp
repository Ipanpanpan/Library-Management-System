#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Library.h" // Include the header file
#include "Admin.h"
#include "Utility.h"
#include "BookImport.h"

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
        mergeSort(adminobj.books, 0, adminobj.books.size()-1,compare_book_by_id);
        cout<<"Sorted Books by ID (Using Merge Sort):"<<endl;
        for(auto e:adminobj.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;
    }
    else if (sortedby = 2){
        bubbleSort(adminobj.books,compare_book_by_title);
        cout<<"Sorted Books by ID (Using Merge Sort):"<<endl;
        cout<<"ID\t"<<"Title\t"<<"Author\t"<<"Category\t"<<"Availability\t"<<"Year Published\t"<<endl;
        for(auto e:adminobj.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;

    }
    else{
        cout<<"Show All Current Books:"<<endl;
        cout<<"ID\t"<<"Title\t"<<"Author\t"<<"Category\t"<<"Availability\t"<<"Year Published\t"<<endl;
        for(auto e:adminobj.books) cout << e.ID <<" "<<e.title<<" "<<e.author<<" "<<e.category<<" "<<e.availability<<" "<<e.year_publish;
        cout<<endl;
    }
}

void Admin::get_all_transaction(){
    // selection sort
}

void Admin::search_transaction_receipt(user_id){
    // binary search
}

