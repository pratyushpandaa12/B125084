#include <iostream>
using namespace std;

class Trip {
private:
    int tripID;
    double distance;
    double baseFare;

    double finalFare;

public:
    Trip(int id, double d, double base) {
        tripID = id;
        distance = d;
        baseFare = base;
        finalFare = 0;
    }

    // Normal fare
    void fare(double ratePerKm) {
        finalFare = baseFare + (distance * ratePerKm);
    }

    // Fare with waiting time
    void fare(double ratePerKm, int waitingTime, double waitingRate) {
        finalFare = baseFare +
                    (distance * ratePerKm) +
                    (waitingTime * waitingRate);
    }

    // Fare with waiting time and discount
    void fare(double ratePerKm, int waitingTime,
              double waitingRate, int discount) {

        finalFare = baseFare +
                    (distance * ratePerKm) +
                    (waitingTime * waitingRate);

        finalFare = finalFare -
                    (finalFare * discount / 100.0);
    }

    void display() {
        cout << "Trip ID: " << tripID << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Base Fare: " << baseFare << endl;
        cout << "Final Fare: " << finalFare << endl;
    }

    friend void compareFare(const Trip &, const Trip &);
};

void compareFare(const Trip &t1, const Trip &t2) {
    cout << "\n--- Fare Comparison ---\n";

    if (t1.finalFare < t2.finalFare) {
        cout << "Trip " << t1.tripID
             << " is cheaper.\n";
        cout << "Fare: " << t1.finalFare << endl;
    }
    else if (t2.finalFare < t1.finalFare) {
        cout << "Trip " << t2.tripID
             << " is cheaper.\n";
        cout << "Fare: " << t2.finalFare << endl;
    }
    else {
        cout << "Both trips have the same fare: "
             << t1.finalFare << endl;
    }
}

int main() {
    int id1, id2;
    double distance1, distance2;
    double base1, base2;

    cout << "Enter Trip 1 ID: ";
    cin >> id1;

    cout << "Enter Trip 1 distance: ";
    cin >> distance1;

    cout << "Enter Trip 1 base fare: ";
    cin >> base1;

    cout << "\nEnter Trip 2 ID: ";
    cin >> id2;

    cout << "Enter Trip 2 distance: ";
    cin >> distance2;

    cout << "Enter Trip 2 base fare: ";
    cin >> base2;

    // Dynamic trip objects
    Trip *trip1 = new Trip(id1, distance1, base1);
    Trip *trip2 = new Trip(id2, distance2, base2);

    double ratePerKm;

    cout << "\nEnter fare rate per km: ";
    cin >> ratePerKm;

    cout << "\nChoose fare calculation for Trip 1:\n";
    cout << "1. Normal fare\n";
    cout << "2. Fare with waiting charge\n";
    cout << "3. Fare with waiting charge and discount\n";

    int choice1;
    cin >> choice1;

    if (choice1 == 1) {

        trip1->fare(ratePerKm);

    }
    else if (choice1 == 2) {

        int waitingTime;
        double waitingRate;

        cout << "Enter waiting time: ";
        cin >> waitingTime;

        cout << "Enter waiting charge per minute: ";
        cin >> waitingRate;

        trip1->fare(ratePerKm, waitingTime, waitingRate);

    }
    else if (choice1 == 3) {

        int waitingTime;
        double waitingRate;
        int discount;

        cout << "Enter waiting time: ";
        cin >> waitingTime;

        cout << "Enter waiting charge per minute: ";
        cin >> waitingRate;

        cout << "Enter discount percentage: ";
        cin >> discount;

        trip1->fare(ratePerKm, waitingTime,
                    waitingRate, discount);

    }
    else {
        cout << "Invalid choice!\n";
        delete trip1;
        delete trip2;
        return 0;
    }

    cout << "\nChoose fare calculation for Trip 2:\n";
    cout << "1. Normal fare\n";
    cout << "2. Fare with waiting charge\n";
    cout << "3. Fare with waiting charge and discount\n";

    int choice2;
    cin >> choice2;

    if (choice2 == 1) {

        trip2->fare(ratePerKm);

    }
    else if (choice2 == 2) {

        int waitingTime;
        double waitingRate;

        cout << "Enter waiting time: ";
        cin >> waitingTime;

        cout << "Enter waiting charge per minute: ";
        cin >> waitingRate;

        trip2->fare(ratePerKm, waitingTime, waitingRate);

    }
    else if (choice2 == 3) {

        int waitingTime;
        double waitingRate;
        int discount;

        cout << "Enter waiting time: ";
        cin >> waitingTime;

        cout << "Enter waiting charge per minute: ";
        cin >> waitingRate;

        cout << "Enter discount percentage: ";
        cin >> discount;

        trip2->fare(ratePerKm, waitingTime,
                    waitingRate, discount);

    }
    else {
        cout << "Invalid choice!\n";
        delete trip1;
        delete trip2;
        return 0;
    }

    cout << "\n--- Trip 1 ---\n";
    trip1->display();

    cout << "\n--- Trip 2 ---\n";
    trip2->display();

    compareFare(*trip1, *trip2);

    // Release dynamic memory
    delete trip1;
    delete trip2;

    return 0;
}