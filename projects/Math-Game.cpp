#include <iostream>
using namespace std;

enum enQuestionLevel {
    Easy, Med, Hard, MIX
};

enum enOpType {
   Add, Sub, Mul, Div, Mix
};

struct stGameInfo {
    short NumberOfQuestions;
    enQuestionLevel QuestionLevel;
    enOpType OpType;
    short NumberOfRightAnswers;
    short NumberOfWrongAnswers;
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void SetWinnerScreenColor(char Answer) {
    switch (Answer) {
        case 'R':
            // Right Answer: Green Screen Color
            system("color 2F");
            break;
        case 'W':
            // Wrong Answer: Red Screen Color
            system("color 4f");
            cout << "\a";
            break;
    }
}

short ReadNumberOfQuestions() {
    short QuestionNumber = 1;
    do
    {
        cout << "How Mant Questions from 1 to 10: ";
        cin >> QuestionNumber;
    } while (QuestionNumber < 1 || QuestionNumber > 10);
    return QuestionNumber;
}

void ResetScreen() {
    system("cls");
    system("color 0f");
}

void ShowFinalGameResults(stGameInfo GameInfo) {
    cout << "\t\t" << "_______________________[Game Results]____________________\n\n";
    cout << "\t\t" << "Questions Number     : " << GameInfo.NumberOfQuestions << endl;
    cout << "\t\t" << "Question Level       : " << GameInfo.QuestionLevel << endl;
    cout << "\t\t" << "Operation Type       : " << GameInfo.OpType << endl;
    cout << "\t\t" << "Right Answer         : " << GameInfo.NumberOfRightAnswers << endl;
    cout << "\t\t" << "Wrong Answer         : " << GameInfo.NumberOfWrongAnswers << endl;
    cout << "\t\t" << "__________________________________________________________\n\n";
}

void StartGame() {
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        cout << endl << "Do you want to play again [y | n]: ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}