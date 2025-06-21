#include <iostream>
using namespace std;

float ReadNumber(string Msg) {
    float number = 0;
    cout << Msg;
    cin >> number;
    return number;
}

float MyFloor(float Number) {
    if (Number > 0) {
        return (int)Number;
    }
    else {
        return (int)Number - 1;
    }
}

int main() {
    float Number = ReadNumber("Enter a number: ");
    cout << "\nMy Floor Result: " << MyFloor(Number) << endl;
    cout << "\nC++ Floor Result: " << floor(Number) << endl;
    return 0;
}