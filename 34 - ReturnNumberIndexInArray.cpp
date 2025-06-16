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

void FillArrayWithRandomNumbers(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

short FindNumberPositionInArray(int arr[100], int arrLength) {
    short SearchNumber = ReadPositiveNumber("\nEnter A Number To Search: ");
    for (int i = 0; i <= arrLength - 1; i++) {
        if (SearchNumber == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    arrLength = ReadPositiveNumber("Enter Array Length: ");

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    short NumberPosition = FindNumberPositionInArray(arr, arrLength);
    if (NumberPosition != -1) {
        cout << "\nThe Number found at position: " << NumberPosition << "\n";
        cout << "\nThe Number found its order : " << NumberPosition + 1 << endl;
    }
    else {
        cout << "\nThe Number Is Not Found!" << endl;
    }
    return 0;
}