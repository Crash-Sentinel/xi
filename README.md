# XI
<img width="19" alt="image" src="https://github.com/user-attachments/assets/a07cbc7a-3bb8-4041-b535-c471fc81cc4a">

Calculus and Linear Algebra based C++ Library

General Documentation:

Enhanced Derivative behavior:
- Uses the Five-point stencil formula and Richardson Extrapolation to determine the definite derivative

Five Stencil Formula:
f'(x) = -f(x+2h) + 8f(x-h) - 8f(x-h) + f(x-2h) / 12h

Pseudocode for better understanding:
- Take h = 1e-5, find f'(x) = A
- Half h, find new f'(x) = B
- Answer = (16 * B - A) / 15;

Mathematical Constants included:

- h (Used in definite derivative algorithm, set to 1e-5 as given)
- pi (Mathematical constant, accuracy of 20 decimal digits)
- half_pi (pi / 2, accuracy of 11 decimal digits)
- third_pi (pi / 3, accuracy of 10 decimal digits)
- quarter_pi (pi / 4, accuracy of 11 decimal digits)
- sixth_pi (pi / 6, accurate of 20 decimal digits)
- phi (the golden ratio mathematical constant, accuracy of 20 decimal digits)
- e (accurate to 20 decimal digits)
- tau (equivalent to 2 * pi, accurate to 35 decimal digits)
- gamma (The Euler Mascheroni Constant, accurate of 30 decimal digits)
- zeta (Equivalent to Apery's Constant, accurate to 19 decimal digits)
- avogadro (Avogadro's constant, used for chemistry. set to 6.022e23)

