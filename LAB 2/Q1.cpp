#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string carNumber;
    string brandName;
    int modelYear;

public:
    void accept()
    {
        cout << "Enter Car Number: ";
        cin >> carNumber;

        cout << "Enter Brand Name: ";
        cin >> brandName;

        cout << "Enter Model Year: ";
        cin >> modelYear;
    }

    void display()
    {
        cout << "\n----- Car Details -----" << endl;
        cout << "Car Number : " << carNumber << endl;
        cout << "Brand Name : " << brandName << endl;
        cout << "Model Year : " << modelYear << endl;
    }
};

int main()
{
    Car c;

    c.accept();
    c.display();

    return 0;
}