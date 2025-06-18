#include <iostream>
using namespace std;

int ReadPositiveNumber(string Msg) {
    int number = 0;
    do {
        cout << Msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength) {
    ArrayLength = ReadPositiveNumber("Enter Array Length: ");
    for (int i = 0; i <= ArrayLength - 1; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i < ArrayLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
    arr[arrLength] = Number;
    arrLength++;
}


void CopyOddNumbersInArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {
    for (int i = 0; i < arrLength; i++) {
        if (arrSource[i] % 2 != 0) {
            AddArrayElement(arrSource[i], arrDestination, arr2Length);
        }
    }
}


int main() {
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0, arr2Length = 0;
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyOddNumbersInArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Odd Number: ";
    PrintArray(arr2, arr2Length);
    return 0;
}