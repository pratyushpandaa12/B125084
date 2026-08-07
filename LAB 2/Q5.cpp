#include <iostream>
#include <string>
using namespace std;

class MobileRecharge
{
private:
    string mobileNumber;
    string customerName;
    float balance;

public:
    void accept()
    {
        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;

        cout << "Enter Customer Name: ";
        cin >> customerName;

        cout << "Enter Current Balance: ";
        cin >> balance;
    }

    void recharge()
    {
        float amount;
        cout << "Enter Recharge Amount: ";
        cin >> amount;

        balance += amount;
    }

    void deductPlan()
    {
        float planCost;
        cout << "Enter Recharge Plan Cost: ";
        cin >> planCost;

        if (planCost <= balance)
        {
            balance -= planCost;
            cout << "Recharge Plan Activated Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void display()
    {
        cout << "\n----- Customer Details -----" << endl;
        cout << "Mobile Number : " << mobileNumber << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Available Balance : " << balance << endl;
    }
};

int main()
{
    MobileRecharge m;

    m.accept();
    m.recharge();
    m.deductPlan();
    m.display();

    return 0;
}