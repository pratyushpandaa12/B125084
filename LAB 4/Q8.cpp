#include <iostream>
using namespace std;

class ServiceManager;

class VehicleService
{
private:
    string vehicleNumber;
    string ownerName;
    string serviceDueStatus;
    int lastServiceKilometres;

public:
    void getData()
    {
        cout << "Enter Vehicle Number: ";
        getline(cin, vehicleNumber);

        cout << "Enter Owner Name: ";
        getline(cin, ownerName);

        cout << "Enter Service Due Status (Due/Not Due): ";
        getline(cin, serviceDueStatus);

        cout << "Enter Last Service Kilometres: ";
        cin >> lastServiceKilometres;
    }

    friend class ServiceManager;
};

class ServiceManager
{
public:
    void displayInfo(VehicleService &v)
    {
        cout << "\n----- Vehicle Service Information -----" << endl;
        cout << "Vehicle Number: " << v.vehicleNumber << endl;
        cout << "Owner Name: " << v.ownerName << endl;
        cout << "Service Due Status: " << v.serviceDueStatus << endl;
        cout << "Last Service Kilometres: "
             << v.lastServiceKilometres << " km" << endl;
    }

    void markServiceCompleted(VehicleService &v)
    {
        v.serviceDueStatus = "Not Due";
        cout << "Service marked as completed." << endl;
    }

    void updateLastServiceKilometres(VehicleService &v)
    {
        int km;

        cout << "Enter new last service kilometres: ";
        cin >> km;

        v.lastServiceKilometres = km;

        cout << "Last service kilometres updated." << endl;
    }

    void checkService(VehicleService &v)
    {
        if (v.serviceDueStatus == "Due")
            cout << "Vehicle requires servicing." << endl;
        else
            cout << "Vehicle does not require servicing." << endl;
    }
};

int main()
{
    VehicleService v;
    ServiceManager manager;

    v.getData();

    manager.displayInfo(v);

    cout << endl;

    manager.checkService(v);

    cout << endl;

    manager.markServiceCompleted(v);
    manager.updateLastServiceKilometres(v);

    cout << endl;

    manager.displayInfo(v);

    return 0;
}