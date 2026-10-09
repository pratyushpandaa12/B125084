
#include <iostream>
using namespace std;

class Score {
    int score;

public:
    Score(int s = 0) {
        score = s;
    }

    Score operator++() {
        ++score;
        return *this;
    }

    Score operator++(int) {
        Score old = *this;
        score++;
        return old;
    }

    void display() const {
        cout << score << endl;
    }
};

int main() {
    int value;

    cout << "Enter initial score: ";
    cin >> value;

    Score original(value);

    Score prefixResult = ++original;

    cout << "\nResult of prefix increment: ";
    prefixResult.display();

    cout << "Original score after prefix: ";
    original.display();

    Score postfixResult = original++;

    cout << "Result of postfix increment: ";
    postfixResult.display();

    cout << "Original score after postfix: ";
    original.display();

    return 0;
}
