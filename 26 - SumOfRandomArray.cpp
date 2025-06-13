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

int SumOfArray(int arr[100], int ArrayLength) {
    int sum = 0;
    for (int i = 0; i <= ArrayLength - 1; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    srand((unsigned)time(NULL));
    int arr[100], ArrayLength;
    FillArrayWithRandomNumbers(arr, ArrayLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, ArrayLength);
    cout << "\nSum of all number is: " << SumOfArray(arr, ArrayLength);
    return 0;
}