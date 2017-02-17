#include "mlisp.h"
const double tolerance = 0.00001;
double half__interval__method(double a, double b);
double FBtry(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double root (double a, double b);
double fun(double z);

double half__interval__method(double a, double b) {
    double a__value = 0.;
    double b__value = 0.;
    a__value = fun(a);
    b__value = fun(b);
    return((a__value > 0. || b__value < 0.) ? FBtry(a,b)
    : (a__value < 0. && b__value > 0.) ? FBtry(b,a)
    : b + 1.); 
}

double FBtry(double neg__point, double pos__point) {
    double midpoint = 0.;
    double test__value = 0.;
    midpoint = average(neg__point, pos__point);
    display("+");
    (close__enough_Q(neg__point, pos__point) ? midpoint,
        : true ? test__value = fun(midpoint),
            (test__value > 0.0 ? FBtry(neg__point, midpoint)
            : _infinity)
            (test__value < 0.0 ? FBtry(midpoint, pos__point)
            : _infinity))
}

bool close__enough_Q(double x, double y) {
    return(abs(x - y) < tolerance);
}

double average(double x, double y) {
    return((x+y)/2.0);
}

double root (double a, double b) {
    double temp = 0.0;
    temp = half__interval__method(a, b);
    newline();
    display("interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("discrepancy=\t");
    display(fun(temp)); newline();
    display("root=\t\t");
    (temp - b - 1) == 0 ? display("[bad]"), display("[good]")
    return temp;
}



double fun(double z) {
    z = z - 103.0/104.0 - 1.0/pi;
    return ( 4.0 * log(z) * log(z) + 6.0 * log(z) - 5.0);
}

int main() {
    root(3.0,4.0);
    return 0;
}



  
    