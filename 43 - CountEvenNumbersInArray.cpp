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

int EvenNumberCountInArray(int arr[100], int arrLength) {
    int EvenNumberCounter = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) {
            EvenNumberCounter++;
        }
    }
    return EvenNumberCounter;
}

int main() {
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nEven Numbers Count Is: " << EvenNumberCountInArray(arr, arrLength) << endl;

    return 0;
}