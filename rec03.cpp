/*
  rec03.cpp
  Kamil Paczkowski - 9/19/25
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account {
     string name;
     int accNumber;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class AccountV2 {
    friend ostream& operator << (ostream& os, const AccountV2& account);

    public:
        AccountV2(const string& name, int accNumber);

        const string& getName() const {return name;}
        int getAccNumber() const {return accNumber;}
    
    private:
        string name;
        int accNumber;
};
AccountV2::AccountV2(const string& nameIn, int accNumberIn) : name(nameIn), accNumber(accNumberIn) {}


ostream& operator<<(ostream& os, const AccountV2& account) {
    // os << "Name: " << account.getName()
    //    << "Account Number: " << account.accNumber();
    os << "Name: " << account.name << " Account Number: " << account.accNumber;
    return os;
}

// Task 3
// Define another Account class (use a different name than in Task
// 1&2) and a Transaction class. The Transaction class is to be
// defined outside of the Account class, i.e. it is not "nested".

class Transaction {
    friend ostream& operator<<(ostream& os, const Transaction& tran);
public:
    const string& getType() const { return type; }
    int getAmount() const { return amount; }

    Transaction(const string& typeIn, int amountIn) : type(typeIn), amount(amountIn) {}

private:
    string type;
    int amount;
};

ostream& operator<<(ostream& os, const Transaction& tran) {
    os << tran.type << ' ' << tran.amount;
    return os;
}

class AccountV3 {
    friend ostream& operator << (ostream& os, const AccountV3& account);

    public:
        AccountV3(const string& accName, int accountNum) : name(accName), accNumber(accountNum), Balance(0) {}

        void deposit(int Amount) {
            Balance += Amount;
            History.push_back(Transaction("Deposit", Amount));
        }

        void withdrawal(int Amount) {
            if (Balance < Amount) {
                cout << "Account# " << accNumber
                << " has only " << Balance
                << ". Insufficient for withdrawal of " << Amount << ".\n";
                return;
            }
            Balance -= Amount;
            History.push_back(Transaction("Withdraw", Amount));
        }

        int getAccountNumber() const { return accNumber; }

    private:
        string name;
        int accNumber;
        int Balance;
        vector<Transaction> History;
};

ostream& operator<<(ostream& os, const AccountV3& account) {
    os << "Name: " << account.name
       << " Account Number: " << account.accNumber
       << " Balance: " << account.Balance << "\n";
    for (size_t i = 0; i < account.History.size(); ++i) {
        os << "  " << account.History[i] << "\n";
    }
    return os;
}

// Task 4
// Define yet another Account class, this time with a nested public
// Transaction class. Again use a different name for the Account class
// than in the previous Tasks. Note that it is NOT necessary to rename
// the Transaction class, since it is nested.

class AccountV4 {
    public:
        class Transaction {
            friend ostream& operator<<(ostream& os, const AccountV4::Transaction& t);
        public:
            Transaction(const string& typeIn, int amountIn) {
                type = typeIn;
                amount = amountIn;
            }
            const string& getType() const { return type; }
            int getAmount() const { return amount; }
        private:
            string type;
            int amount;
        };
    
        friend ostream& operator<<(ostream& os, const AccountV4& account);
    
        AccountV4(const string& accName, int accountNum) : name(accName), accNumber(accountNum), Balance(0) {}
    
        void deposit(int Amount) {
            Balance += Amount;
            History.push_back(Transaction("Deposit", Amount));
        }
    
        void withdrawal(int Amount) {
            if (Balance < Amount) {
                cout << "Account# " << accNumber
                << " has only " << Balance
                << ". Insufficient for withdrawal of " << Amount << ".\n";
                return;
            }
            Balance -= Amount;
            History.push_back(Transaction("Withdraw", Amount));
        }
    
        int getAccountNumber() const { return accNumber; }
    
    private:
        string name;
        int accNumber;
        int Balance;
        vector<Transaction> History;
};
    
ostream& operator<<(ostream& os, const AccountV4::Transaction& t) {
    os << t.getType() << ' ' << t.getAmount();
    return os;
}
    
ostream& operator<<(ostream& os, const AccountV4& account) {
    os << "Name: " << account.name
        << " Account Number: " << account.accNumber
        << " Balance: " << account.Balance << "\n";
    for (size_t i = 0; i < account.History.size(); ++i) {
        os << "  " << account.History[i] << "\n";
    }
    return os;
}
    
// Task 5
// Same as Task 4, but make the Transaction nested class private.
// Yes, the Account class needs a new name but, again, the Transaction
// class does not.


int main()
{
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n"
         << "Filling vector of struct objects, define a local struct instance\n"
         << "and set fields explicitly:\n";
     
     vector<Account> accounts;
     ifstream acctFile;

     acctFile.open("accounts.txt");

     string name;
     int accNumber;

     while (acctFile >> name >> accNumber) {
          Account a;
          a.name = name;
          a.accNumber = accNumber;
          accounts.push_back(a);
     }
     acctFile.close();

     for (size_t i = 0; i < accounts.size(); ++i) {
          cout << accounts[i].name << ' ' << accounts[i].accNumber << '\n';
     }
     
    //      1b
    cout << "Task1b:\n"
         << "Filling vector of struct objects, using {} initialization:\n";
     
     accounts.clear();
     acctFile.clear();
     acctFile.open("accounts.txt");

     while (acctFile >> name >> accNumber) {
          Account a = {name, accNumber};   
          accounts.push_back(a);
     }
     acctFile.close();
  
     for (size_t i = 0; i < accounts.size(); ++i) {
          cout << accounts[i].name << ' ' << accounts[i].accNumber << '\n';
     }
    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:"
         << "\nFilling vector of class objects, using local class object:\n";

    vector<AccountV2> cAccounts;

    acctFile.clear();
    acctFile.open("accounts.txt");

    while (acctFile >> name >> accNumber) {
        AccountV2 newAccount(name, accNumber);
        cAccounts.push_back(newAccount);
    }
    acctFile.close();

    for (size_t i = 0; i < cAccounts.size(); ++i) {
        cout << "Name: " << cAccounts[i].getName()
             << " Account Number: " << cAccounts[i].getAccNumber() << "\n";
    }

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    
    for (size_t i = 0; i < cAccounts.size(); ++i) {
        cout << cAccounts[i] << "\n";
    }

    cout << "\nTask2c:\n"
         << "output using output operator as friend without getters\n";

    for (size_t i = 0; i < cAccounts.size(); ++i) {
        cout << cAccounts[i] << "\n";
    }

    cout << "\nTask2d:\n"
         << "Filling vector of class objects, using temporary class object:\n";

    vector<AccountV2> cAccountsPB;
    acctFile.clear();
    acctFile.open("accounts.txt");
    while (acctFile >> name >> accNumber) {
        cAccountsPB.push_back(AccountV2(name, accNumber));
    }
    acctFile.close();

    for (size_t i = 0; i < cAccountsPB.size(); ++i) {
        cout << cAccountsPB[i] << "\n";
    }
    
    cout << "\nTask2e:\n"
         << "Filling vector of class objects, using emplace_back:\n";
    
    vector<AccountV2> cAccountsEB;
    acctFile.clear();
    acctFile.open("accounts.txt");
    while (acctFile >> name >> accNumber) {
        cAccountsEB.emplace_back(name, accNumber);
    }
    acctFile.close();

    for (size_t i = 0; i < cAccountsEB.size(); ++i) {
        cout << cAccountsEB[i] << "\n";
    }

    cout << "==============\n"
         << "\nTask 3:\nAccounts and Transaction:\n";
    
    {
        vector<AccountV3> accsHistory;

        ifstream tranFile;
        string action;
        tranFile.open("transactions.txt");
        while (tranFile >> action) {
            if (action == "Account") {
                tranFile >> name >> accNumber; 
                accsHistory.push_back(AccountV3(name, accNumber));
            } else if (action == "Deposit") {          
                int amount;
                tranFile >> accNumber >> amount;
                int found = 1;
                for (size_t i = 0; i < accsHistory.size(); ++i) {
                    if (accsHistory[i].getAccountNumber() == accNumber) {
                        accsHistory[i].deposit(amount);   
                        found = 0;
                        break;
                    }
                }
                if (found == 1) {
                    cout << "No account found." << "\n";
                }
            } else if (action == "Withdraw") {        
                int amount;
                tranFile >> accNumber >> amount;
                int found = 1;
                for (size_t i = 0; i < accsHistory.size(); ++i) {
                    if (accsHistory[i].getAccountNumber() == accNumber) {
                        accsHistory[i].withdrawal(amount);
                        found = 0;
                        break;
                    }
                }
                if (found == 1) {
                    cout << "No account found." << "\n";
                }
            }
        }
        tranFile.close();

        for (size_t i = 0; i < accsHistory.size(); ++i) {
            cout << accsHistory[i];
        }
    }
    cout << "==============\n"
         << "\nTask 4:\nTransaction nested in public section of Account:\n";
    
    {     
        vector<AccountV4> accsHistory;

        ifstream tranFile;
        string action;
        tranFile.open("transactions.txt");
        while (tranFile >> action) {
            if (action == "Account") {
                tranFile >> name >> accNumber; 
                accsHistory.push_back(AccountV4(name, accNumber));
            } else if (action == "Deposit") {          
                int amount;
                tranFile >> accNumber >> amount;
                int found = 1;
                for (size_t i = 0; i < accsHistory.size(); ++i) {
                    if (accsHistory[i].getAccountNumber() == accNumber) {
                        accsHistory[i].deposit(amount);   
                        found = 0;
                        break;
                    }
                }
                if (found == 1) {
                    cout << "No account found." << '\n';
                }
            } else if (action == "Withdraw") {        
                int amount;
                tranFile >> accNumber >> amount;
                int found = 1;
                for (size_t i = 0; i < accsHistory.size(); ++i) {
                    if (accsHistory[i].getAccountNumber() == accNumber) {
                        accsHistory[i].withdrawal(amount);
                        found = 0;
                        break;
                    }
                }
                if (found == 1) {
                    cout << "No account found." << "\n";
                }
            }
        }
        tranFile.close();
        
        for (size_t i = 0; i < accsHistory.size(); ++i) {
            cout << accsHistory[i];
        }
    }

    cout << "==============\n"
         << "\nTask 5:\nTransaction nested in private section of Account:\n";
} // main
