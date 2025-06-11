#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Quiz {
    string question;
    string options[4];
    char correct; // 'A', 'B', 'C', or 'D'
};

void loadQuestions(vector<Quiz>& quiz) {
    quiz.push_back({"What is the capital of France?",
                   {"A. Paris", "B. Rome", "C. Madrid", "D. Berlin"}, 'A'});

    quiz.push_back({"Which data structure uses FIFO principle?",
                   {"A. Stack", "B. Queue", "C. Tree", "D. Graph"}, 'B'});

    quiz.push_back({"Which planet is known as the Red Planet?",
                   {"A. Earth", "B. Venus", "C. Mars", "D. Jupiter"}, 'C'});

    quiz.push_back({"Who wrote 'Romeo and Juliet'?",
                   {"A. Charles Dickens", "B. William Shakespeare", "C. J.K. Rowling", "D. Mark Twain"}, 'B'});

    quiz.push_back({"Which language is used to develop system-level programs?",
                   {"A. HTML", "B. Python", "C. Java", "D. C"}, 'D'});
}

void playQuiz(const vector<Quiz>& quiz) {
    char answer;
    int score = 0;

    for (size_t i = 0; i < quiz.size(); ++i) {
        cout << "\nQ" << i + 1 << ": " << quiz[i].question << endl;
        for (int j = 0; j < 4; ++j) {
            cout << quiz[i].options[j] << endl;
        }

        cout << "Your answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);

        if (answer == quiz[i].correct) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Wrong! Correct answer: " << quiz[i].correct << endl;
        }
    }

    cout << "\nYour Score: " << score << " out of " << quiz.size() << endl;
    if (score == quiz.size())
        cout << "Excellent!" << endl;
    else if (score >= quiz.size() / 2)
        cout << "Good job!" << endl;
    else
        cout << "Better luck next time!" << endl;
}

int main() {
    vector<Quiz> quiz;
    loadQuestions(quiz);

    cout << "==== Welcome to the Quiz Game ====\n";
    playQuiz(quiz);

    return 0;
}
