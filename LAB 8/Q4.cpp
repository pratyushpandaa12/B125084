
#include <iostream>
using namespace std;

class BackupPolicy {
public:
    virtual double calculateStorage(double size) {
        return 0;
    }

    virtual ~BackupPolicy() {}
};

class FullBackup : public BackupPolicy {
public:
    double calculateStorage(double size) override {
        return size;
    }
};

class IncrementalBackup : public BackupPolicy {
public:
    double calculateStorage(double size) override {
        return (0.25 * size) + 50;
    }
};

int main() {
    double size;

    cout << "Enter data size in MB: ";
    cin >> size;

    FullBackup f;
    IncrementalBackup i;

    BackupPolicy *ptr;

    ptr = &f;
    cout << "Full Backup Storage: "
         << ptr->calculateStorage(size)
         << " MB\n";

    ptr = &i;
    cout << "Incremental Backup Storage: "
         << ptr->calculateStorage(size)
         << " MB\n";

    return 0;
}
