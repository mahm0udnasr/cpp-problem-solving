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

short FindNumberPositionInArray(int Number, int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        if (Number == arr[i]) {
            return i;
        }
    }
    return -1;
}

// bool isNumberInArray(int Number,int arr[100], int arrLength) {
//       for (int i = 0; i <= arrLength - 1; i++) {
//         if (Number == arr[i]) {
//             return true;
//         }
//     }
//     return false;
// }


bool isNumberInArray(int Number,int arr[100], int arrLength) {
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    arrLength = ReadPositiveNumber("Enter Array Length: ");

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, arrLength);

    int searchNumber = ReadPositiveNumber("\nEnter A Number To Search: ");
    cout << "\nNumber you are looking for is: " << searchNumber << "\n";

    if (isNumberInArray(searchNumber, arr, arrLength)) {
        cout << "\nyes, The number is found :-)" << endl;
    }
    else {
        cout << "\nno, The number is not found :-(" << endl;
    }
    return 0;
}