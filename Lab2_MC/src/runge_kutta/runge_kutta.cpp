#include "runge_kutta.h"
#include <iostream>
#include <math.h>

RungeKutta::RungeKutta(Func functions, Vector variables, Vector constants, Vector params) {
    this->constants = constants;
    this->functions = functions;
    this->variables = variables;
    this->params = params;
    this->comparison_x1 = {0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0, 3000.0, 3500.0, 4000.0, 4500.0, 5000.0, 5500.0, 6000.0, 6500.0, 7000.0, 7500.0, 8000.0, 8500.0, 9000.0, 9500.0, 10000.0};
    this->values_for_r = {0.015, 0.0135, 0.012, 0.0107, 0.0096, 0.0088, 0.0077, 0.0069, 0.0061, 0.0055, 0.0049, 0.0044, 0.0039, 0.0035, 0.0031, 0.0028, 0.0025, 0.0022, 0.002, 0.0018, 0.0016};
}



std::pair<DoubleVector, Vector> RungeKutta::K1(Vector variab, double h, double start, double end) {

    DoubleVector result(variab.size());
    Vector interval;

    auto iter_comp_x1 = comparison_x1.end();
    auto iter_values_r = values_for_r.end();

    double x1 = 0.0;

   

    while (start < end)
    {
        interval.push_back(start);

        Vector k(variab.size());
        x1 = variab[0];
        iter_comp_x1 = --comparison_x1.end();
        iter_values_r = --values_for_r.end();
        
        while (x1 < *iter_comp_x1) {
            if (x1 < 0) {
                x1 = *comparison_x1.begin();
                params[0] = *values_for_r.begin();
                break;
            }
            --iter_comp_x1;
            --iter_values_r;
        }
        
    

      
    
        params[0] = *iter_values_r;

        Vector kp = functions(variab, constants, params);
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
    return {result, interval};
}

std::pair<std::pair<DoubleVector, Vector> , PairErrorAndH> RungeKutta::Calculate(double h, double start, double end, double acceptable) {
    Vector vec_error, state_h, interval;
    double relative_error;
    DoubleVector y, new_y;   
    do
    {
        auto values_and_interval = K1(variables, h, start, end);
        y = values_and_interval.first;
        interval = values_and_interval.second;
        new_y = K1(variables, h / 2.0, start, end).first;

        state_h.push_back(h);
        
        double new_x = new_y[0].back();
        double x = y[0].back();
        relative_error = abs((new_x - x) / new_x) * 100;

        vec_error.push_back(relative_error);
        
        h = h / 2.0;
    } while (relative_error > acceptable);
    std::cout << "H:" << h << std::endl;
    return {{y, interval}, {vec_error, state_h}};
}