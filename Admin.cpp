#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Library.h" // Include the header file
#include "Admin.h"

Library adminobj;
void Admin::addbook(ID, title, author, category, availability){
    adminobj.add_books(ID,title,author,category,availability);
}

void Admin::editbook(ID,title, author, category, availability){
    adminobj.edit_book(ID,title,author,category,availability);
}

void Admin::deletebook(ID){
    adminobj.remove_book(ID);
}


