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

void PrintNumberInOrder(int Number) {
  string OrderedNumber = to_string(Number);
  for(int i = 0; i < OrderedNumber.length(); i++) {
    cout << OrderedNumber[i] << endl;
  }
}

int main() {
  PrintNumberInOrder(ReadPositiveNumber("Entre a positive number: "));
  return 0;
}



/*
 * another solution (best practice)
int ReverseNumber(int Number)
{
    int Remainder = 0;
    int Number2 = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    
    return Number2;
}

void PrintDigits(int Number)
{
    int Remainder = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
}

>> PrintDigits(ReverseNumber(*****));
*/