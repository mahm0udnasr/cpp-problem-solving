#include <iostream>
#include <math.h>
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

bool isPerfectNumber(int Number) {
  int sum = 0;
  for(int i = 1; i < Number;  i++) {
    if (Number % i == 0) {
      sum += i;
    }
  }
  return Number == sum;
}

void PrintPerfectNumberFrom1toN(int num) {
  for(int i = 1; i <= num; i++) {
    if(isPerfectNumber(i)) {
      cout << i << endl;
    }
  }
}

int main() {
  PrintPerfectNumberFrom1toN(ReadPositiveNumber("Enter a positive number: "));
  return 0;
}