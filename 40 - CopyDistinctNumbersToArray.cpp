#include <iostream>
using namespace std;

void FillArray(int arrSource[100], int& sourceLength) {
    sourceLength = 10;
    arrSource[0] = 10;
    arrSource[1] = 10;
    arrSource[2] = 10;
    arrSource[3] = 50;
    arrSource[4] = 50;
    arrSource[5] = 70;
    arrSource[6] = 70;
    arrSource[7] = 70;
    arrSource[8] = 70;
    arrSource[9] = 90;
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i < ArrayLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        if (Number == arr[i]) {
            return i;
        }
    }
    return -1;
}

bool isNumberInArray(int Number, int arr[100], int arrLength) {
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
    arr[arrLength] = Number;
    arrLength++;
}


void CopyDistinctNumbersInArray(int arrSource[100], int arrDestination[100], int sourceLength, int& destinationLength) {
    for (int i = 0; i < sourceLength; i++) {
        if(!isNumberInArray(arrSource[i], arrDestination, destinationLength))
        AddArrayElement(arrSource[i], arrDestination, destinationLength);
    }
}


int main() {
    int arrSource[100], sourceLength = 0, arrDestination[100], destinationLength = 0;

    FillArray(arrSource, sourceLength);

    cout << "\nArray 1 Elements: ";
    PrintArray(arrSource, sourceLength);

    CopyDistinctNumbersInArray(arrSource, arrDestination, sourceLength, destinationLength);

    cout << "\nArray 2 Distinct Number: ";
    PrintArray(arrDestination, destinationLength);

    return 0;
}