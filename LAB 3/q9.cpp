#include <iostream>
using namespace std;

// Store employee records in a dynamically allocated array of objects.
class Employee {
    

public:
int id;
    string name;
    double salary;
    void accept();
    void display();
};
void Employee::accept() {
    // Read one employee record.
    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter salary: ";
    cin >> salary;
}
void Employee::display() {
    // Print one employee record in a consistent format.
    cout << "Employee ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "-----------------------------" << endl;
}




int main()
{
    int n;
cout << "Enter number of employees: ";
cin >> n;

Employee* empArray = new Employee[n];
for (int i=0;i<n;i++)
{
    cout << "Enter details of the employee "<< i+1 << endl;
    empArray[i].accept();
}
cout << "==== EMPLOYEE DETAILS ====\n";
for (int i=0;i<n;i++)
{
    cout << "Employee "<< i+1 << endl;
    empArray[i].display();
}
int idx = 0;
double totalSalary = empArray[0].salary;
for (int i=1;i<n;i++)
{
   totalSalary += empArray[i].salary;
   if(empArray[i].salary > empArray[idx].salary)
   idx =i ;
}
cout << "==== EMPLOYEE DETAILS OF HIGHEST SALARY====\n";

empArray[idx].display();
double avg = totalSalary / n;
cout << "==== AVERAGE SALARY====\n";
cout << "Average Salary = "<< avg<<endl;
delete[] empArray; // Release the complete object array.

    return 0;
}
