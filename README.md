# XI
<img width="19" alt="image" src="https://github.com/user-attachments/assets/a07cbc7a-3bb8-4041-b535-c471fc81cc4a">

Calculus and Linear Algebra based C++ Library

## What is Xi? Why create it?

I chose Xi after the 14th letter of the greek alphabet, it is a personal favorite letter of mine and doesn't seem to get much recognition or love from the math community, so I decided to give this library its name. The more formal pronounciation of it is more of a "[KS-I]" sound but personally I don't mind if you pronounce it differently or the such.

As to why I decided to create a Linear Algebra and Calculus Library, I didn't notice many people really creating a library for C++ like this, so I decided why not myself to do so? Thus, Xi was created.

## General Documentation:

Enhanced Derivative behavior:
- Uses the Five-point stencil formula and Richardson Extrapolation to determine the definite derivative

Five Stencil Formula:
> f'(x) = -f(x+2h) + 8f(x-h) - 8f(x-h) + f(x-2h) / 12h

Pseudocode for better understanding:
- Take h = 1e-5, find f'(x) = A
- Half h, find new f'(x) = B
- Answer = (16 * B - A) / 15;

## Future Updates:

- Actually getting some Linear Algebra into here
- Sprucing up the integral and derivative code to be both more diverse in their methods and more optimized

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

