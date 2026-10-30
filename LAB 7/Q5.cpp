
#include <iostream>
using namespace std;

class Sensor {
protected:
    int sensorID;

public:
    Sensor(int id) {
        sensorID = id;
    }
};

class Temperature : virtual public Sensor {
protected:
    double temp;

public:
    Temperature(int id, double t) : Sensor(id) {
        temp = t;
    }
};

class Humidity : virtual public Sensor {
protected:
    double humidity;

public:
    Humidity(int id, double h) : Sensor(id) {
        humidity = h;
    }
};

class FarmMonitor : public Temperature, public Humidity {
public:
    FarmMonitor(int id, double t, double h)
        : Sensor(id),
          Temperature(id, t),
          Humidity(id, h) {}

    void display() {
        cout << "\n--- Farm Monitoring System ---\n";
        cout << "Sensor ID: " << sensorID << endl;
        cout << "Temperature: " << temp << " C\n";
        cout << "Humidity: " << humidity << "%\n";

        if (temp > 35)
            cout << "Warning: High Temperature!\n";

        if (humidity > 80)
            cout << "Warning: High Humidity!\n";

        if (temp <= 35 && humidity <= 80)
            cout << "Farm Conditions Normal\n";
    }
};

int main() {
    int id;
    double temp, humidity;

    cout << "Enter Sensor ID: ";
    cin >> id;

    cout << "Enter Temperature in Celsius: ";
    cin >> temp;

    cout << "Enter Humidity Percentage: ";
    cin >> humidity;

    FarmMonitor f(id, temp, humidity);
    f.display();

    return 0;
}
