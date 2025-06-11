#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Msg) {
    int number = 0;
    do {
        cout << Msg;
        cin >> number;
    } while (number <= 0 || number >= 100);
    return number;
}

char GetRandomCapitalChar() {
    return char(rand() % (65 - 90 + 1) + 65);
}

string GenerateRandomKey() {
    string Key;
    for (int i = 1; i <= 4; i++) {
        Key += GetRandomCapitalChar();
    }
    return Key;
}

void PrintRandomKeys(int length) {\
    for (int i = 1; i <= length; i++) {
        cout << "\n";
        cout << "Key [";
        if (i <= 9) {
            cout << "0" << i;
        }
        else {
            cout << i;
        }
        cout << "] : ";
        for (int j = 1; j <= 4; j++) {
            cout << GenerateRandomKey();
            if (j <= 3) {
                cout << "-";
            }
            else {
                continue;
            }
        }
        cout << "\n";
    }
}

int main() {
    srand((unsigned)time(NULL));
    int length = ReadPositiveNumber("Entre A Length Of Keys: ");
    PrintRandomKeys(length);
	return 0;
}