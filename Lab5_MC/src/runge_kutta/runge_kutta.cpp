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

    // auto iter_comp_x1 = comparison_x1.end();
    // auto iter_values_r = values_for_r.end();

    double x1 = 0.0;

   

    while (start < end)
    {
        // interval.push_back(start);

        // Vector k(variab.size());
        // x1 = variab[0];
        // iter_comp_x1 = --comparison_x1.end();
        // iter_values_r = --values_for_r.end();
        
        // while (x1 < *iter_comp_x1) {
        //     if (x1 < 0) {
        //         x1 = *comparison_x1.begin();
        //         params[0] = *values_for_r.begin();
        //         break;
        //     }
        //     --iter_comp_x1;
        //     --iter_values_r;
        // }
        
    

      
    
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
    // do
    // {
    //     y = K1(variables, h, start, end);
    //     new_y = K1(variables, h / 2.0, start, end);

    //         state_h.push_back(h);
        
    //     double new_x = new_y[0].back();
    //     double x = y[0].back();
    //     relative_error = abs((new_x - x) / new_x) * 100;

    //     vec_error.push_back(relative_error);
        
    //     h = h / 2.0;
    // } while (relative_error > acceptable);
    //std::cout << "H:" << h << std::endl;
    return K1(variables, h, start, end);;
}