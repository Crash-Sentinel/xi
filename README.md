# XI - Ξ
<img width="19" alt="image" src="https://github.com/user-attachments/assets/a07cbc7a-3bb8-4041-b535-c471fc81cc4a">

Calculus and Linear Algebra based C++ Library

## What is Xi? Why create it?

I chose Xi after the 14th letter of the greek alphabet, it is a personal favorite letter of mine and doesn't seem to get much recognition or love from the math community, so I decided to give this library its name. The more formal pronounciation of it is more of a "[KS-I]" sound but personally I don't mind if you pronounce it differently or the such.

As to why I decided to create a Linear Algebra and Calculus Library, I didn't notice many people really creating a library for C++ like this, so I decided why not myself to do so? Thus, Xi was created.

## Example Usage

Using xi_integral and xi_derivative to calculate the respective area under the X squared curve from 0 to 2 and the derivative of the same function at x=2
Similar Driver Program is in examples directory

```
// Ensure correct file path
#include "include/main.h"
/*
can use just:
#include "include/derivative.h"
#include "include/integral.h"
for example for less loading of other functions
*/

#include <iostream>

// Use double / long double or similar types for accuracy, otherwise values may be incorrect
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
```

## General Documentation:

Enhanced Derivative behavior:
- Uses the Five-point stencil formula and Richardson Extrapolation to determine the definite derivative

Five Stencil Formula:
> f'(x) = -f(x+2h) + 8f(x-h) - 8f(x-h) + f(x-2h) / 12h

Pseudocode for better understanding:
- Take h = 3.29272e-10 (about 3.3e-10), find f'(x) = A (given that x is an argument passed)
- Half h, find new f'(x) = B
- Answer = (16 * B - A) / 15;

## Future Updates:

- Actually getting some Linear Algebra into here
- Sprucing up the integral and derivative code to be both more diverse in their methods and more optimized
- Fixing up matrix.h to be fully functional
- Providing more value to array.h

### Mathematical Constants included:

- `H` (Used in definite derivative algorithm, set to 1e-5 as given)
- `PI` (Mathematical constant, accuracy of 20 decimal digits)
- `HALF_PI` (pi / 2, accuracy of 11 decimal digits)
- `THIRD_PI` (pi / 3, accuracy of 10 decimal digits)
- `QUARTER_PI` (pi / 4, accuracy of 11 decimal digits)
- `SIXTH_PI` (pi / 6, accurate of 20 decimal digits)
- `PHI` (the golden ratio mathematical constant, accuracy of 20 decimal digits)
- `E` (Euler's number, accurate to 20 decimal digits)
- `TAU` (equivalent to 2 * pi, accurate to 35 decimal digits)
- `GAMMA` (The Euler Mascheroni Constant, accurate of 30 decimal digits)
- `FEIGENBAUM` (The Feigenbaum Constant approx. 4.669..., accurate to 30 decimal digits)
- `ZETA` (Equivalent to Apery's Constant, accurate to 19 decimal digits)
- `AVOGADRO` (Avogadro's constant, used for chemistry. set to 6.022e23)

