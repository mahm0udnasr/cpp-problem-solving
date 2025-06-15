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
    for (int i = 0; i <= ArrayLength - 1; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        arrDestination[i] = arrSource[arrLength - 1 - i];
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = ReadPositiveNumber("Enter Array Length: ");

    FillArrayWithRandomNumbers(arr, arrLength);
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after copying array 1 in reversed order: \n";
    PrintArray(arr2, arrLength);
    return 0;
}