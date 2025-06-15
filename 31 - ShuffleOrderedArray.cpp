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

void FillArrayWith1toN(int arr[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        arr[i] = i + 1;
    }
}

void PrintArray(int arr[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Swap(int &A, int &B) {
    int temp = 0;
    temp = A;
    A = B;
    B = temp;
}

void ShuffleArray(int arr[100], int ArrayLength) {
    for (int i = 0; i <= ArrayLength - 1; i++) {
        Swap(arr[RandomNumber(1, ArrayLength) - 1], arr[RandomNumber(1, ArrayLength) - 1]);
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int ArrayLength = ReadPositiveNumber("Enter Array Length: ");

    FillArrayWith1toN(arr, ArrayLength);

    cout << "\nArray elements before shuffle: ";
    PrintArray(arr, ArrayLength);

    ShuffleArray(arr, ArrayLength);

    cout << "\nArray elements after shuffle: ";
    PrintArray(arr, ArrayLength);
    return 0;
}