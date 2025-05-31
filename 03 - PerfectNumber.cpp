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

bool isPerfectNumber(int Number) {
  int sum = 0;
  for(int i = 1; i < Number;  i++) {
    if (Number % i == 0) {
      sum += i;
    }
  }
  return Number == sum;
}

void PrintResult(int num) {
  if (isPerfectNumber(num)) {
    cout << num << " is perfect" << endl;
  } else {
    cout << num << " is non perfect" << endl;
  }
}

int main() {
  PrintResult(ReadPositiveNumber("Enter a positive number: "));
  return 0;
}