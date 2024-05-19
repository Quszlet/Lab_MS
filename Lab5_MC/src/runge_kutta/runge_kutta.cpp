#include "runge_kutta.h"
#include <iostream>
#include <math.h>

RungeKutta::RungeKutta() {
   
}



RungeKutta::RungeKutta(Func functions, Matrix matrix_intensity, Vector variables) {
    this->functions = functions;
    this->variables = variables;
    this->m_matrix_intensity = matrix_intensity;
}



Matrix RungeKutta::K1(Vector variab, double h, double start, double end) {

    Matrix result(variab.size());
    Vector interval;

    double x1 = 0.0;

    result[0].push_back(1);
    result[1].push_back(0);
    result[2].push_back(0);
    result[3].push_back(0);
   

    while (start < end)
    { 
        Vector k(variab.size());
        Vector kp = functions(m_matrix_intensity, variab);
        for (int j = 0; j < k.size(); j++)
        {
            k[j] = k[j] + kp[j] * h;
            variab[j] += k[j];
            if (variab[j] < 0) {
                break;
            }
            result[j].push_back(variab[j]);
        }
        
        start += h;
        kp.clear();
        k.clear();
        
    }
    variab.clear();
    return result;
}

Matrix RungeKutta::Calculate(double h, double start, double end) {
    Vector vec_error, state_h, interval;
    double relative_error;
    Matrix y, new_y;   
    
    return K1(variables, h, start, end);;
}