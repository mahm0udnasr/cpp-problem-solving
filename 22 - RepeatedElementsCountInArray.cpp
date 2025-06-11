#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Msg) {
    int number = 0;
    do {
        cout << Msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

void ReadArray(int arr[100], int& ArrayLength) {
    ArrayLength = ReadPositiveNumber("Enter Array Length: ");
    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i <= ArrayLength - 1; i++) {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int ArrayLength) {
    int TimeRepeatedCount = 0;
    for (int i = 0; i <= ArrayLength - 1; i++) {
        if (Number == arr[i]) {
            TimeRepeatedCount++;
        }
    }
    return TimeRepeatedCount;
}


int main() {
    int arr[100], ArrayLength, NumberToCheck;
    ReadArray(arr, ArrayLength);
    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");
    cout << "\nOriginal Array: ";
    PrintArray(arr, ArrayLength);
    cout << "Number: " << NumberToCheck << " is repeated ";
    cout << TimesRepeated(NumberToCheck, arr, ArrayLength) << " time(s)" << endl;
    return 0;
}