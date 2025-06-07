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

void PrintLetterPattern(int Number) {
  for(int i = 1; i <= Number; i++) {
    for(int j = i; j >= 1; j--) {
        cout << char(64 + i);
    }
    cout << "\n";
  }
}

/*
  * another solution
  for (int i = 65; i <= 65 + Number - 1; i++) {
    for (int j = 1; j <= i - 65 + 1; j++) {
        cout << char(i);
    }
    cout << "\n";
  }
*/


int main() {
  PrintLetterPattern(ReadPositiveNumber("Entre a number: "));
  return 0;
}