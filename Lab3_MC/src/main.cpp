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
    int number_input = 0;

    while (iss >> token) {
        number_input = std::stoi(token);
        if (number_input <= 0 || number_input > 5) {
            cout << "Ошибка: входные сигналы должны быть в диапозоне 1-5" << endl;
            exit(EXIT_FAILURE);
        }
        tokens.push_back(number_input);
    }

    return tokens;
}

int main() {
    string input;
    
    cout << "Введите входные сигналы: ";

    getline(cin, input);
 
    Vector sequence_input_signals = splitBySpace(input);
     
    int fieldWidth = 6; 

    cout << "Номер такта работы автомата:"   ;
    cout << setw(fieldWidth + 1) << "--";
    for (int i = 0; i < sequence_input_signals.size(); i++) {
        cout << setw(fieldWidth + 1) << i + 1;
    }
    cout << endl;


    cout << "Послед. входных сигналов:    ";
    cout << setw(fieldWidth) << "--";
    for (const auto& signal :  sequence_input_signals)
    {   
        cout << setw(fieldWidth) << "x" << signal;
    }
    cout << endl;

    Vector sequence_output_signals;

    int start_state = 0;
    int number_state = 6;
    int number_output = 4;

    MuriMachine mura_machine(start_state, number_state, number_output);

    int state = mura_machine.GetState();

    sequence_output_signals.push_back(mura_machine.Output());

    cout << "Послед. состояний автомата: ";
    cout << setw(fieldWidth) << "z" << state;
    for (const auto& signal :  sequence_input_signals) {
        sequence_output_signals.push_back(mura_machine.Output());
        cout << setw(fieldWidth) << "z" << state;
        state = mura_machine.Transition(signal - 1);
    }
    cout << endl;

    cout << "Послед. выходных сигналов:  ";
     for (const auto& signal :  sequence_output_signals)
    {   
        cout << setw(fieldWidth) << "y" << signal;
    }
    cout << endl;
}