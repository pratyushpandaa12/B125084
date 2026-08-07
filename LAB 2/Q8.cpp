#include <iostream>
#include <string>
using namespace std;

class HostelFee
{
    string studentName;
    int hostelID;
    float monthlyFee;
    int months;
    float totalFee;
    char delayed;
public:
    void accept()
    {
        cout << "Enter Student Name: ";
        cin >> studentName;

        cout << "Enter Hostel ID: ";
        cin >> hostelID;

        cout << "Enter Monthly Fee: ";
        cin >> monthlyFee;

        cout << "Enter Number of Months: ";
        cin >> months;

        cout << "Is Payment Delayed? (Y/N/yes/Yes): ";
        cin >> delayed;
    }

    void calculateFee()
    {
        totalFee = monthlyFee * months;

        if (delayed == 'Y' || delayed == 'y'|| delayed == 'Yes' || delayed == 'yes')
        {
            totalFee += 500;
        }
    }

    void display()
    {
        cout << "\n----- Hostel Fee Details -----" << endl;
        cout << "Student Name : " << studentName << endl;
        cout << "Hostel ID    : " << hostelID << endl;
        cout << "Monthly Fee  : " << monthlyFee << endl;
        cout << "Months       : " << months << endl;

        if (delayed == 'Y' || delayed == 'y')
            cout << "Late Fine    : 500" << endl;
        else
            cout << "Late Fine    : 0" << endl;

        cout << "Total Amount : " << totalFee << endl;
    }
};

int main()
{
    HostelFee h;

    h.accept();
    h.calculateFee();
    h.display();

    return 0;
}