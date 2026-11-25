#include "root.hpp"



const double x_a = 0.1;
const double x_bis = 1.5;
const double x_bsec = 0.5;


int main(){
    bisection_method(x_a, x_bis);
    secant_method(x_a, x_bsec);
    newton_method(x_a);
    return 0;
}