#include <iostream>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResult {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }

    switch (RoundInfo.PlayerChoice) {
        case enGameChoice::Stone:
            if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Paper:
            if (RoundInfo.ComputerChoice == enGameChoice::Scissors) {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Scissors:
            if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
                return enWinner::Computer;
            }
            break;
    }
    return enWinner::Player;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {

}

string ChoiceName(enGameChoice Choice) {
    string arrGameChoice[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoice[Choice - 1];
}

string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner) {

}

enGameChoice ReadPlayerChoice() {
    short PlayerChoice = 1;
    do
    {
        cout << "\nYour Choice: [1]: Stone, [2] Paper, [3] Scissors :";
        cin >> PlayerChoice;
    } while (PlayerChoice < 1 || PlayerChoice > 3);
    return (enGameChoice)PlayerChoice;
}

enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1,3);
}

void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "] \n";
    cout << "_____________________________________\n" << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResult PlayGame(short RoundsNumber) {
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= RoundsNumber; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins: \n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player) {
            PlayerWinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer) {
            ComputerWinTimes++;
        }
        else {
            DrawTimes++;
        }
        PrintRoundResults(RoundInfo);
    }
}

void ShowGameOverScreen() {
    cout << "\t------------------------------------------\n";
    cout << "\t\t +++ G a m e O v e r +++ \n";
    cout << "\t------------------------------------------\n";
}

void ShowFinalGameResults(stGameResult GameResults) {

}

short ReadNumberOfRounds() {
    short GameRounds = 1;
    do
    {
        cout << "How many Round 1 to 10: ";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

void ResetScreen() {

}

void StartGame() {
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResult GameResults = PlayGame(ReadNumberOfRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        cout << endl << "Do you want to play again [y | n]: ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    return 0;
}