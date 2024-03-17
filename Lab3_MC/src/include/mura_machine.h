#ifndef _MURA_MACHINE_H_
#define _MURA_MACHINE_H_

#include <vector>

using DoubleVector = std::vector<std::vector<int>>;
using Vector = std::vector<int>;

class MuriMachine
{
private:
    int number_states;
    int number_inputs;
    int state;
    DoubleVector trans;
    Vector out;
public:
    MuriMachine(int state, int number_states, int number_inputs);

    int transition(int signal);
    int output();
};

#endif // _MURA_MACHINE_H_