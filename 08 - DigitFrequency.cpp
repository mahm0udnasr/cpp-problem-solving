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

void PrintCountDigitFrequency(int Number, short Frequency) {
  int count = 0, reminder = 0;
  while (Number > 0)
  {
    reminder = Number % 10;
    Number /= 10;
    if(reminder == Frequency) {
      ++count;
    }
  }
  cout << "Digit " << Frequency << " Frequency is " << count << " Time(s)" << endl;
}

int main() {
  PrintCountDigitFrequency(ReadPositiveNumber("Entre a Number: "), ReadPositiveNumber("Entre a Frequency: "));
  return 0;
}