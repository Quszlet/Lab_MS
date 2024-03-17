// #include <sciplot/sciplot.hpp>
// #include <vector>
// #include <iostream>
// #include <iomanip>

// using sciplot::Vec;

// std::vector<double> functions_3order(double x1, double x2, double x3, double c, double u, double g, double r);

// int main() {
//     double x1 = 0.0;
//     double x2 = 0.0;
//     double x3 = 1000.0;
//     double c = 8000.0;
//     double u = 20.0;
//     double g = 9.81;
//     double r = 0.015;
//     double x0 = 0.0;
//     double x = 13.0;
//     double h = 0.1;

//     std::cout << std::setw(20) << "x1 " << std::setw(10) << "x2 " << std::setw(10) << "x3 " << std::endl;

//     std::cout << std::setw(20) << x1;
//     std::cout << std::setw(20) << x2;
//     std::cout << std::setw(20) << x3 << std::endl;


//     int steps = x / h;

//     // Runge-Kutta 1K
//     //std::vector<double> y;

//     // Runge-Kutta 4K
//     std::vector<double> k(3), k1, k2, k3, k4, y1, y2, y3;
//     for (int i = 0; i < steps; i++)
//     {
//         // Runge-Kutta 1K
//         // y = functions_3order(x1, x2, x3, c, u, g, r);

//         // x1 += y[0] * h;
//         // x2 += y[1] * h;
//         // x3 += y[2] * h;

//         // Runge-Kutta 4K

//         k1 = functions_3order(x1, x2, x3, c, u, g, r);
//         k2 = functions_3order(x1 + h/2 * k1[0], x2 + h/2 * k1[1], x3 + h/2 * k1[2], c, u, g, r);
//         k3 = functions_3order(x1 + h/2 * k2[0], x2 + h/2 * k2[1], x3 + h/2 * k2[2], c, u, g, r);
//         k4 = functions_3order(x1 + h * k3[0], x2 + h * k3[1], x3 + h * k3[2], c, u, g, r);

//         for (int j = 0; j < k.size(); j++)
//         {
//             k[j] += (h * (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])) / 6;
//         }
        
//         x1 += k[0];
//         x2 += k[1];
//         x3 += k[2];

//         y1.push_back(x1);
//         y2.push_back(x2);
//         y3.push_back(x3);


//         std::cout << std::setw(20) << x1;
//         std::cout << std::setw(20) << x2;
//         std::cout << std::setw(20) << x3 << std::endl;
//     }
    
//     // Vec y1_(y1.data(), y1.size());
//     // Vec y2_(y2.data(), y2.size());
//     // Vec y3_(y3.data(), y3.size());

//     sciplot::Plot2D plot;

//     Vec x_1 = {0.00, 0.16, 0.32, 0.48, 0.64, 0.80, 0.96, 1.12, 1.28, 1.44, 1.60, 1.76, 1.92, 2.08, 2.24, 2.40, 2.56, 2.72, 2.88, 3.04, 3.20, 3.36, 3.52, 3.68, 3.84, 4.00, 4.16, 4.32, 4.48, 4.64, 4.80, 4.96, 5.12, 5.28, 5.44, 5.60, 5.76, 5.92, 6.08, 6.24, 6.40, 6.56, 6.72, 6.88, 7.04, 7.20, 7.36, 7.52, 7.68, 7.84, 8.00, 8.16, 8.32, 8.48, 8.64, 8.80, 8.96, 9.12, 9.28, 9.44, 9.60, 9.76, 9.92, 10.08, 10.24, 10.40, 10.56, 10.72, 10.88, 11.04, 11.20, 11.36, 11.52, 11.68, 11.84, 12.00, 12.16, 12.32, 12.48, 12.64, 12.80, 12.96, 13.12, 13.28, 13.44, 13.60, 13.76, 13.92, 14.08, 14.24, 14.40, 14.56, 14.72, 14.88, 15.04, 15.20, 15.36, 15.52, 15.68, 15.84, 16.00};
//     // Set the width and height of the plot in points (72 points = 1 inch)
//     plot.size(1000, 1000);

//     // Set the font name and size
//     plot.fontName("Palatino");
//     plot.fontSize(12);

