// 4. Hybrid Inheritance Problem:

//    Consider you're developing software for a banking system. Design a class hierarchy for different types of bank accounts. Create a base class `Account` with properties like `accountNumber` and `balance`. Derive classes `SavingsAccount` and `CurrentAccount` from `Account`, representing different types of accounts. Further, derive a class `JointAccount` from both `SavingsAccount` and `CurrentAccount`, representing joint accounts with shared ownership. Implement member functions to deposit and withdraw money from the accounts, ensuring proper handling of joint account operations. Test your code with various account operations.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << endl;
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }
};

class SavingsAccount : virtual public Account {
public:
    SavingsAccount(string accNum, double bal) : Account(accNum, bal) {}
};

class CurrentAccount : virtual public Account {
public:
    CurrentAccount(string accNum, double bal) : Account(accNum, bal) {}
};

class JointAccount : public SavingsAccount, public CurrentAccount {
public:
    JointAccount(string accNum, double bal) : Account(accNum, bal), SavingsAccount(accNum, bal), CurrentAccount(accNum, bal) {}
    void deposit(double amount) override {
        SavingsAccount::deposit(amount);
        CurrentAccount::deposit(amount);
        cout << "Deposited $" << amount << " into joint account " << accountNumber << endl;
    }
    void withdraw(double amount) override {
        SavingsAccount::withdraw(amount);
        CurrentAccount::withdraw(amount);
    }
};

int main() {
    vector<Account*> accounts;
    Account* savingsAccount = new SavingsAccount("SA001", 1000);
    Account* currentAccount = new CurrentAccount("CA001", 2000);
    Account* jointAccount = new JointAccount("JA001", 3000); // Constructor invocation fixed
    accounts.push_back(savingsAccount);
    accounts.push_back(currentAccount);
    accounts.push_back(jointAccount);
    for (auto account : accounts) {
        account->deposit(500);
        account->withdraw(200);
        cout << "Account Balance for " << account->accountNumber << ": $" << account->balance << endl;
        cout << endl;
    }
    for (auto account : accounts) {
        delete account;
    }

    return 0;
}