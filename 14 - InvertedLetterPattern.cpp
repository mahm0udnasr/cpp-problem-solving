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

void PrintInvertedLetterPattern(int Number) {
  for(int i = Number; i >= 1; i--) {
    for(int j = 1; j <= i; j++) {
        cout << char(64 + i);
    }
    cout << "\n";
  }
}

/*
  * another solution
  for (int i = 65 + Number - 1; i >= 65; i--) {
    for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++) {
        cout << char(i);
    }
  }
  - explain code
  - 5 -> for (int i = 65 + 5 - 1; i >= 65; i--) -> 69 -> E (first loop from 69 to 65) E to A
  - for (int j = 1; j <= 5 - ((65 + 5 - 1) - i); j++) -> loop char pattern
  EEEEE
  DDDD
  CCC
  BB
  A
*/


int main() {
  PrintInvertedLetterPattern(ReadPositiveNumber("Entre a number: "));
  return 0;
}