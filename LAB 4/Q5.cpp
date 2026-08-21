#include <iostream>
using namespace std;

class EventParticipant
{
private:
    string participantName;
    int age;
    string registrationStatus;

public:
    void getData()
    {
        cout << "Enter Participant Name: ";
        getline(cin, participantName);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Registration Status: ";
        getline(cin, registrationStatus);
    }

    friend void verifyParticipant(EventParticipant p);
};

void verifyParticipant(EventParticipant p)
{
    cout << "\n----- Event Registration Details -----" << endl;
    cout << "Participant Name: " << p.participantName << endl;
    cout << "Age: " << p.age << endl;
    cout << "Registration Status: " << p.registrationStatus << endl;

    if (p.age >= 18 && p.registrationStatus == "Active")
        cout << "Result: Eligible" << endl;
    else
        cout << "Result: Not Eligible" << endl;
}

int main()
{
    EventParticipant p;

    p.getData();
    verifyParticipant(p);

    return 0;
}