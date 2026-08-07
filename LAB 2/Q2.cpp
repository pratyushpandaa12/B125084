#include <iostream>
using namespace std;

class Square
{
private:
    float side;
    float area;
    float perimeter;

public:
    void readSide()
    {
        cout << "Enter the side of the square: ";
        cin >> side;
    }

    void calculateArea()
    {
        area = side * side;
    }

    void calculatePerimeter()
    {
        perimeter = 4 * side;
    }

    void display()
    {
        cout << "\n----- Square Details -----" << endl;
        cout << "Side       : " << side << endl;
        cout << "Area       : " << area << endl;
        cout << "Perimeter  : " << perimeter << endl;
    }
};

int main()
{
    Square s;

    s.readSide();
    s.calculateArea();
    s.calculatePerimeter();
    s.display();

    return 0;
}