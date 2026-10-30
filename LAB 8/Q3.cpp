
#include <iostream>
using namespace std;

class TrafficSignal {
public:
    virtual int getGreenDuration(int vehicleCount) {
        return 0;
    }

    virtual ~TrafficSignal() {}
};

class UrbanSignal : public TrafficSignal {
public:
    int getGreenDuration(int vehicleCount) override {
        int duration = 10 + 2 * vehicleCount;

        if (duration > 60)
            duration = 60;

        return duration;
    }
};

class HighwaySignal : public TrafficSignal {
public:
    int getGreenDuration(int vehicleCount) override {
        int duration = 15 + 3 * vehicleCount;

        if (duration > 90)
            duration = 90;

        return duration;
    }
};

int main() {
    int vehicles;

    cout << "Enter number of vehicles: ";
    cin >> vehicles;

    UrbanSignal u;
    HighwaySignal h;

    TrafficSignal *ptr;

    ptr = &u;
    cout << "Urban Green Duration: "
         << ptr->getGreenDuration(vehicles)
         << " seconds\n";

    ptr = &h;
    cout << "Highway Green Duration: "
         << ptr->getGreenDuration(vehicles)
         << " seconds\n";

    return 0;
}
