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

void PrintSumOfDigits(int number) {
    int remainder = 0, sum = 0;
    while(number > 0) {
      remainder = number %10;
      number /= 10;
      sum += remainder;
    }
    cout << "Total of Digits = " << sum << endl;
}

int main() {
  PrintSumOfDigits(ReadPositiveNumber("Entre a positive number: "));
  return 0;
}