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
        arr[i] = RandomNumber(-100, 100);
    }
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i < ArrayLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int NegativeNumberCountInArray(int arr[100], int arrLength) {
    int NegativeNumberCounter = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] < 0) {
            NegativeNumberCounter++;
        }
    }
    return NegativeNumberCounter;
}

int main() {
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength = 0;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nNegative Numbers Count Is: " << NegativeNumberCountInArray(arr, arrLength) << endl;

    return 0;
}