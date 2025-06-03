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

void PrintInvertedNumberPattern(int Number) {
  for(int i = Number; i >=1; i--) {
    for(int j = 1; j <= i; j++) {
      cout << i;
    }
    cout << "\n";
  }
}

int main() {
  PrintInvertedNumberPattern(ReadPositiveNumber("Read A Number: "));
  return 0;
}