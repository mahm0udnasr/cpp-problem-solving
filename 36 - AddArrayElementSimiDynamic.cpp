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

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i <= arrLength - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
  arrLength++;
  arr[arrLength - 1] = Number;
}

void InputUserNumberInArray(int arr[100], int& arrLength) {
    bool AddMoreNumber = false;
    do
    {
        // int Element = ReadPositiveNumber("Please Enter A Number: ");
        // for (int i = 0; i <= arrLength; i++) {
        //     arr[arrLength] = Element;
        // }
        AddArrayElement(ReadPositiveNumber("Please Enter A Number: "), arr, arrLength);
        cout << "Do You Want To Add More Number [0, 1]: ";
        cin >> AddMoreNumber;
        // arrLength += 1;
    } while (AddMoreNumber);
}


int main() {
    int arr[100], arrLength = 0;
    InputUserNumberInArray(arr, arrLength);
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array 1 elements: ";
    PrintArray(arr, arrLength);
    return 0;
}