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

int CountDigitFrequency(short DigitToCheck, int Number) {
  int count = 0, reminder = 0;
  while (Number > 0)
  {
    reminder = Number % 10;
    Number /= 10;
    if(reminder == DigitToCheck) {
      ++count;
    }
  }
  return count;
}

void PrintCountDigitFrequency(int Number) {
  for(int i = 0; i < 10; i++) {
    short DigitFrequency = CountDigitFrequency(i, Number);
    if(DigitFrequency > 0) {
      cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)" << endl;
    }
  }
}

int main() {
  int Number = ReadPositiveNumber("Entre a Number: ");
  PrintCountDigitFrequency(Number);
  return 0;
}