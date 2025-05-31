#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int ReadPositiveNumber(string Msg) {
  int number = 0;
  do {
    cout << Msg;
    cin >> number;
  } while(number <= 0);
  return number;
}

void PrintDigitsReversed(int number) {
  string DigitNumberToString = to_string(number);
  for(int i = DigitNumberToString.length(); i >= 0; i--) {
    cout << DigitNumberToString[i] << endl;
  }
}

int main() {
  PrintDigitsReversed(ReadPositiveNumber("Entre a positive number: "));
  return 0;
}