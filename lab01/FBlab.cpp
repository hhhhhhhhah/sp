#include "mlisp.h"

double FBsquare(double x);
double smallest__divisor(double n);
double find__divisor(double n, double test__divisor);
bool divides_Q(double a, double b);
bool prime_Q(double n);

double FBsquare(double x) {
    return x*x;
}

double smallest__divisor(double n) {
    return find__divisor(n, 2);
}

double find__divisor(double n, double test__divisor) {
    return (FBsquare(test__divisor) > n ? n
    : divides_Q(test__divisor, n) ? test__divisor
    : find__divisor(n, test__divisor + 1));
}      
    
bool divides_Q(double a, double b) {
    return (remainder(b, a) == 0);
}

bool prime_Q(double n) {
    return(smallest__divisor(n) == n);
}

int main() {
    display(prime_Q(2)); 
    newline();
    display(prime_Q(4)); 
    newline();
    display(prime_Q(7)); 
    newline();
}
