
#include <iostream>
using namespace std;

class Scholarship {
public:
    virtual double calculateAward(double marks,
                                  double familyIncome) {
        return 0;
    }

    virtual ~Scholarship() {}
};

class MeritScholarship : public Scholarship {
public:
    double calculateAward(double marks,
                          double familyIncome) override {

        if (marks >= 90)
            return 20000;
        else if (marks >= 80)
            return 10000;
        else
            return 0;
    }
};

class NeedBasedScholarship : public Scholarship {
public:
    double calculateAward(double marks,
                          double familyIncome) override {

        if (familyIncome < 200000 && marks >= 70)
            return 25000;
        else
            return 0;
    }
};

int main() {
    double marks, income;

    cout << "Enter student's marks: ";
    cin >> marks;

    cout << "Enter family income (Rs.): ";
    cin >> income;

    MeritScholarship m;
    NeedBasedScholarship n;

    Scholarship *ptr;

    ptr = &m;
    cout << "\nMerit Scholarship Award: Rs. "
         << ptr->calculateAward(marks, income)
         << endl;

    ptr = &n;
    cout << "Need-Based Scholarship Award: Rs. "
         << ptr->calculateAward(marks, income)
         << endl;

    return 0;
}
