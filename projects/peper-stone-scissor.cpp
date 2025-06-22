#include <iostream>
using namespace std;

enum enChoice { paper = 1, stone = 2, scissor = 3 };

short GetComputerChoice() {
    return rand() % (1 + 2) + 1;
}

short ReadPlayerChoice() {
    short PlayerChoice;
    cout << "\nChoice: [1] Paper [2] Stone [3] Scissor: ";
    cin >> PlayerChoice;
    return PlayerChoice;
}

short ReadNumberOfRounds() {
    short RoundLength;
    cout << "\nHow many rounds you want play: ";
    cin >> RoundLength;
    return RoundLength;
}

void StartGame() {
    int NumberOfRounds = ReadNumberOfRounds();
    short playerWinCount = 0, ComputerWinCount = 0, DrawCount = 0;
    for (int i = 1; i <= NumberOfRounds; i++) {
        short PlayerChoice = ReadPlayerChoice();
        short ComputerChoice =  GetComputerChoice();
        
        if (PlayerChoice == ComputerChoice) {
            cout << "\nDraw\n";
            DrawCount++;
        }
        else if (PlayerChoice == 1 && ComputerChoice == 2) {
            cout << "\nPlayer Winner\n";
            playerWinCount++;
        }
        else if (PlayerChoice == 2 && ComputerChoice == 3) {
            cout << "\nPlayer Winner\n";
            playerWinCount++;
        }
        else if (PlayerChoice == 3 && ComputerChoice == 1) {
            cout << "\nPlayer Winner\n";
            playerWinCount++;
        }
        else if (ComputerChoice == 1 && PlayerChoice == 2) {
            cout << "\nComputer Winner\n";
            ComputerWinCount++;
        }
        else if (ComputerChoice == 2 && PlayerChoice == 3) {
            cout << "\nComputer Winner\n";
            ComputerWinCount++;
        }
        else if (ComputerChoice == 3 && PlayerChoice == 1) {
            cout << "\nComputer Winner\n";
            ComputerWinCount++;
        }
        else {
            cout << "\nCorrect Choice\n";
        }
    }
    cout << "\nPlayer Win: " << playerWinCount << endl;
    cout << "Computer Win: " << ComputerWinCount << endl;
    cout << "Draw: " << DrawCount << endl;
}



int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}