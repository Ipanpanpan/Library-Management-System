#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Account{

private:
    //Attributes
    std::string username;
    std::string password;
    std::string personalInfo;

public:
    //Constructor
    Account(const std::string& user, const std::string& pass);

    //Getters and Setter
    std::string getUsername() const;
    void setUsername(const std::string& user);

    std::string getPassword() const;
    void setPassword(const std::string& pass);

    std::string getPersonalInfo() const;
    void setPersonalInfo(const std::string& info);

    void searchBook(const std::string& title, const std::vector<std::string>& books);
    void getAllUsers(const std::string& filePath);
    void getAllBooks(const std::string& filePath);
};

#endif // ACCOUNT_H
