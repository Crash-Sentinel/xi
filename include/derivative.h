#ifndef XI_DERIVATIVE
#define XI_DERIVATIVE

#include <cmath>
#include "math_consts.h"
#include <type_traits>
#include <limits>

namespace xi_derivative
{
    template <typename Func, typename T>
    inline long double definite_derivative(Func&& f, T x, long double h = -1)
    {
        /*
            Derivative calculated with Five-Point Stencil 
            at a difference of h and Richardson Extrapolation
            to reduce potential error of h
        */
        static_assert(
            std::is_arithmetic<T>::value,
            "Type must be a numerical value"
        );

        if (h == -1) {
            h = std::pow(std::numeric_limits<long double>::epsilon(), 0.5);
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
}


#endif
