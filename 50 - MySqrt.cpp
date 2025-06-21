#include <iostream>
using namespace std;

float ReadNumber(string Msg) {
    float number = 0;
    cout << Msg;
    cin >> number;
    return number;
}

int MySqrt(float Number) {
    return pow(Number, 0.5);
}

int main() {
    float Number = ReadNumber("Enter a number: ");
    cout << "\nMy Sqrt Result: " << MySqrt(Number) << endl;
    cout << "\nC++ Ceil Result: " << sqrt(Number) << endl;
    return 0;
}