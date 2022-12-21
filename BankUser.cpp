#include "json.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "BankUser.hpp"

using json = nlohmann::json;
// List sounded better even though they aren't the same thing
using accountList = std::vector<std::string>; 

/* New User(Default) Constructor */
/* Add accounts to bankS */
BankUser::BankUser() noexcept{
    bankS["accounts"] = "";
}

/* Returning User Constructor */
/* Move old bank storage into bankS */
/* @oldbankS - bank storage from last use*/
BankUser::BankUser(const json &oldBankS) noexcept{
    bankS = std::move(oldBankS);
}

/* NewAccount */
/* Adds a new account to the bank storage */
/* @accountName - new accounts name */
void BankUser::NewAccount(const std::string &accountName) noexcept{
    json newAccount;
    newAccount["name"] = accountName;
    newAccount["balance"] = 0.00;
    bankS["accounts"].push_back(newAccount);
}

/* DepositFunds */
/* Deposits funds(amount) in a given account(accountName) */
/* @accountName - account to deposit money into */
/* @amount - amount of money to deposit */
void BankUser::DepositFunds(const std::string &accountName, const double amount) noexcept{

}

/* BalanceInquiry */
/* $Returns the balance of a certain account(accountName) */
/* @accountName - account being queried */
constexpr double BankUser::BalanceInquiry(const std::string &accountName) noexcept{

}

/* AllAccounts */
/* $Returns a std::vector<std::string> containing all of the accounts */
constexpr accountList BankUser::AllAccounts() noexcept{

}

/* CloseAccount */
/* Closes an account(accountName) */
/* @accountName - Account being closed */
void BankUser::CloseAccount(const std::string &accountName) noexcept{

}

/* ModifyAccount */
/* Change the name of an account */
/* @accountName - Account having name changed */
/* @newName - New account name */
void BankUser::ModifyAccount(const std::string &accountName, const std::string &newName) noexcept{

}



