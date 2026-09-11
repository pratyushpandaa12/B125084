#include <iostream>
using namespace std;

class ParkingFloor {
private:
    int floorNo;
    int slots;
    bool *occupied;

public:
    ParkingFloor(int f, int n) {
        floorNo = f;
        slots = n;
        occupied = new bool[slots];

        for (int i = 0; i < slots; i++)
            occupied[i] = false;
    }

    // Reserve one particular slot
    void reserve(int position) {
        if (position < 1 || position > slots) {
            cout << "Invalid slot number!\n";
            return;
        }

        if (occupied[position - 1]) {
            cout << "Slot " << position << " is already occupied.\n";
        } else {
            occupied[position - 1] = true;
            cout << "Slot " << position << " reserved successfully.\n";
        }
    }

    // Reserve consecutive slots
    void reserve(int start, int count) {
        if (start < 1 || start + count - 1 > slots || count <= 0) {
            cout << "Invalid slot range!\n";
            return;
        }

        // Check availability first
        for (int i = start - 1; i < start - 1 + count; i++) {
            if (occupied[i]) {
                cout << "Some slots in the requested range are already occupied.\n";
                return;
            }
        }

        for (int i = start - 1; i < start - 1 + count; i++)
            occupied[i] = true;

        cout << count << " consecutive slots reserved successfully.\n";
    }

    void display() {
        cout << "\nFloor " << floorNo << ":\n";

        for (int i = 0; i < slots; i++) {
            cout << "Slot " << i + 1 << ": "
                 << (occupied[i] ? "Occupied" : "Free") << endl;
        }
    }

    ~ParkingFloor() {
        delete[] occupied;
    }
};

int main() {
    int floors;

    cout << "Enter number of floors: ";
    cin >> floors;

    ParkingFloor **building = new ParkingFloor*[floors];

    for (int i = 0; i < floors; i++) {
        int floorNo, slots;

        cout << "\nEnter floor number: ";
        cin >> floorNo;

        cout << "Enter number of slots: ";
        cin >> slots;

        building[i] = new ParkingFloor(floorNo, slots);

        int choice;

        cout << "\n1. Reserve single slot\n";
        cout << "2. Reserve consecutive slots\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int position;
            cout << "Enter slot number: ";
            cin >> position;

            building[i]->reserve(position);
        }
        else if (choice == 2) {
            int start, count;

            cout << "Enter starting slot: ";
            cin >> start;

            cout << "Enter number of consecutive slots: ";
            cin >> count;

            building[i]->reserve(start, count);
        }
        else {
            cout << "Invalid choice!\n";
        }

        building[i]->display();
    }

    // Release all dynamically allocated floors
    for (int i = 0; i < floors; i++)
        delete building[i];

    delete[] building;

    return 0;
}