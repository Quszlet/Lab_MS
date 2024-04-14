#include <markov_process_ds_ct.h>
#include <cmath>
#include <limits>
#include <iostream>


MarkovProcessDsCt::MarkovProcessDsCt(Matrix matrix_intensity) {
    states = {1, 0, 0, 0};
    m_matrix_intensity = matrix_intensity;
    functions_diff = [](Matrix matrix_intensity, Vector states) {
        Vector diff_equals;
        double sum;
        for (int i = 0; i < matrix_intensity.size(); i++)
        {
            sum = 0;
            for (int j = 0; j < matrix_intensity[i].size(); j++)
            {
                double ds = matrix_intensity[j][i];
                double st = states[j];
                sum += matrix_intensity[j][i] * states[j];
            }
            diff_equals.push_back(sum);
        }
        

        return diff_equals;
    };
    m_runge_kutta = new RungeKutta(functions_diff, matrix_intensity, states);
}

Vector MarkovProcessDsCt::calculateMaxProbability() {
    Matrix A = {
        {m_matrix_intensity[0][0], m_matrix_intensity[1][0], m_matrix_intensity[2][0], m_matrix_intensity[3][0]},
        {m_matrix_intensity[0][1], m_matrix_intensity[1][1], m_matrix_intensity[2][1], m_matrix_intensity[3][1]},
        {m_matrix_intensity[0][2], m_matrix_intensity[1][2], m_matrix_intensity[2][2], m_matrix_intensity[3][2]},
        {1.0, 1.0, 1.0, 1.0},
    };
    int n = A.size();
    Vector b = {0.0, 0.0, 0.0, 1.0};
    Vector x = {1.0, 0.0, 0.0, 0.0};
    Vector new_x(n);
    double norm;

    for (int iteration = 0; iteration < 1000; ++iteration) {
        for (int i = 0; i < n; ++i) {
            new_x[i] = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    new_x[i] -= A[i][j] * x[j];
                }
            }
            new_x[i] /= A[i][i];
        }

        // Проверка на сходимость
        norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += (x[i] - new_x[i]) * (x[i] - new_x[i]);
        }

        if (sqrt(norm) < 1e-10) {
            break;
        }

        x = new_x;
    }
    
    return x;
}

Matrix MarkovProcessDsCt::calculateProbabiliteStates(double h, double start, double end) {
    return m_runge_kutta->Calculate(h, start, end);
}

MarkovProcessDsCt::~MarkovProcessDsCt() {
    delete m_runge_kutta;
}