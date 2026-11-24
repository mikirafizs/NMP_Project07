#pragma once

#include <cmath>
#include <fstream>
#include <iostream>


const int itmax = 30;
const double epsilon = 1.0e-12;

inline double f(double x){ return (x-1)*std::pow((x-3), 6); }
inline double df(double x){ return std::pow((x-3), 5)*(7*x-9); } //calculated by hand

inline void bisection_method(double a, double b){
    int k = 0;
    double delta_abs;
    double x_solution;

    std::ofstream bisection("../data/bisection.csv");
    if(!bisection.is_open()){
        std::cerr << "Cannot open bisection file.\n";
    }

    do{
        k = k + 1;
        double c = a + (b-a)/2;
        
        if(f(a)*f(c) < 0){
            b = c;
        }else{
            a = c;
        }

        x_solution = c;
        double delta = a-b;
        delta_abs = std::abs(a-b);
        double residual = f(x_solution);
        double bracket_width = b-a;

        bisection << k <<", " << x_solution << ", " << delta << ", " << delta_abs << ", " << residual << ", " << bracket_width << "\n";

        
    }while (k < itmax && delta_abs > epsilon);
    
    if(k == itmax){
        std::cout << "Bisection method terminated by itmax.\n";
    }else{
        std::cout << "Bisection method terminated by epsilon criterion.\n";
    }

    bisection.close();
}

inline void secant_method(double a, double b){
    int k = 0;
    double c;
    double delta_abs;
    double x_solution;

    std::ofstream secant("../data/secant.csv");
    if(!secant.is_open()){
        std::cerr << "Cannot open secant file.\n";
    }

    do{
        k = k + 1;
        if(f(b)-f(a) == 0){
            std::cerr << "Division by zero in secant method.";
            exit(-1);
        }
        c = b - f(b)*((b-a)/(f(b)-f(a)));

        a = b;
        b = c;

        delta_abs = std::abs(b-a);
        x_solution = b;
        double delta = b-a;
        double residual = f(x_solution);

        secant << k <<", " << x_solution << ", " << delta << ", " << delta_abs << ", " << residual << "\n";

    }while(k < itmax && delta_abs > epsilon);

    if(k == itmax){
        std::cout << "Secant method terminated by itmax.\n";
    }else{
        std::cout << "Secant method terminated by epsilon criterion.\n";
    }

    secant.close();
}

inline void newton_method(double x){
    int k = 0;
    double delta_abs;

    std::ofstream newton("../data/newton.csv");
    if(!newton.is_open()){
        std::cerr << "Cannot open newton file.\n";
    }

    do{
        k = k + 1;
        if(df(x) == 0){
            std::cerr << "Division by zero in newton method.";
            exit(-1);
        }
        double x_1 = x - (f(x)/df(x));

        delta_abs = std::abs(x - x_1);
        double delta = x_1-x;
        double residual = f(x_1);
        x = x_1;

        newton << k <<", " << x << ", " << delta << ", " << delta_abs << ", " << residual << "\n";

    }while(k < itmax && delta_abs > epsilon);

    if(k == itmax){
        std::cout << "Newton method terminated by itmax.\n";
    }else{
        std::cout << "Newton method terminated by epsilon criterion.\n";
    }

    newton.close();
}