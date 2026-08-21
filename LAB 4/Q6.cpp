#include <iostream>
using namespace std;

class PrinterManager;

class Printer
{
private:
    string printerName;
    int pagesPrinted;
    int inkLevel;
    bool powerStatus;

public:
    void getData()
    {
        cout << "Enter Printer Name: ";
        getline(cin, printerName);

        cout << "Enter Number of Pages Printed: ";
        cin >> pagesPrinted;

        cout << "Enter Ink Level (%): ";
        cin >> inkLevel;

        int power;
        cout << "Enter Power Status (1 = ON, 0 = OFF): ";
        cin >> power;

        powerStatus = power;
    }

    friend class PrinterManager;
};

class PrinterManager
{
public:
    void displayInfo(Printer &p)
    {
        cout << "\n----- Printer Information -----" << endl;
        cout << "Printer Name: " << p.printerName << endl;
        cout << "Pages Printed: " << p.pagesPrinted << endl;
        cout << "Ink Level: " << p.inkLevel << "%" << endl;

        cout << "Power Status: "
             << (p.powerStatus ? "ON" : "OFF") << endl;
    }

    void turnOn(Printer &p)
    {
        p.powerStatus = true;
        cout << "Printer turned ON." << endl;
    }

    void turnOff(Printer &p)
    {
        p.powerStatus = false;
        cout << "Printer turned OFF." << endl;
    }

    void checkInkLevel(Printer &p)
    {
        cout << "Current Ink Level: "
             << p.inkLevel << "%" << endl;
    }

    void resetPageCount(Printer &p)
    {
        p.pagesPrinted = 0;
        cout << "Page count reset successfully." << endl;
    }
};

int main()
{
    Printer p;
    PrinterManager manager;

    p.getData();

    manager.displayInfo(p);

    cout << "\n--- Printer Operations ---" << endl;

    manager.turnOn(p);
    manager.checkInkLevel(p);
    manager.resetPageCount(p);
    manager.displayInfo(p);
    manager.turnOff(p);

    return 0;
}