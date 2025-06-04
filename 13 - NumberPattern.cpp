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

void PrintNumberPattern(int Number) {
  for(int i = 1; i <= Number; i++) {
    for(int j = i; j >= 1; j--) {
      cout << i;
    }
    cout << "\n";
  }
}

int main() {
  PrintNumberPattern(ReadPositiveNumber("Read A Number: "));
  return 0;
}