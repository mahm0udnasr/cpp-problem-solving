#include <iostream>
using namespace std;

float ReadNumber(string Msg) {
    float number = 0;
    cout << Msg;
    cin >> number;
    return number;
}

float MyABS(float Number) {
    return Number < 0 ? Number * -1 : Number;
}

int main() {
    float Number = ReadNumber("Enter a number: ");
    cout << "\nMy ABS Result: " << MyABS(Number) << endl;
    cout << "\nC++ ABS Result: " << abs(Number) << endl;
    return 0;
}