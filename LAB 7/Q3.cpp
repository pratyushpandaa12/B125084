
#include <iostream>
using namespace std;

class Candidate {
protected:
    int id;
    double attendance;

public:
    Candidate(int i, double a) {
        id = i;
        attendance = a;
    }
};

class RegularCandidate : public Candidate {
public:
    RegularCandidate(int i, double a) : Candidate(i, a) {}

    void checkEligibility() {
        cout << "\nRegular Candidate ID: " << id << endl;
        cout << "Attendance: " << attendance << "%\n";

        if (attendance >= 75)
            cout << "Eligible for examination\n";
        else
            cout << "Not eligible for examination\n";
    }
};

class ReappearCandidate : public Candidate {
public:
    ReappearCandidate(int i, double a) : Candidate(i, a) {}

    void checkEligibility() {
        cout << "\nReappear Candidate ID: " << id << endl;
        cout << "Attendance: " << attendance << "%\n";

        if (attendance >= 60)
            cout << "Eligible for examination\n";
        else
            cout << "Not eligible for examination\n";
    }
};

int main() {
    int id1, id2;
    double a1, a2;

    cout << "Enter Regular Candidate ID: ";
    cin >> id1;
    cout << "Enter attendance: ";
    cin >> a1;

    cout << "\nEnter Reappear Candidate ID: ";
    cin >> id2;
    cout << "Enter attendance: ";
    cin >> a2;

    RegularCandidate r(id1, a1);
    ReappearCandidate p(id2, a2);

    r.checkEligibility();
    p.checkEligibility();

    return 0;
}
