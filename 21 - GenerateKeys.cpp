#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


int ReadPositiveNumber(string Msg) {
    int number = 0;
    do {
        cout << Msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break; // break is not necessary after return.
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
    return '\0';
}

string GenerateRandomKey(enCharType CharType, short Length) {
    string Key;
    for (int i = 1; i <= Length; i++) {
        Key += GetRandomCharacter(CharType);
    }
    return Key;
}

string GenerateKey()
{
    string Key = "";
    for (int j = 1; j <= 4; j++) {
        Key += GenerateRandomKey(enCharType::CapitalLetter, 4);
        if (j <= 3) {
            Key += "-";
        }
        else {
            continue;
        }
    }
    return Key;
}

void GenerateKeys(short NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++) {
        cout << "\n";
        cout << "Key [";
        if (i <= 9) {
            cout << "0" << i;
        }
        else {
            cout << i;
        }
        cout << "] : ";
        cout << GenerateKey() << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    short NumberOfKeys = ReadPositiveNumber("Entre A Length Of Keys: ");
    GenerateKeys(NumberOfKeys);
    return 0;
}