
#include <iostream>
#include <string>
using namespace std;

class Image {
protected:
    int width, height;

public:
    Image(int w, int h) {
        width = w;
        height = h;
    }
};

class CompressedImage : public Image {
protected:
    double compression;

public:
    CompressedImage(int w, int h, double c)
        : Image(w, h) {
        compression = c;
    }
};

class EncryptedImage : public CompressedImage {
private:
    string algorithm;

public:
    EncryptedImage(int w, int h, double c, string a)
        : CompressedImage(w, h, c) {
        algorithm = a;
    }

    void display() {
        long long originalPixels = 1LL * width * height;
        double effectivePixels =
            originalPixels * compression / 100.0;

        cout << "\n--- Image Metadata ---\n";
        cout << "Width: " << width << " pixels\n";
        cout << "Height: " << height << " pixels\n";
        cout << "Original Pixels: " << originalPixels << endl;
        cout << "Compression: " << compression << "%\n";
        cout << "Effective Pixel Size: "
             << effectivePixels << endl;
        cout << "Encryption Algorithm: " << algorithm << endl;
    }
};

int main() {
    int w, h;
    double c;
    string algorithm;

    cout << "Enter image width: ";
    cin >> w;

    cout << "Enter image height: ";
    cin >> h;

    cout << "Enter compression percentage: ";
    cin >> c;

    cout << "Enter encryption algorithm: ";
    cin >> algorithm;

    EncryptedImage img(w, h, c, algorithm);
    img.display();

    return 0;
}
