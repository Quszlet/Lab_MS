#include <sciplot/sciplot.hpp>
#include <vector>
#include <iostream>
#include <iomanip>
#include "runge_kutta.h"

using sciplot::Vec;

Vector functions_3order(Vector variables, Vector constants, Vector params);

int main() {
    Vector variables = {0.0, 0.0, 1000.0};
    Vector constants = {8000.0, 20.0, 9.81};
    Vector params = {0.015};
    double x0 = 0.0;
    double x = 13.0;
    double h = 0.1;
    // std::cout << std::setw(20) << "x1 " << std::setw(20) << "x2 " << std::setw(20) << "x3 " << std::endl;

    
    RungeKutta runge_kutta(functions_3order, variables, constants, params);
   
    auto y = runge_kutta.Calculate(h, x0, x, 0.01);


    Vector y1 = y.first.first[0];
    Vector y2 = y.first.first[1];
    Vector y3 = y.first.first[2];

    // for (int i = 0; i < y1.size(); i++)
    // {
    //     std::cout << std::setw(20) << y1[i];
    //     std::cout << std::setw(20) << y2[i];
    //     std::cout << std::setw(20) << y3[i] << std::endl;
    // }
    
    
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

