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

int MyCeil(float Number) {
    if (abs(GetFractionPart(Number))> 0) {
        if (Number > 0) {
            return (int)Number + 1;
        }
        else {
            return (int)Number;
        }
    }
    else {
        return Number;
    }
}

int main() {
    float Number = ReadNumber("Enter a number: ");
    cout << "\nMy Ceil Result: " << MyCeil(Number) << endl;
    cout << "\nC++ Ceil Result: " << ceil(Number) << endl;
    return 0;
}