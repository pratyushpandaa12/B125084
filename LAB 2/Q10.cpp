#include <iostream>
#include <string>
using namespace std;

class WaterBill
{
    int consumerNumber;
    string consumerName;
    int waterConsumption;
    float billAmount;

public:
    void accept()
    {
        cout << "Enter Consumer Number: ";
        cin >> consumerNumber;

        cout << "Enter Consumer Name: ";
        cin >> consumerName;

        cout << "Enter Water Consumption (litres): ";
        cin >> waterConsumption;
    }

    void calculateBill()
    {
        if (waterConsumption <= 500)
        {
            billAmount = waterConsumption * 2;
        }
        else if (waterConsumption <= 1000)
        {
            billAmount = (500 * 2) + (waterConsumption - 500) * 3;
        }
        else
        {
            billAmount = (500 * 2) + (500 * 3) + (waterConsumption - 1000) * 5;
        }
    }

    void display()
    {
        cout << "\n----- Water Bill -----" << endl;
        cout << "Consumer Number    : " << consumerNumber << endl;
        cout << "Consumer Name      : " << consumerName << endl;
        cout << "Water Consumption  : " << waterConsumption << " litres" << endl;
        cout << "Bill Amount        : Rs. " << billAmount << endl;
    }
};

int main()
{
    WaterBill w;

    w.accept();
    w.calculateBill();
    w.display();

    return 0;
}