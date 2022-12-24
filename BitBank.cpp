#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <type_traits>
#include "json.hpp"
#include "BankUser.hpp"

using json = nlohmann::json;
using std::cout, std::cin, std::endl;

/* ConvertToMoney */
/* Changes the double entered into money format */
/* by rounding to the second decimal place */
/* @input-The double to be changed*/
void ConvertToMoney(double &input){
    input = std::ceil(input * 100.0) / 100.0;
}

/* AccNumGetter */
/* Get and Validate users account numbers they enter */
/* @AccountNumber - where user input for account number is stored */
/* @user - BankUser that gives the length of the account */
/* @userQ - Question to ask the user */
void AccNumGetter(int &accountNumber, BankUser &user, std::string &userQ){
    bool validInput = false;
    cout << userQ << endl;
    user.AllAccounts();
    while(!validInput){
        cout << ">> ";
        int numAccounts = user.NumAccounts();
        if (cin >> accountNumber 
            && (0 < accountNumber && accountNumber < numAccounts+1)) {
            validInput = true;
        } else {
            cout << "invalid input enter an integer between 0 and " << numAccounts+1 << "\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

/* FundGetter */
/* Get and validate funds input */
/* @fund - Where funds user input is stored */
/* @fundQ - Question to ask the user */
void FundGetter(double &fund, std::string &fundQ){
    bool validInput = false;
    while(!validInput){
        cout << fundQ << endl;
        cout << ">> ";
        if (cin >> fund) {
            validInput = true;;
        } else {
            cout << "invalid input\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    ConvertToMoney(fund);
}

int main(int argc, char **argv){
    std::string accountName, accQ, fundQ;
    double startingBalance, fund;
    int accountNumber;
    bool validInput;
    json bankSParsed;

    /* Open bank storage json file */
    std::ifstream bankSIn("bankStorage.json");

    /* If there is a file: */
    /* print returning welcome and parse JSON */
    /* otherwise: */
    /* print basic welcome */
    BankUser *user = new BankUser();
    if(bankSIn.is_open()){
        cout << "*****************************" << endl;
        cout << "* Welcome Back to Bit Bank™ *" << endl;
        cout << "*****************************" << endl;
        bankSParsed = json::parse(bankSIn);
        user->ReturningUser(bankSParsed);
    }else{
        cout << "************************" << endl;
        cout << "* Welcome to Bit Bank™ *" << endl;
        cout << "************************" << endl;
    }
    bankSIn.close();

    auto userInput = 0;
    while(userInput != 8){
        /*User Input Options*/
        cout << "Enter a command number:" << endl;
        cout << "1. Create a new Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Balance Enquiry" << endl;
        cout << "5. All Accounts" << endl;
        cout << "6. Close Account" << endl;
        cout << "7. Manage Accounts" << endl;
        cout << "8. Exit" << endl;

        /*User Input*/
        cout << ">> ";
        cin >> userInput;
        validInput = false;

        /*User Input Cases*/
        switch (userInput)
        {
        case 1 /* New Account */:
            cout << "New Account Name: ";
            cin >>  accountName;

            fundQ = "Accounts Starting Balance: ";
            FundGetter(startingBalance, fundQ);

            user->NewAccount(accountName, startingBalance);
            break;
        
        case 2 /* Deposit Funds */:
            accQ = "Which Account to Deposit?";
            AccNumGetter(accountNumber, (*user), accQ);

            fundQ = "How Much to Deposit?";
            FundGetter(fund, fundQ);

            user->DepositFunds(accountNumber-1,fund);
            break;

        case 3 /* Withdraw Funds*/: 
            accQ = "Which Account to Withdraw From?";
            AccNumGetter(accountNumber, (*user), accQ);

            fundQ = "How Much Would You Like to Withdraw?";
            FundGetter(fund, fundQ);
            
            user->WithdrawFunds(accountNumber-1, fund);
            break;

        case 4 /* Balance Enquiry */: 
            accQ = "Which Accounts Balance?";
            AccNumGetter(accountNumber, (*user), accQ);

            user->BalanceInquiry(accountNumber-1);
            break;

        case 5 /* All Accounts */: 
            cout << "All Accounts: ";
            user->AllAccounts(); 
            break;
        
        case 6 /* Close Account */ :
            accQ = "Which Account to Close?";
            AccNumGetter(accountNumber,(*user), accQ);

            user->CloseAccount(accountNumber-1);
            break;

        case 7 /* Manage Accounts */:
            accQ = "Which Account to Manage?";
            AccNumGetter(accountNumber,(*user), accQ);

            cout << "New Account Name: ";
            cout << ">> ";
            cin >> accountName;

            user->ModifyAccount(accountNumber, accountName);
            break;
        
        case 8 /* Exit */: 
            break;

        default:
            cout << "Select A Command 1-8" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    cout << "Thank You For Visiting Bit Bank!" << endl;
}