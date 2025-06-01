#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Msg) {
  int number = 0;
  do {
    cout << Msg;
    cin >> number;
  } while(number <= 0);
  return number;
}

void PrintReversedNumber(int Number) {
  int reminder = 0;
  string ReversedNumber;
  while(Number > 0) {
    reminder = Number % 10;
    Number /= 10;
    ReversedNumber += to_string(reminder);
  }
  cout << "Reversed Number is: " << ReversedNumber << endl;
}

int main() {
  PrintReversedNumber(ReadPositiveNumber("Entre a positive number: "));
  return 0;
}