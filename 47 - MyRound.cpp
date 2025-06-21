#include <iostream>
using namespace std;

float ReadNumber(string Msg) {
    float number = 0;
    cout << Msg;
    cin >> number;
    return number;
}

float GetFractionPart(float Number) {
    return Number - (int)Number;
}

float MyRound(float Number) {
    int intPart = (int)Number;

    float FractionPart = GetFractionPart(Number);

    if (abs(FractionPart) >= .5) {
        if (Number > 0) {
            return ++intPart;
        }
        else {
            return --intPart;
        }
    }
    else {
        return intPart;
    }
}

int main() {
    float Number = ReadNumber("Enter a number: ");
    cout << "\nMy Round Result: " << MyRound(Number) << endl;
    cout << "\nC++ Round Result: " << round(Number) << endl;
    return 0;
}