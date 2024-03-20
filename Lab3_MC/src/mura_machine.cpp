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
        {1, 5, 2, 3, 4}, // Состояние 0
        {2, 0, 3, 4, 5}, // Состояние 1
        {3, 1, 4, 5, 0}, // Состояние 2
        {4, 2, 5, 0, 1}, // Состояние 3
        {5, 3, 0, 1, 2}, // Состояние 4
        {0, 4, 1, 2, 3}  // Состояние 5
    };
    this->out = {0, 1, 3, 2, 0, 3};
}

int MuriMachine::Transition(int signal) {
    state = trans[state][signal];
    return state;
}

int MuriMachine::Output() {
    return out[state];
}

int MuriMachine::GetState() {
    return state;
}