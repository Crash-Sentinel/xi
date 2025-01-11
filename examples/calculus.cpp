
// Ensure correct file path
#include "./../include/main.h" // <- (The Path to main.h, which includes everything)
/*
can use just:
#include "./../include/derivative.h" <- (The Path to derivative.h)
#include "./../include/integral.h" <- (The Path to integral.h)
for example for less loading of other data structures and algorithms
*/

#include <iostream>

// Use double / long double or similar types for accuracy
double x_squared(double x); // Function Prototype

int main () 
{
    const int A = 0;
    const int B = 2;
    
    // The Definite Derivative of x_squared at B (the value 2)
    std::cout << xi_derivative::definite_derivative(x_squared, B) << std::endl; // 4

    // The Definite Integral of x_squared from A (the value 0) to B (the value 2)
    std::cout << xi_integral::definite_integral(x_squared, A, B) << std::endl; // 2.6667

    return 0;
}

double x_squared(double x) // Function Definition
{
    return x * x;
}