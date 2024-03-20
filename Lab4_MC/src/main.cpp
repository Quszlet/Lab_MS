#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using DoubleVector = std::vector<std::vector<double>>;
using Vector = std::vector<double>;


// 36 вариант
// Y-детерминированный Мили - выходной сигнал определяется детерменированно
// Мили - y[n] = f(z[n], x[n])
// при формировании выходного сигнала учитывается текущее состояние и входной сигнал

int determine_initial_state(const double& number, const Vector& c) {
    if (number < c[0]) 
    {
        return 0;
    }
    
    for (int i = 0, j = 1; j < c.size(); i++, j++)
    {
        double fs = c[i];
        double sf = c[i] + c[j];
        if (c[i] < number && number < (c[i] + c[j])) 
        {
            return i + 1;
        }
    }
    
    return c.size() - 1;
}

int determine_next_state(const double& number, const int& index_state, const DoubleVector& A) {
    if (number < A[index_state][0]) 
    {
        return 0;
    }
    
    for (int i = 0, j = 1; j < A[index_state].size(); i++, j++)
    {
        double fs = A[index_state][i];
        double sf = A[index_state][i] +A[index_state][j];
        if (A[index_state][i] < number && number < (A[index_state][i] +A[index_state][j])) 
        {
            return i + 1;
        }
    }
    
    return A[index_state].size() - 1;
    
}


int main() {
    int n = 1; // входной алфавит из 1-го символа 
    int m = 3; // выходной алфвавит из 3-х символов
    int p = 3; // количество состояний
    std::vector<string> states = {"a", "b", "c"};
    std::vector<string> input_words = {"1"};
    std::vector<string> output_words = {"m", "n", "k"};

    int field_width = 15; 
    cout << "x" << setw(field_width) << "z_old"
    << setw(field_width) << "r_1" << setw(field_width) << "z_new" 
    << setw(field_width) << "y" << endl;

    DoubleVector A = {
        {0.2, 0.6, 0.2},
        {1.0, 0.0, 0.0},
        {0.3, 0.5, 0.2}
    };

    Vector C = {0.1, 0.5, 0.4};

    std::random_device rd;  // Используется для получения случайного seed
    std::mt19937 gen(rd()); // Генератор случайных чисел (Mersenne Twister алгоритм)
    std::uniform_real_distribution<> dis(0.0, 1.0); 

    cout << std::fixed << std::setprecision(2);

    int index_state = determine_initial_state(dis(gen), C);
    
    double r_1, r_2;
    for (int i = 0; i < 5; i++)
    {
        cout << input_words[0];
        cout << setw(field_width) << states[index_state];

        r_1 = dis(gen);

        cout << setw(field_width) << r_1;

        index_state = determine_next_state(r_1, index_state, A);

        cout << setw(field_width) << states[index_state];

        cout << setw(field_width) << output_words[index_state];

        cout << endl;
    }
    
}