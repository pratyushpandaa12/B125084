#include <iostream>
using namespace std;

class WalletManager;

class DigitalWallet
{
private:
    string userName;
    double walletBalance;
    string walletStatus;

public:
    DigitalWallet(string name, double balance, string status)
    {
        userName = name;
        walletBalance = balance;
        walletStatus = status;
    }

    friend class WalletManager;
};

class WalletManager
{
public:
    void displayDetails(DigitalWallet &w)
    {
        cout << "----- Digital Wallet Details -----" << endl;
        cout << "User Name: " << w.userName << endl;
        cout << "Wallet Balance: Rs. " << w.walletBalance << endl;
        cout << "Wallet Status: " << w.walletStatus << endl;
    }

    void addMoney(DigitalWallet &w, double amount)
    {
        if (w.walletStatus == "Active")
        {
            w.walletBalance += amount;
            cout << "Rs. " << amount << " added successfully." << endl;
        }
        else
        {
            cout << "Wallet is disabled. Cannot add money." << endl;
        }
    }

    void deductMoney(DigitalWallet &w, double amount)
    {
        if (w.walletStatus != "Active")
        {
            cout << "Wallet is disabled. Transaction not allowed." << endl;
        }
        else if (amount <= w.walletBalance)
        {
            w.walletBalance -= amount;
            cout << "Rs. " << amount << " deducted successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    void disableWallet(DigitalWallet &w)
    {
        w.walletStatus = "Disabled";
        cout << "Wallet has been disabled." << endl;
    }

    void displayStatus(DigitalWallet &w)
    {
        cout << "Current Wallet Status: "
             << w.walletStatus << endl;
    }
};

int main()
{
    DigitalWallet wallet("Pratyush", 5000, "Active");
    WalletManager manager;

    manager.displayDetails(wallet);

    cout << endl;

    manager.addMoney(wallet, 2000);
    manager.deductMoney(wallet, 1500);

    cout << endl;

    manager.displayDetails(wallet);

    cout << endl;

    manager.disableWallet(wallet);
    manager.displayStatus(wallet);

    cout << endl;

    manager.deductMoney(wallet, 500);

    return 0;
}