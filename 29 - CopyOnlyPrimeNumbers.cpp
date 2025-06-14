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

bool isPrime(int num) {
    int M = round(num / 2);
    for (int counter = 2; counter <= M; counter++) {
        if (num % counter == 0) {
            return false;
        }
    }
    return true;
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

void CopyPrimeNumberFromArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {
    arr2Length = 0;
    for (int i = 0; i <= arrLength - 1; i++) {
        if (isPrime(arrSource[i])) {
            arrDestination[arr2Length] = arrSource[i];
            arr2Length++;
        }
    }
}


int main() {
    srand((unsigned)time(NULL));
    int arr[100], ArrayLength;
    FillArrayWithRandomNumbers(arr, ArrayLength);

    int arr2[100], arr2Length = 0;
    CopyPrimeNumberFromArray(arr, arr2, ArrayLength, arr2Length);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, ArrayLength);

    cout << "\nPrime number in array2: ";
    PrintArray(arr2, arr2Length);
    return 0;
}