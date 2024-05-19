#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::map;
using std::swap;
using std::string;
using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

Vector lineSolve(Matrix matrix, Vector b);
unsigned long long factorialRecursive(int n);

int main() {
    int quanitity_smo = 5; // количество СМО

    map<string, int> channels_in_smo; // кол-во каналов в каждой СМО
    channels_in_smo["K1"] = 1;
    channels_in_smo["K2"] = 2;
    channels_in_smo["K3"] = 2;
    channels_in_smo["K4"] = 1;
    channels_in_smo["K5"] = 2;

    Matrix transfer_probabilities = { // матрица вероятностей передач
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0.86, 0, 0.14, 0},
        {0, 0.2, 0, 0.8, 0, 0},
        {0, 0, 0, 0, 0.1, 0.9},
        {0, 0, 0.08, 0, 0, 0},
        {0.95, 0, 0, 0, 0.05, 0}
    };

    double requisition_rate = 4; // интенсивность источника заявок
    double average_service_time = 0.5; // cреднее длительность обслуживания заявок(для всех СМО)

    cout << "Характеристики разомкутой стохастической сети:" << endl << endl; 
    cout << "Число n СМО S1,...,Sj, образующих сеть - " << quanitity_smo << endl << endl;

    cout << "Число каналов K1,...,Kn, входящих в СМО S1...Sj:" << endl;

    for (const auto& [channel_smo, quanitity] : channels_in_smo) {
        cout << "\t- " << channel_smo << " = " << quanitity << endl;
    }
    cout << endl;
        
    cout << "Матрица вероятности передач: " << endl;
    for (int i = 0; i < transfer_probabilities.size(); i++)
    {
        cout << "\t";
        for (int j = 0; j < transfer_probabilities[i].size(); j++)
        {
            cout << std::setw(4) << transfer_probabilities[i][j] << " ";
        }
        cout << endl;
    }
     cout << endl;
    
    cout << "Интенсивность λ0 источника заявок S0 - " << requisition_rate << endl << endl;
    
    cout << "Среднее длительность обслуживания заявок - " << average_service_time << endl << endl;

    transfer_probabilities = { // матрица вероятностей передач
    //  s1  s2   s3   s4  s5
        {-1.0, 0.2, 0.0, 0.0, 0.0},
        {0.86, -1.0, 0.0, 0.08, 0.0},
        {0.0, 0.8, -1.0, 0.0, 0.0},
        {0.14, 0.0, 0.1, -1.0, 0.05},
        {0.0, 0.0, 0.9, 0.92, -1.0}
    };

    Vector ky = {1.0, 0.0, 0.0, 0.0, 0.0}; 

    cout << "Относительные коэффициенты передачи от входа системы к узлам: " << endl;
    Vector a = lineSolve(transfer_probabilities, ky);
    for (int i = 0; i < a.size(); i++)
    {
        cout << "\t- a" << i+1 << " = " << a[i] << endl;
    }
    cout << endl;
    
    // Входящие потоки заявок в систему
    Vector lambda;
    for (int i = 0; i < a.size(); i++)
    {
        lambda.push_back(a[i] * requisition_rate);
    }
    
    // Загрузка систем СМО и среднее количество занятых каналов
    Vector p;
    Vector k;
    int j = 0;
    for (const auto& [channel_smo, quanitity] : channels_in_smo)
    {
        k.push_back(lambda[j] * average_service_time);
        if (quanitity == 1) {
            p.push_back(lambda[j] * average_service_time);
        } else {
            p.push_back((lambda[j] * average_service_time / quanitity));
        }
        j++;
    }

     cout << "Среднее количество занятых каналов в СМО: " << endl;
    for (int i = 0; i < k.size(); i++)
    {
        cout << "\t- k" << i+1 << " = " << k[i] << endl;
    }
     cout << endl;

    cout << "Загрузка систем СМО: " << endl;
    for (int i = 0; i < p.size(); i++)
    {
        cout << "\t- p" << i+1 << " = " << p[i] << endl;
    }
     cout << endl;

    // Проверка стационарности СМО
    bool isStationary = true;
    cout << "Стационарность СМО: " << endl;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] < 1) {
            cout << "\t- СМО S" << i+1 << " стационарна " << endl;
        } else {
            cout << "\t- СМО S" << i+1 << " не стационарна " << endl;
            isStationary = false;
        }
    }
    cout << endl;
    
    if (isStationary) {
        cout << "СМО в целом стационарна " << endl << endl;
    } else {
        cout << "СМО в целом не стационарна " << endl << endl;
    }

    cout << "Вводим СМО в стационарный режим" << endl << endl;

    // Преобразование в режим стационарности
    j = 0;
    int divider = 2;
    isStationary = true;
    while(true) {
        for (const auto& [channel_smo, quanitity] : channels_in_smo)
        {
            if (p[j] > 1) {
                p[j] = (lambda[j] * (average_service_time / divider) / quanitity);
                k[j] = lambda[j] * (average_service_time / divider);
                if (p[j] > 1) {
                    isStationary = false;
                } 
            } 
            j++;
        }

        if (isStationary) {
            break;
        }
        isStationary = true;
        divider++;
        j = 0;
    }

    // Проверка стационарности СМО
    
    cout << "Стационарность СМО: " << endl;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] < 1) {
            cout << "\t- СМО S" << i+1 << " стационарна " << p[i] << endl;
        } else {
            cout << "\t- СМО S" << i+1 << " не стационарна " << p[i] << endl;
            isStationary = false;
        }
    }
    cout << endl;
    
    if (isStationary) {
        cout << "СМО в целом стационарна " << endl << endl;
    } else {
        cout << "СМО в целом не стационарна " << endl << endl;
    }

    // Вероятности простоя каждой СМО
    double left_operand = 0.0;
    double right_operand = 0.0;
    j = 0;
    Vector P0;
    for (const auto& [channel_smo, quanitity] : channels_in_smo)
    {
        for (int i = 0; i < quanitity; i++)
        {
            left_operand += pow((k[j] / factorialRecursive(i)), i);
        }
        
        right_operand += pow(k[j], quanitity) / (factorialRecursive(k[j]) * (1 - k[j]/ quanitity));
        P0.push_back(left_operand + right_operand);
        j++;
    }
    
    cout << "Вероятности простоя каждой СМО" << endl;
    for (int i = 0; i < P0.size(); i++)
    {
        cout << "\t- p" << i+1 << " = " << p[i] << endl;
    }
    cout << endl;

    // Средняя длина очереди заявок для каждой СМО
    Vector L;
    j = 0;
    for (const auto& [channel_smo, quanitity] : channels_in_smo)
    {
        if (quanitity == 1) {
            L.push_back(pow(p[j], 2) / (1 - p[j]));
        } else {
            L.push_back((pow(k[j], quanitity + 1) / (factorialRecursive(quanitity) * quanitity * (1 - k[j] / quanitity)))); // !!!
        }
        j++;
    }

    cout << "Средняя длина очереди заявок для каждой СМО" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        cout << "\t- l" << i+1 << " = " << L[i] << endl;
    }
    cout << endl;

    // Среднее число заявок в каждой СМО
    Vector m;
    for (int i = 0; i < a.size(); i++)
    {
        m.push_back(L[i] + k[i]);
    }

    cout << "Среднее число заявок в каждой СМО" << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << "\t- m" << i+1 << " = " << m[i] << endl;
    }
    cout << endl;

    // Среднее время ожидания заявки в очереди систем
    Vector w;
    for (int i = 0; i < a.size(); i++)
    {
        w.push_back(L[i] / lambda[i]);
    }

    cout << "Среднее время ожидания заявки в очереди систем" << endl;
    for (int i = 0; i < w.size(); i++)
    {
        cout << "\t- w" << i+1 << " = " << w[i] << endl;
    }
    cout << endl;

    // Среднее время пребывания заявки в системе Sj
    Vector t;
    for (int i = 0; i < a.size(); i++)
    {
        t.push_back(m[i] / lambda[i]);
    }

    cout << "Среднее время пребывания заявки в системе Sj" << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << "\t- t" << i+1 << " = " << t[i] << endl;
    }
    cout << endl;

    double L_sum = 0.0;
    double N = 0.0;
    double W = 0.0;
    double T = 0.0;

    for (int i = 0; i < a.size(); i++)
    {
        L_sum += L[i];
        N += m[i];
        W = a[i] * w[i];
        T = a[i] * t[i];
    }

    cout << "Характеристики для всей системы в целом ->" << endl;
    cout << "Cредняя длина очереди: " << L_sum << endl;
    cout << "Cредняя число заявок: " << N << endl;
    cout << "Cредняя время ожидания в очередях: " << W << endl;
    cout << "Cредняя время пребывания заявки в сети: " << T << endl;
}

unsigned long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

Vector lineSolve(Matrix matrix, Vector b) {
    int n = matrix.size();

    for (double& el : b) {
        el = -el;
    }

   // Прямой ход
    for (int i = 0; i < n; ++i) {
        // Поиск максимального элемента в столбце
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Поменять местами текущую строку с строкой с максимальным элементом
        for (int k = i; k < n; ++k) {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        swap(b[maxRow], b[i]);

        // Обнуление элементов ниже текущего
        for (int k = i + 1; k < n; ++k) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
            b[k] += c * b[i];
        }
    }

    // Обратный ход
    Vector x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i] / matrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            b[k] -= matrix[k][i] * x[i];
        }
    }
    return x;
}