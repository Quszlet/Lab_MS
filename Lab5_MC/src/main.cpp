#include <iostream>
#include <iomanip>
#include <math.h>
#include "markov_process_ds_ct.h"

using std::cout;
using std::endl;

int main() {
    Matrix matrix_intensity = {
        {-0.3, 0.15, 0.1, 0.05},
        {0.0, -0.5, 0.3, 0.2},
        {0.0, 0.0, -0.7, 0.7},
        {0.0, 0.0, 0.0, -0.0}
    };

    MarkovProcessDsCt markov_process_ds_ct(matrix_intensity);

    double h = 1;
    double start = 0.0;
    double end = 35.0;

    auto result_probs_states = markov_process_ds_ct.calculateProbabiliteStates(h, start, end);

    auto res1 = result_probs_states[0];
    auto res2 = result_probs_states[1];
    auto res3 = result_probs_states[2];
    auto res4 = result_probs_states[3];
    cout << "Вычисление дифф. уравнений Колмогорова для вероятностей состояний:" << endl << endl;
    cout << std::setw(25) << "  " << "Сост. 1" << "  " << "Сост. 2" << "  " <<  "Сост. 3"  << "  " << "Сост. 4" << "  " << "Sum=1?" << endl;
    int wight_in_result = 3;
    double sum = 0;
    std::string isSum = "";
    for (int i = 0; i < res1.size(); i++)
    {
        sum = res1[i] + res2[i] + res3[i] + res4[i];
        isSum = (round(sum) == 1.0) ? "Да" : "Нет";
        cout << "Номер вектора значений " << i+1 << " : "; 

        cout << std::fixed <<  std::setprecision(4) << res1[i] << std::setw(wight_in_result) << " " << res2[i] << std::setw(wight_in_result) << " " << res3[i] << std::setw(wight_in_result) << " " << res4[i];
        cout << std::setw(wight_in_result) << " " << isSum;
        cout << endl;
    }
    cout << endl;

    cout << "Вычисление предельных вероятностей:" << endl << endl;

    auto result_probs_max = markov_process_ds_ct.calculateMaxProbability();
    cout << "Сост. 1" << "  " << "Сост. 2" << "  " <<  "Сост. 3"  << "  " << "Сост. 4" << endl;
    cout << std::fixed <<  std::setprecision(4) << -result_probs_max[0] << "  " << -result_probs_max[1] << "  " <<  -result_probs_max[2]  << "  " << result_probs_max[3] << endl;
}