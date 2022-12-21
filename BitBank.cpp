#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char **argv){
    using std::cout, std::cin, std::endl;

    /* Open bank storage json file */
    std::ifstream bankSIn("bankStorage.json");
    json bankSParsed;

    /* If there is a file: */
    /* print returning welcome and parse JSON */
    /* otherwise: */
    /* print basic welcome */
    if(bankSIn.is_open()){
        bankSParsed = json::parse(bankSIn);
        cout << "*****************************" << endl;
        cout << "* Welcome Back to Bit Bank™ *" << endl;
        cout << "*****************************" << endl;
    }else{
        cout << "************************" << endl;
        cout << "* Welcome to Bit Bank™ *" << endl;
        cout << "************************" << endl;
    }
    bankSIn.close();

    auto userInput = 0;
    while(userInput != 7){
        /*User Input Options*/
        cout << "Enter a command number:" << endl;
        cout << "1. Create a new Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Balance Enquiry" << endl;
        cout << "5. All Accounts" << endl;
        cout << "6. Manage Accounts" << endl;
        cout << "7. Exit" << endl;

        /*User Input*/
        cout << ">> ";
        cin >> userInput;


        /*User Input Cases*/
        switch (userInput)
        {
        case 1:

            break;
        
        case 2:
            break;
        
        case 3: 
            break;

        case 4: 
            break;

        case 5: 
            break;
        
        case 6:
            break;
        
        case 7: 
            break;

        default:
            break;
        }

    }

    json Account;
    Account["name"] = "newAccount";
    Account["money"] = 2;
    bankSParsed["accounts"].push_back(Account);

    std::ofstream bankSOut("bankStorage.json");
    bankSOut << std::setw(4) << bankSParsed << endl;


    cout << "Thank You For Visiting Bit Bank!" << endl;
}

    // string isNewUser;
    // string username;
    // string password;
    // std::cout << "are you a returning user? (y or n) " << std::endl;

    // bool goodInput = false;
    // while(!goodInput){
    //     std::cin >> isNewUser;
    //     if(isNewUser.toLower() == "y"){
    //         goodInput = newUser(username, password);
    //     }else if(isNewUser.lower() == "n"){
    //         goodInput = returningUser(username, password);
    //     }else{
    //         std::cout << "*** Invalid Response use (y or n) ***";
    //     }
    // }
    // std::cout << "Username: ";
    // std::cin >> username;
    // std::cout << "Password: ";
    // std::cin >> password;
    // std::cout << username << std::endl;


// bool newUser(std::string &username, std::string &password){

// }

// bool returningUser(std::string &username, std::string &password){

// }