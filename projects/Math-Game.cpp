#include <iostream>
using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuiz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void ResetScreen() {
    system("cls");
    system("color 0f");
}

short ReadNumberOfQuestion() {
    short QuestionNumber = 1;
    do
    {
        cout << "Enter Question Number from 1 to 10: ";
        cin >> QuestionNumber;
    } while (QuestionNumber < 1 || QuestionNumber > 10);
    return QuestionNumber;
}

enQuestionsLevel ReadQuestionLevel() {
    int QuestionLevel = 1;
    do
    {
        cout << "Select Question Level\n [1] Easy [2] Medium [3] Hard [4] Mix : ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOperationType() {
    int OpType = 1;
    do
    {
        cout << "Select Operation Type\n[1] +\n[2] -\n[3] *\n[4] /\n[5] Mix : ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType)OpType;
}

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "*";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
    return arrQuestionLevelText[QuestionLevel - 1];
}

void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); // Green for correct answers.
    else
    {
        system("color 4F"); // Red for incorrect answers.
        cout << "\a";
    }
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mult:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number2 != 0) ? (Number1 / Number2) : 0;  // Avoid division by zero.
    default:
        return Number1 + Number2;
    }
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix)
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;

    return Question;
}

void AskAndCorrectQuestionListAnswers(stQuiz& Quiz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
    {
        cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]\n";
        cout << Quiz.QuestionList[QuestionNumber].Number1 << " "
            << GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OperationType) << " "
            << Quiz.QuestionList[QuestionNumber].Number2 << " = ";

        cin >> Quiz.QuestionList[QuestionNumber].PlayerAnswer;

        if (Quiz.QuestionList[QuestionNumber].PlayerAnswer == Quiz.QuestionList[QuestionNumber].CorrectAnswer)
        {
            cout << "Correct!\n";
            SetScreenColor(true);
            Quiz.NumberOfRightAnswers++;
        }
        else
        {
            cout << "Wrong! Correct Answer: " << Quiz.QuestionList[QuestionNumber].CorrectAnswer << endl;
            SetScreenColor(false);
            Quiz.NumberOfWrongAnswers++;
        }
    }

    Quiz.isPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}


void PlayMathGame()
{
    stQuiz Quiz;
    Quiz.NumberOfQuestions = ReadNumberOfQuestion();
    Quiz.QuestionsLevel = ReadQuestionLevel();
    Quiz.OpType = ReadOperationType();
    for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
    {
        Quiz.QuestionList[QuestionNumber] = GenerateQuestion(Quiz.QuestionsLevel, Quiz.OpType);
    }
    AskAndCorrectQuestionListAnswers(Quiz);
    cout << "\nQuiz Completed! Right Answers: " << Quiz.NumberOfRightAnswers
        << ", Wrong Answers: " << Quiz.NumberOfWrongAnswers << "\n";
    cout << (Quiz.isPass ? "You Passed the Quiz!\n" : "You Failed the Quiz!\n");
}

void StartGame() {
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        PlayMathGame();
        cout << endl << "Do you want to play again [y | n]: ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}