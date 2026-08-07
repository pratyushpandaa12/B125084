#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{
    string playerName;
    int matchesPlayed;
    int totalRuns;
    float battingAverage;
    string performance;

public:
    void accept()
    {
        cout << "Enter Player Name: ";
        cin >> playerName;

        cout << "Enter Matches Played: ";
        cin >> matchesPlayed;

        cout << "Enter Total Runs Scored: ";
        cin >> totalRuns;
    }

    void calculateAverage()
    {
        battingAverage = (float)totalRuns / matchesPlayed;

        if (battingAverage >= 50)
            performance = "Excellent";
        else if (battingAverage >= 35)
            performance = "Good";
        else if (battingAverage >= 20)
            performance = "Average";
        else
            performance = "Poor";
    }

    void display()
    {
        cout << "\n----- Player Report -----" << endl;
        cout << "Player Name      : " << playerName << endl;
        cout << "Matches Played   : " << matchesPlayed << endl;
        cout << "Total Runs       : " << totalRuns << endl;
        cout << "Batting Average  : " << battingAverage << endl;
        cout << "Performance      : " << performance << endl;
    }
};

int main()
{
    CricketPlayer p;

    p.accept();
    p.calculateAverage();
    p.display();

    return 0;
}