#include <iostream>
#include <string>
using namespace std;

class MovieTicket
{
private:
    string movieName;
    float ticketPrice;
    int numberOfTickets;
    float totalCost;

public:
    void accept()
    {
        cout << "Enter Movie Name: ";
        cin >> movieName;

        cout << "Enter Ticket Price: ";
        cin >> ticketPrice;

        cout << "Enter Number of Tickets: ";
        cin >> numberOfTickets;
    }

    void calculateCost()
    {
        totalCost = ticketPrice * numberOfTickets;
    }

    void display()
    {
        cout << "\n----- Booking Summary -----" << endl;
        cout << "Movie Name        : " << movieName << endl;
        cout << "Ticket Price      : " << ticketPrice << endl;
        cout << "Number of Tickets : " << numberOfTickets << endl;
        cout << "Total Cost        : " << totalCost << endl;
    }
};

int main()
{
    MovieTicket m;

    m.accept();
    m.calculateCost();
    m.display();

    return 0;
}