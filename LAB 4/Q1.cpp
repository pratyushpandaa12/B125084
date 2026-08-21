#include <iostream>
using namespace std;

class Weather
{
private:
    string cityName;
    float temperature;
    string weatherCondition;

public:
    void getData()
    {
        cout << "Enter City Name: ";
        getline(cin, cityName);

        cout << "Enter Temperature (in C): ";
        cin >> temperature;
        cin.ignore();

        cout << "Enter Weather Condition: ";
        getline(cin, weatherCondition);
    }

    friend void generateReport(Weather w);
};

void generateReport(Weather w)
{
    cout << "\n----- Weather Report -----" << endl;
    cout << "City: " << w.cityName << endl;
    cout << "Temperature: " << w.temperature << " C" << endl;
    cout << "Weather Condition: " << w.weatherCondition << endl;

    if (w.temperature > 35)
        cout << "Category: Very Hot" << endl;
    else if (w.temperature >= 20 && w.temperature <= 35)
        cout << "Category: Pleasant" << endl;
    else
        cout << "Category: Cool" << endl;
}

int main()
{
    Weather w;

    w.getData();
    generateReport(w);

    return 0;
}