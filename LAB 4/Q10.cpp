#include <iostream>
using namespace std;

class AttendanceManager;

class Classroom
{
private:
    string className;
    int totalStudents;
    int presentStudents;
    string attendanceStatus;

public:
    void getData()
    {
        cout << "Enter Class Name: ";
        getline(cin, className);

        cout << "Enter Total Students: ";
        cin >> totalStudents;

        cout << "Enter Present Students: ";
        cin >> presentStudents;

        attendanceStatus = "Not Completed";
    }

    friend class AttendanceManager;
};

class AttendanceManager
{
public:
    void displayInfo(Classroom &c)
    {
        cout << "\n----- Classroom Information -----" << endl;
        cout << "Class Name: " << c.className << endl;
        cout << "Total Students: " << c.totalStudents << endl;
        cout << "Present Students: " << c.presentStudents << endl;
        cout << "Attendance Status: "
             << c.attendanceStatus << endl;
    }

    void updatePresentStudents(Classroom &c)
    {
        int present;

        cout << "Enter updated number of present students: ";
        cin >> present;

        if (present >= 0 && present <= c.totalStudents)
        {
            c.presentStudents = present;
            cout << "Present student count updated." << endl;
        }
        else
        {
            cout << "Invalid number of students." << endl;
        }
    }

    void markAttendanceCompleted(Classroom &c)
    {
        c.attendanceStatus = "Completed";
        cout << "Attendance marked as completed." << endl;
    }

    void displayAttendanceStatus(Classroom &c)
    {
        cout << "Attendance Status: "
             << c.attendanceStatus << endl;
    }

    void calculateAbsentStudents(Classroom &c)
    {
        int absentStudents =
            c.totalStudents - c.presentStudents;

        cout << "Absent Students: "
             << absentStudents << endl;
    }
};

int main()
{
    Classroom c;
    AttendanceManager manager;

    c.getData();

    manager.displayInfo(c);

    cout << "\n--- Attendance Operations ---" << endl;

    manager.updatePresentStudents(c);
    manager.markAttendanceCompleted(c);

    cout << endl;

    manager.displayInfo(c);
    manager.displayAttendanceStatus(c);
    manager.calculateAbsentStudents(c);

    return 0;
}