
#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string name;
    double distance;

public:
    Ticket(string n, double d) {
        name = n;
        distance = d;
    }
};

class RailwayTicket : public Ticket {
private:
    double farePerKm;

public:
    RailwayTicket(string n, double d, double rate)
        : Ticket(n, d) {
        farePerKm = rate;
    }

    void display() {
        double fare = distance * farePerKm;

        if (distance > 300) {
            fare = fare - (fare * 0.10);
        }

        cout << "\n--- Railway Ticket Details ---\n";
        cout << "Passenger Name: " << name << endl;
        cout << "Distance: " << distance << " km\n";
        cout << "Fare per km: Rs. " << farePerKm << endl;
        cout << "Final Fare: Rs. " << fare << endl;
    }
};

int main() {
    string name;
    double distance, rate;

    cout << "Enter passenger name: ";
    getline(cin, name);

    cout << "Enter distance travelled: ";
    cin >> distance;

    cout << "Enter fare per km: ";
    cin >> rate;

    RailwayTicket r(name, distance, rate);
    r.display();

    return 0;
}
