
#include <iostream>
#include <string>
using namespace std;

class Document {
public:
    virtual void exportFile(string filename) {
        cout << "Exporting document\n";
    }

    virtual ~Document() {}
};
class PDFDocument : public Document {
public:
    void exportFile(string filename) override {
        cout << "Exporting " << filename
             << " as PDF (.pdf)\n";
    }
};

class TextDocument : public Document {
public:
    void exportFile(string filename) override {
        cout << "Exporting " << filename
             << " as Text (.txt)\n";
    }
};

class CSVDocument : public Document {
public:
    void exportFile(string filename) override {
        cout << "Exporting " << filename
             << " as CSV (.csv)\n";
    }
};

int main() {
    string filename;

    cout << "Enter document name (without extension): ";
    cin >> filename;

    PDFDocument pdf;
    TextDocument txt;
    CSVDocument csv;

    Document *ptr;

    ptr = &pdf;
    ptr->exportFile(filename);

    ptr = &txt;
    ptr->exportFile(filename);

    ptr = &csv;
    ptr->exportFile(filename);

    return 0;
}
