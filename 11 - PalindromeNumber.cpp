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

int ReverseNumber(int Number) {
  int reminder = 0, Number2 = 0;
  while (Number > 0)
  {
    reminder = Number % 10;
    Number /= 10;
    Number2 = Number2 * 10 + reminder;
  }
  return Number2;
}

bool isPalindromeNumber(int Number) {
  return Number ==  ReverseNumber(Number);
}


int main() {
  if(isPalindromeNumber(ReadPositiveNumber("Entre a number: "))) {
    cout << "\nYes, it is a Palindrome Number.\n";
  } else {
    cout << "\nNo, it is not a Palindrome Number.\n";
  }
}