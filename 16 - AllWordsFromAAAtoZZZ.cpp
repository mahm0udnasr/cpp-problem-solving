#include <iostream>
using namespace std;

void PrintAllWordsFromAAAtoZZZ() {
  for(int i = 65; i <= 90; i++) {
    for(int j = 65; j <= 90; j++) {
      for(int k = 65; k <= 90; k++) {
        cout << char(i) << char(j) << char(k) << endl;
      }
    }
  }
}

int main() {
  PrintAllWordsFromAAAtoZZZ();
  return 0;
}