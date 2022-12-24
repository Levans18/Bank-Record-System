#include "json.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <filesystem>
#include "BankUser.hpp"


using json = nlohmann::json;
using std::cin, std::cout, std::endl;
// List sounded better even though they aren't the same thing
using accountList = std::vector<std::string>; 

/* New User(Default) Constructor */
/* Add accounts to bankS */
BankUser::BankUser() noexcept{
    bankS["accounts"] = {};
}

/* Returning User Constructor */
/* Move old bank storage into bankS */
/* @oldbankS - bank storage from last use*/
void BankUser::ReturningUser(json &oldBankS) noexcept{
    bankS = std::move(oldBankS);
}

/* NewAccount */
/* Adds a new account to the bank storage */
/* @accountName - new accounts name */
void BankUser::NewAccount(const std::string &accountName, const double &startingBalance) noexcept{
    json newAccount;
    newAccount["name"] = accountName;
    newAccount["balance"] = startingBalance;
    bankS["accounts"].push_back(newAccount);
    UpdateJson();
}

/* DepositFunds */
/* Deposits funds(amount) in a given account(accountName) */
/* @accountNumber - account number to deposit money into */
/* @amount - amount of money to deposit */
void BankUser::DepositFunds(const int &accountNumber, const double amount) noexcept{
    double currBalance = bankS["accounts"][accountNumber]["balance"];
    bankS["accounts"][accountNumber]["balance"] = std::ceil((currBalance + amount) * 100.0) / 100.0;
    UpdateJson();
}

/* WithdrawFunds */
/* Withraw funds(amount) from a given account(accountName) */
/* @accountNumber - account number to widthdraw from */
/* @amount - amount to be withdrawn */
void BankUser::WithdrawFunds(const int &accountNumber, const double amount) noexcept{
    double currBalance = bankS["accounts"][accountNumber]["balance"];
    bankS["accounts"][accountNumber]["balance"] = std::ceil((currBalance - amount) * 100.0) / 100.0;
    UpdateJson();
}

/* BalanceInquiry */
/* $Returns the balance of a certain account(accountName) */
/* @accountName - account being queried */
void BankUser::BalanceInquiry(const int &accountNumber) noexcept{
    cout << bankS["accounts"][accountNumber]["name"] << ":" << endl;
    cout << "\t Balance: " << bankS["accounts"][accountNumber]["balance"] << endl;
}

/* AllAccounts */
/* $Returns a std::vector<std::string> containing all of the accounts */
void BankUser::AllAccounts() noexcept{
    int accountNumber = 1;
    cout << "| ";
    for(auto account : bankS["accounts"]){
        cout << accountNumber++ << ". " << (std::string)account["name"] << " | ";
    }
    cout << endl;
}

/* CloseAccount */
/* Closes an account(accountName) */
/* @accountName - Account being closed */
void BankUser::CloseAccount(const int &accountNumber) noexcept{
    bankS["accounts"].erase(accountNumber-1);
    UpdateJson();
}

/* ModifyAccount */
/* Change the name of an account */
/* @accountName - Account having name changed */
/* @newName - New account name */
void BankUser::ModifyAccount(const int &accountNumber, const std::string &newName) noexcept{
    bankS["accounts"][accountNumber-1]["name"] = newName;
    UpdateJson();
}

/* UpdateJson */
/* Delete and Update The Json File */
void BankUser::UpdateJson() noexcept{
    std::filesystem::path storagePath = "bankStorage.json";
    storagePath.remove_filename();
    std::ofstream bankSOut("bankStorage.json");
    bankSOut << std::setw(4) << bankS << endl;
    bankSOut.close();
}

/* NumAccounts */
/* Get The Number of Accounts*/
int BankUser::NumAccounts() noexcept {
    return bankS["accounts"].size();
}
