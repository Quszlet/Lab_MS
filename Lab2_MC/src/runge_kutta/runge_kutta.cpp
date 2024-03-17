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

Vector RungeKutta::ValuesForK2(Vector k1, double h) {
    Vector values;
    for (int i = 0; i < k1.size(); i++)
    {
        values.push_back(variables[i] + h / 2 * k1[i]);
    }
    return values;
}

Vector RungeKutta::ValuesForK3(Vector k2, double h) {
    Vector values;
    for (int i = 0; i < k2.size(); i++)
    {
        values.push_back(variables[i] + h / 2 * k2[i]);
    }
    return values;
    
}

Vector RungeKutta::ValuesForK4(Vector k3, double h) {
    Vector values;
    for (int i = 0; i < k3.size(); i++)
    {
        values.push_back(variables[i] + h * k3[i]);
    }
    return values;
    
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

DoubleVector RungeKutta::K4(double h, double start, double end) {
    Vector k(variables.size()), k1, k2, k3, k4;
    DoubleVector result(k.size());

    auto iter_comp_x1 = comparison_x1.end();
    auto iter_values_r = values_for_r.end();

    double x1 = 0.0;

    //std::cout << "In" << std::endl;

    while (start < end)
    {
        x1 = variables[0];
        iter_comp_x1 = --comparison_x1.end();
        iter_values_r = --values_for_r.end();
        
        while (x1 < *iter_comp_x1) {
            // std::cout  << "X1: " << x1 << " Iter: " <<*iter_comp_x1 << std::endl;
            if (x1 < 0) {
                x1 = *comparison_x1.begin();
                params[0] = *values_for_r.begin();
                break;
            }
            --iter_comp_x1;
            --iter_values_r;
        }
        
    

        // std::cout << "X1: " << x1 << std::endl;  
        // std::cout << "Posle Iter x1: " << *iter_comp_x1 << std::endl; 
        // std::cout << "Posle Iter r: " << *iter_values_r << std::endl;
    
        params[0] = *iter_values_r;

        k1 = functions(variables, constants, params);
        k2 = functions(ValuesForK2(k1, h), constants, params);
        k3 = functions(ValuesForK3(k2, h), constants, params);
        k4 = functions(ValuesForK4(k3, h), constants, params);

        for (int j = 0; j < k.size(); j++)
        {
            k[j] += (h * (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])) / 6;
            variables[j] += k[j];
            if (isinf(variables[j])) {
                return result;
            }
            result[j].push_back(variables[j]);
        }

        start += h;

        //std::cout << "Start:" << start << std::endl; 
    }
    
    return result;
}

std::pair<std::pair<DoubleVector, Vector> , PairErrorAndH> RungeKutta::CalculateK4(double h, double start, double end, double acceptable) {
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

    return {{y, interval}, {vec_error, state_h}};
}