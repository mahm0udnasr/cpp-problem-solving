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

void SumOfTwoArray(int arr1[100], int arr2[100], int arrSum[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrSum[100];
    int ArrayLength = ReadPositiveNumber("Enter Array Length: ");

    FillArrayWithRandomNumbers(arr, ArrayLength);
    FillArrayWithRandomNumbers(arr2, ArrayLength);

    SumOfTwoArray(arr, arr2, arrSum, ArrayLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, ArrayLength);

    cout << "\nArray 2 elements: ";
    PrintArray(arr2, ArrayLength);

    cout << "\nSum of Arr1 and Arr2 elements: ";
    PrintArray(arrSum, ArrayLength);
    return 0;
}