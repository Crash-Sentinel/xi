#ifndef XI_INTEGRAL
#define XI_INTEGRAL

#include <omp.h>
#include <iostream>
#include "math_consts.h"

namespace xi_integral
{
    /*
        Simpsons Rule Based Definite Integral
    */
    template <typename Func, typename T1, typename T2>
    inline long double definite_integral(Func&& f, T1 a, T2 b, int n = -1)
    {
        static_assert(
            std::is_arithmetic<T1>::value && std::is_arithmetic<T2>::value,
            "Types for A and B must be both numerical"
        );
        
        if (n % 2 == 1)
        {
            std::cerr << "N must be even for definite integral!" << std::endl;
            return -1;
        }

        if (n == -1) n = 10'000;

        long double delta_x = (static_cast<long double>(b) - a) / n;
        long double sum = f(a) + f(b);

        #pragma omp parallel for reduction(+ : sum)
        for (int i = 1; i < n; ++i)
        {
            long double x = a + i * delta_x;

            if (i % 2 == 0)
            {
                sum += 2 * f(x);
            }
            else
            {
                sum += 4 * f(x);
            }
        }

        return (delta_x / 3) * sum;
    }
}

#endif 
