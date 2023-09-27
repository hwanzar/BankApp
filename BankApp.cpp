#include <iostream>
#include <string>

using namespace std; // Include the standard namespace

class BankAccount
{
private:
    string account_number;
    string account_holder_name;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(const string &acc_number, const string &acc_holder_name, double initial_balance)
    {
        account_number = acc_number;
        account_holder_name = acc_holder_name;
        balance = initial_balance;
    }

    // Method to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Please enter a positive amount." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
        else if (amount <= 0)
        {
            cout << "Invalid withdrawal amount. Please enter a positive amount." << endl;
        }
        else
        {
            cout << "Insufficient balance for withdrawal." << endl;
        }
    }

    // Method to check balance
    void check_balance()
    {
        cout << "Account Balance for " << account_holder_name << ": $" << balance << endl;
    }
};

int main()
{
    string account_number, account_holder_name;
    double initial_balance;

    // Prompt the user to enter account details
    cout << "Enter account number: ";
    cin >> account_number;
    cout << "Enter account holder name: ";
    cin >> account_holder_name;
    cout << "Enter initial balance: ";
    cin >> initial_balance;

    // Create a BankAccount object
    BankAccount account(account_number, account_holder_name, initial_balance);

    int choice;
    double amount;

    while (true)
    {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.check_balance();
            break;
        case 4:
            cout << "Exiting program. Thank you!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
