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
        BankUser(const json &oldBankS) noexcept;
        ~BankUser() noexcept;
        void NewAccount(const std::string &accountName);
        void DepositFunds(const std::string &accountName, const double amount) noexcept;
        void WithdrawFunds(const std::string &accountName, const int amount) noexcept;
        constexpr double BalanceInquiry(const std::string &accountName) noexcept;
        constexpr accountList AllAccounts() noexcept;
        void CloseAccount(const std::string &accountName) noexcept;
        void ModifyAccount(const std::string &newName) noexcept;
};


#endif