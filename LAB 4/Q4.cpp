#include <iostream>
using namespace std;

class ElectricMeter
{
private:
    string meterNumber;
    string consumerName;
    int unitsConsumed;

public:
    void getData()
    {
        cout << "Enter Meter Number: ";
        getline(cin, meterNumber);

        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);

        cout << "Enter Units Consumed: ";
        cin >> unitsConsumed;
    }

    friend void checkUsage(ElectricMeter e);
};

void checkUsage(ElectricMeter e)
{
    cout << "\n----- Electricity Usage Report -----" << endl;
    cout << "Meter Number: " << e.meterNumber << endl;
    cout << "Consumer Name: " << e.consumerName << endl;
    cout << "Units Consumed: " << e.unitsConsumed << endl;

    if (e.unitsConsumed < 100)
        cout << "Usage Category: Low Usage" << endl;
    else if (e.unitsConsumed <= 300)
        cout << "Usage Category: Moderate Usage" << endl;
    else
        cout << "Usage Category: High Usage" << endl;
}

int main()
{
    ElectricMeter e;

    e.getData();
    checkUsage(e);

    return 0;
}