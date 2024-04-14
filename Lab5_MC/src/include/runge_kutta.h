#ifndef _RUNGE_KYTTA_
#define _RUNGE_KYTTA_

#include <vector>
#include <functional>
#include <list>

using List = std::list<double>;
using Vector = std::vector<double>;
using Matrix = std::vector<std::vector<double>>;
using PairErrorAndH = std::pair<std::vector<double>,std::vector<double>>;
using Func = std::function<std::vector<double>(std::vector<std::vector<double>>, std::vector<double>)>;

class RungeKutta 
{
private:
    Func functions;
    Vector params;
    Vector variables;
    Matrix m_matrix_intensity;
public:
    RungeKutta();
    RungeKutta(Func, Matrix, Vector);
    Matrix K1(Vector, double, double, double);
    Matrix Calculate(double, double, double);
};

#endif // _RUNGE_KYTTA_
