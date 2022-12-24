#include "json.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

#ifndef BANKUSER_HPP
#define BANKUSER_HPP

using json = nlohmann::json;
// List sounded better even though they aren't the same thing
using accountList = std::vector<std::string>; 

class BankUser{
    private:
        json bankS;
    public:
        BankUser() noexcept;
        ~BankUser() noexcept;
        void ReturningUser(json &oldBankS) noexcept;
        void NewAccount(const std::string &accountName, const double &startingBalance) noexcept;
        void DepositFunds(const int &accountNumber, const double amount) noexcept;
        void WithdrawFunds(const int &accountNumber, const double amount) noexcept;
        void BalanceInquiry(const int &accountNumber) noexcept;
        void AllAccounts() noexcept;
        void CloseAccount(const int &accountNumber) noexcept;
        void ModifyAccount(const int &accountNumber,const std::string &newName) noexcept;
        void UpdateJson() noexcept;
        int NumAccounts() noexcept;
};

#endif