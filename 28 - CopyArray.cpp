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
    for (int i = 0; i <= ArrayLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        arrDestination[i] = arrSource[i];
    }
}


int main() {
    srand((unsigned)time(NULL));
    int arr[100], ArrayLength;
    FillArrayWithRandomNumbers(arr, ArrayLength);
    
    int arr2[100];
    CopyArray(arr, arr2, ArrayLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, ArrayLength);

    cout << "\nArray 2 elements after copy: ";
    PrintArray(arr2, ArrayLength);
    return 0;
}