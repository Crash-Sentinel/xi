#ifndef XI_DERIVATIVE
#define XI_DERIVATIVE

#include <cmath>
#include "math_consts.h"
#include <iostream>
#include <type_traits>

namespace xi_derivative
{
    template <typename Func, typename T>
    inline long double definite_derivative(Func&& f, T x, T h = -1)
    {
        /*
            Derivative calculated with Five-Point Stencil 
            at a difference of h and Richardson Extrapolation
            to reduce potential error of h
        */
        static_assert(
            std::disjunction_v<std::is_same<T, float>, std::is_same<T, double>>,
            "Type must be either float or double for X and h"
        );

        if (h == -1) {
            h = xi_math_consts::h * std::fabs(x); // or use sqrt(epsilon) * |x|
        }

        long double xl = static_cast<long double>(x);
        long double hl = static_cast<long double>(h);

        // Five-point stencil at step size h
        long double D_h = (-f(xl + 2 * hl) + 8 * f(xl + hl) - 8 * f(xl - hl) + f(xl - 2 * hl)) / (12 * hl);

        hl /= 2;  
        long double D_h2 = (-f(xl + 2 * hl) + 8 * f(xl + hl) - 8 * f(xl - hl) + f(xl - 2 * hl)) / (12 * hl);

        // Richardson extrapolation
        long double D_extrapolated = (16 * D_h2 - D_h) / 15;

        return D_extrapolated;
    }



    // template <typename Func, typename T>
    // inline long double definite_derivative(
    //     Func&& f, 
    //     T x, 
    //     T h = -1)
    // {
    //     static_assert(
    //         std::disjunction_v<std::is_same<T, float>, std::is_same<T, double>>,
    //         "Type must be either float or double for X and h"
    //     );

    //     long double xl = static_cast<long double>(x);
    //     long double hl = static_cast<long double>(h);

    //     if (h == -1)
    //     {
    //         h = sqrt(xi_math_consts::epsilon) * std::fabs(x);
    //         std::cout << std::endl << "h: " << h << std::endl;
    //     }

    //     // Five-point stencil formula for improved precision
    //     return (-f(xl + 2 * hl) + 8 * f(xl + hl) - 8 * f(xl - hl) + f(xl - 2 * hl)) / (12 * hl);
    // }
}


#endif