//     // Set the x and y labels
//     plot.xlabel("x");
//     plot.ylabel("y");

//     // Set some options for the legend
//     plot.legend()
//         .atOutsideTop()
//         .fontSize(10)
//         .displayHorizontal()
//         .displayExpandWidthBy(2); 
    
//      // Plot the Bessel functions
//     plot.drawCurve(x_1, y1).label("y1");
//     plot.drawCurve(x_1, y2).label("y2");
//     plot.drawCurve(x_1, y3).label("y3");
    
//      // Create figure to hold plot
//     sciplot::Figure fig = {{plot}};
//     // Create canvas to hold figure
//     sciplot::Canvas canvas = {{fig}};

//     // Show the plot in a pop-up window
//     canvas.show();
// }

// std::vector<double> functions_3order(double x1, double x2, double x3, double c, double u, double g, double r) {
//     return std::vector<double>{x2, (c * u) / x3 - g - (r * x2 * x2) / x3, -u};
// }

#include <sciplot/sciplot.hpp>
#include <vector>
#include <iostream>
#include <iomanip>
#include "runge_kutta.h"

using sciplot::Vec;

Vector functions_3order(Vector variables, Vector constants, Vector params);

int main() {
    // double x1 = 0.0;
    // double x2 = 0.0;
    // double x3 = 1000.0;
    // double c = 8000.0;
    // double u = 20.0;
    // double g = 9.81;
    // double r = 0.015;
    Vector variables = {0.0, 0.0, 1000.0};
    Vector constants = {8000.0, 20.0, 9.81};
    Vector params = {0.015};
    double x0 = 0.0;
    double x = 13.0;
    double h = 0.1;

    std::cout << std::setw(20) << "x1 " << std::setw(20) << "x2 " << std::setw(20) << "x3 " << std::endl;

    // std::cout << std::setw(20) << x1;
    // std::cout << std::setw(20) << x2;
    // std::cout << std::setw(20) << x3 << std::endl;

    
    RungeKutta runge_kutta(functions_3order, variables, constants, params);
   
    auto y = runge_kutta.CalculateK4(h, x0, x, 0.01);


    Vector y1 = y.first.first[0];
    Vector y2 = y.first.first[1];
    Vector y3 = y.first.first[2];

    for (int i = 0; i < y1.size(); i++)
    {
        std::cout << std::setw(20) << y1[i];
        std::cout << std::setw(20) << y2[i];
        std::cout << std::setw(20) << y3[i] << std::endl;
    }
    
    
    sciplot::Plot2D plot1, plot2;

   

    Vector H = y.second.second;
    Vector Error = y.second.first;
    Vector interval = y.first.second;
    

    plot1.size(1000, 1000);
    plot2.size(1000, 1000);


    // Set the font name and size
    plot1.fontName("Palatino");
    plot1.fontSize(12);

    plot2.fontName("Palatino");
    plot2.fontSize(12);

    // Set the x and y labels
    plot1.xlabel("T");
    plot1.ylabel("X");

    plot2.xlabel("Размер шага");
    plot2.ylabel("Погрешность %");

    // Set some options for the legend
    plot1.legend()
        .atOutsideTop()
        .fontSize(10)
        .displayHorizontal()
        .displayExpandWidthBy(2);

    plot2.legend()
        .atOutsideTop()
        .fontSize(10)
        .displayHorizontal()
        .displayExpandWidthBy(2);
    
     // Plot the Bessel functions
    plot1.drawCurve(interval, y1).label("x1");
    plot1.drawCurve(interval, y2).label("x2");
    plot1.drawCurve(interval, y3).label("x3");
    
    
   
    plot2.xrange(h, 0.0);
    plot2.drawCurve(H, Error).label("H");


    sciplot::Figure fig = {{plot1, plot2}};
   
    sciplot::Canvas canvas = {{fig}};

    canvas.size(1000, 1000);
    
    canvas.show(); 
}

Vector functions_3order(Vector variables, Vector constants, Vector params) {
    double x1 = variables[0];
    double x2 = variables[1];
    double x3 = variables[2];
    double c = constants[0];
    double u = constants[1];
    double g = constants[2];
    double r = params[0];

    return {x2, ((c * u) / x3) - g - ((r * x2 * x2) / x3), -u};
}

