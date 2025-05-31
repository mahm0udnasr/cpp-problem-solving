#include <iostream>
#include <string>
#include <math.h>
using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


int ReadPositiveNumber(string Msg) {
  int number = 0;
  do {
    cout << Msg;
    cin >> number;
  } while(number <= 0);
  return number;
}

enPrimNotPrime CheckPrime(int num) {
  int M = round(num/2);
  for(int counter = 2; counter <= M; counter++) {
    if(num % counter == 0) {
      return enPrimNotPrime::NotPrime;
    }
  }
  return enPrimNotPrime::Prime;
}

void PrintResult(int num) {
  cout << "Prime Numbers from " << 1 << " to " << num << endl;
  cout << " ara: " << endl;
  for(int i = 1; i <= num; i++) {
    if (CheckPrime(i) == enPrimNotPrime::Prime) {
      cout << i << endl;
    }
  }
}

int main() {
  PrintResult(ReadPositiveNumber("Entre a positive number: "));
  return 0;
}