#include "mura_machine.h"

// 36 вариант

// 5 входов
// 6 состояний
// 4 выхода

MuriMachine::MuriMachine(int state, int number_states, int number_inputs) {
    this->state = state;
    this->number_states = number_states;
    this->number_inputs = number_inputs;
    this->trans = {
         // 0  1  2  3  4
        {0, 4, 1, 2, 3}, // Состояние 0
        {1, 0, 2, 3, 4}, // Состояние 1
        {2, 0, 3, 4, 0}, // Состояние 2
        {3, 1, 4, 0, 0}, // Состояние 3
        {4, 2, 0, 0, 1}, // Состояние 4
        {0, 3, 0, 1, 2}  // Состояние 5
    };
    this->out = {0, 1, 3, 2};
}

int MuriMachine::transition(int signal) {
    return trans[state][signal];
}

int MuriMachine::output() {
    return state;
}