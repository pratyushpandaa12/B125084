#include <iostream>
using namespace std;

class SensorGrid {
private:
    int n;
    double *temperature;

public:
    SensorGrid(int size) {
        n = size;
        temperature = new double[n];
    }

    void enterReadings() {
        cout << "Enter " << n << " temperature readings:\n";

        for (int i = 0; i < n; i++) {
            cout << "Reading " << i + 1 << ": ";
            cin >> temperature[i];
        }
    }

    void displayReadings() {
        cout << "\nTemperature Readings:\n";

        for (int i = 0; i < n; i++) {
            cout << "Sensor " << i + 1
                 << ": " << temperature[i] << endl;
        }
    }

    void replaceReading(int position, double newTemperature) {
        if (position < 1 || position > n) {
            cout << "Invalid sensor position!\n";
            return;
        }

        temperature[position - 1] = newTemperature;

        cout << "Reading replaced successfully.\n";
    }

    friend void compareAverage(const SensorGrid &, const SensorGrid &);

    ~SensorGrid() {
        delete[] temperature;
    }
};

void compareAverage(const SensorGrid &g1, const SensorGrid &g2) {
    double sum1 = 0, sum2 = 0;

    for (int i = 0; i < g1.n; i++)
        sum1 += g1.temperature[i];

    for (int i = 0; i < g2.n; i++)
        sum2 += g2.temperature[i];

    double avg1 = sum1 / g1.n;
    double avg2 = sum2 / g2.n;

    cout << "\n--- Average Temperature ---\n";

    cout << "Grid 1 Average: " << avg1 << endl;
    cout << "Grid 2 Average: " << avg2 << endl;

    if (avg1 > avg2)
        cout << "Grid 1 has the greater average temperature.\n";
    else if (avg2 > avg1)
        cout << "Grid 2 has the greater average temperature.\n";
    else
        cout << "Both grids have the same average temperature.\n";
}

int main() {
    int n1, n2;

    cout << "Enter number of sensors in Grid 1: ";
    cin >> n1;

    SensorGrid grid1(n1);
    grid1.enterReadings();

    cout << "\nEnter number of sensors in Grid 2: ";
    cin >> n2;

    SensorGrid grid2(n2);
    grid2.enterReadings();

    cout << "\n--- Grid 1 ---\n";
    grid1.displayReadings();

    cout << "\n--- Grid 2 ---\n";
    grid2.displayReadings();

    int position;
    double newTemperature;

    cout << "\nEnter grid number to replace reading (1/2): ";
    int choice;
    cin >> choice;

    cout << "Enter sensor position: ";
    cin >> position;

    cout << "Enter new temperature: ";
    cin >> newTemperature;

    if (choice == 1)
        grid1.replaceReading(position, newTemperature);
    else if (choice == 2)
        grid2.replaceReading(position, newTemperature);
    else
        cout << "Invalid grid choice!\n";

    cout << "\n--- Updated Readings ---\n";

    cout << "\nGrid 1:";
    grid1.displayReadings();

    cout << "\nGrid 2:";
    grid2.displayReadings();

    compareAverage(grid1, grid2);

    return 0;
}