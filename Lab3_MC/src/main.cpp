#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "mura_machine.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

// 36 вариант

// 5 входов
// 6 состояний
// 4 выхода

Vector splitBySpace(const string &str) {
    std::istringstream iss(str);
    Vector tokens;
    string token;

    while (iss >> token) {
        if (token.size() != 1) {
            exit(EXIT_FAILURE);
        }
        tokens.push_back(std::stoi(token));
    }

    return tokens;
}

int main() {
    string input;
    getline(cin, input);
    cout << input << endl;
    Vector sequence_input_signals = splitBySpace(input);
     // Устанавливаем ширину поля в зависимости от максимальной длины строкового представления входных сигналов
    int fieldWidth = 6; // Вы можете регулировать это значение в зависимости от нужд

    cout << "Номер такта работы автомата"   ;
    cout << setw(fieldWidth + 1) << "--";
    for (int i = 0; i < sequence_input_signals.size(); ++i) {
        cout << setw(fieldWidth + 1) << i + 1;
    }
    cout << endl;


    cout << "Послед. входных сигналов:   ";
    cout << setw(fieldWidth) << "--";
    for (int i = 0; i < sequence_input_signals.size(); i++)
    {   
        cout << setw(fieldWidth) << "x" << sequence_input_signals[i];
    }
    cout << endl;
}