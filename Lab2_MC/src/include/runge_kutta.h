#ifndef _RUNGE_KYTTA_
#define _RUNGE_KYTTA_

#include <vector>
#include <functional>
#include <list>

using List = std::list<double>;
using Vector = std::vector<double>;
using DoubleVector = std::vector<std::vector<double>>;
using PairErrorAndH = std::pair<std::vector<double>,std::vector<double>>;
using Func = std::function<std::vector<double>(std::vector<double>, std::vector<double>, std::vector<double>)>;

class RungeKutta 
{
private:
    Func functions;
    Vector params;
    Vector variables;
    Vector constants;
    List comparison_x1; 
    List values_for_r;
public:
    RungeKutta(Func, Vector, Vector, Vector);
    std::pair<DoubleVector, Vector> K1(Vector, double, double, double);
    std::pair<std::pair<DoubleVector, Vector> , PairErrorAndH> Calculate(double, double, double, double);
};

#endif // _RUNGE_KYTTA_
