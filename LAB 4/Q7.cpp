#include <iostream>
using namespace std;

class MuseumManager;

class Exhibit
{
private:
    string exhibitName;
    int exhibitID;
    int visitorCount;
    bool displayStatus;

public:
    void getData()
    {
        cout << "Enter Exhibit Name: ";
        getline(cin, exhibitName);

        cout << "Enter Exhibit ID: ";
        cin >> exhibitID;

        cout << "Enter Visitor Count: ";
        cin >> visitorCount;

        int status;
        cout << "Enter Display Status (1 = Open, 0 = Closed): ";
        cin >> status;

        displayStatus = status;
    }

    friend class MuseumManager;
};

class MuseumManager
{
public:
    void displayInfo(Exhibit &e)
    {
        cout << "\n----- Exhibit Information -----" << endl;
        cout << "Exhibit Name: " << e.exhibitName << endl;
        cout << "Exhibit ID: " << e.exhibitID << endl;
        cout << "Visitor Count: " << e.visitorCount << endl;
        cout << "Display Status: "
             << (e.displayStatus ? "Open" : "Closed") << endl;
    }

    void addVisitors(Exhibit &e)
    {
        int visitors;

        cout << "Enter number of visitors to add: ";
        cin >> visitors;

        e.visitorCount += visitors;

        cout << "Visitors added successfully." << endl;
    }

    void resetVisitorCount(Exhibit &e)
    {
        e.visitorCount = 0;
        cout << "Visitor count reset successfully." << endl;
    }

    void openExhibit(Exhibit &e)
    {
        e.displayStatus = true;
        cout << "Exhibit opened." << endl;
    }

    void closeExhibit(Exhibit &e)
    {
        e.displayStatus = false;
        cout << "Exhibit closed." << endl;
    }

    void checkStatus(Exhibit &e)
    {
        cout << "Exhibit is currently "
             << (e.displayStatus ? "OPEN." : "CLOSED.") << endl;
    }
};

int main()
{
    Exhibit e;
    MuseumManager manager;

    e.getData();

    manager.displayInfo(e);

    cout << "\n--- Museum Operations ---" << endl;

    manager.openExhibit(e);
   
    manager.checkStatus(e);
    manager.addVisitors(e);
    cout << endl;

    manager.displayInfo(e);
    manager.closeExhibit(e);


    return 0;
}