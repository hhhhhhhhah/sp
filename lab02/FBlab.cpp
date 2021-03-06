#include "iostream"
#include "mlisp.h"

double half__interval__method(double a, double b);
double __FB__try(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double root (double a, double b);
double fun(double z);
extern const double tolerance;

double half__interval__method(double a, double b) {
    double a__value = 0.;
    double b__value = 0.;
    a__value = fun(a);
    b__value = fun(b);
    return((a__value < 0. || b__value > 0.) ? __FB__try(a,b)
    	: (a__value > 0. && b__value < 0.) ? __FB__try(b,a)
    	: (b + 1)); 
}

double __FB__try(double neg__point, double pos__point) {
    double midpoint = 0.;
    double test__value = 0.;
    midpoint = average(neg__point, pos__point);
    display("+");
    return (close__enough_Q(neg__point, pos__point) ? midpoint
        : true ? test__value = fun(midpoint),
    	    (test__value > 0.0) ? __FB__try(neg__point, midpoint)
            :(test__value < 0.0) ? __FB__try(midpoint, pos__point)
	        :  midpoint
            : _infinity);
}

bool close__enough_Q(double x, double y) {
    const double tolerance = 0.00001;
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
    //(temp - b - 1) == 0 ? display("[bad]"): display("[good]");
    display((temp - b - 1) == 0 ? "[bad]": "[good]");
    return temp;
}



double fun(double z) {
    z = z - 103.0/104.0 - 1.0/pi;
    return ( 4.0 * log(z) * log(z) + 6.0 * log(z) - 5.0);
}

int main() {
    display("FB variant 3\n");
    display(root(3.0,4.0));
    newline();
    return 0;
}



  
    
