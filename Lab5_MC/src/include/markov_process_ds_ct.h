#ifndef _MARKOV_PROCESS_DS_CT_
#define _MARKOV_PROCESS_DS_CT_

#include "runge_kutta.h"

using Vector = std::vector<double>;
using Func = std::function<std::vector<double>(Matrix, Vector)>;

class MarkovProcessDsCt
{
private:
    RungeKutta* m_runge_kutta;
    Func functions_diff;
    Matrix m_matrix_intensity;
    Vector states;
public:
    MarkovProcessDsCt(Matrix);
    ~MarkovProcessDsCt();
    Vector calculateMaxProbability();
    Matrix calculateProbabiliteStates(double, double, double); 
};

#endif // _MARKOV_PROCESS_DS_CT_