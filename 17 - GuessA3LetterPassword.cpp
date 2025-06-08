#include <iostream>
using namespace std;

string ReadAString(string Msg) {
  string Password;
  cout << Msg;
  cin >> Password;
  return Password;
}

bool GuessPassword(string OriginalPassword) {
  string word = "";
  int counter = 0;
  cout << "\n";
  for(int i = 65; i <= 90; i++) {
    for(int j = 65; j <= 90; j++) {
      for(int k = 65; k <= 90; k++) {
        counter++;
        word += char(i);
        word += char(j);
        word += char(k);
        cout << "Trial [" << counter << "] : " << word << endl;
        if(word == OriginalPassword) {
          cout << "\nPassword is " << word << "\n";
          cout << "Found after " << counter << " Trail(s)\n";
          return true;
        }
        word = "";
      }
    }
  }
  return false;
}

int main() {
  GuessPassword(ReadAString("Input Pass: "));
  return 0;
}