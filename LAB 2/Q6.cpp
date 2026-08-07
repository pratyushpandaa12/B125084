/**/
#include <iostream>
using namespace std;

class Time
{
    int h1, m1, h2, m2;
    int totalHours, totalMinutes;

public:
    void accept()
    {
        cout << "Enter First Time (Hours Minutes): ";
        cin >> h1 >> m1;

        cout << "Enter Second Time (Hours Minutes): ";
        cin >> h2 >> m2;
    }

    void addTime()
    {
        totalHours = h1 + h2;
        totalMinutes = m1 + m2;

        if (totalMinutes >= 60)
        {
            totalHours += totalMinutes / 60;
            totalMinutes = totalMinutes % 60;
        }
    }

    void display()
    {
        cout << "\n----- Result -----" << endl;
        cout << "Total Time = " << totalHours << " hr "
             << totalMinutes << " min" << endl;
    }
};

int main()
{
    Time t;

    t.accept();
    t.addTime();
    t.display();

    return 0;
}