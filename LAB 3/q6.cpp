#include <iostream>
using namespace std;

// Represent a product and calculate its total cost from quantity and price.
class Product
{
    int productID;
    string productName;
    int quantity;
    float price;

public:

    // Read product details from standard input.
    void accept()
    {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    // Display details and the derived total product cost.
    void display()
    {
        cout << "\nProduct Details ---" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName<< endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
        cout << "TOTAL PRODUCT COST: " << price * quantity << endl;
    }
};

int main()
{
    Product *b = new Product;

    b->accept();
    b->display();

    delete b;
    b = nullptr;
    return 0;
}
