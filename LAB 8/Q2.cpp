
#include <iostream>
using namespace std;

class ElectricityPlan {
public:
    virtual double calculateBill(double units) {
        return 0;
    }

    virtual ~ElectricityPlan() {}
};

class ResidentialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override {
        if (units <= 100)
            return units * 4;

        return 400 + (units - 100) * 6;
    }
};

class CommercialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override {
        return units * 7;
    }
};

int main() {
    double units;

    cout << "Enter electricity units consumed: ";
    cin >> units;

    ResidentialPlan r;
    CommercialPlan c;

    ElectricityPlan *ptr;

    ptr = &r;
    cout << "Residential Bill: Rs. "
         << ptr->calculateBill(units) << endl;

    ptr = &c;
    cout << "Commercial Bill: Rs. "
         << ptr->calculateBill(units) << endl;

    return 0;
}
