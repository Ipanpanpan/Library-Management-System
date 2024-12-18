#include "Account.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Account::Account(const std::string& user, const std::string& pass, Library* lib)
    : username(user), password(pass), library(lib) {}

std::string Account::getUsername() const {
    return username;
}

void Account::setUsername(const std::string& user) {
    username = user;
}

std::string Account::getPassword() const {
    return password;
}

void Account::setPassword(const std::string& pass) {
    password = pass;
}

void Account::displayAccountInfo() const {
    std::cout << "Username: " << username << std::endl;
}
