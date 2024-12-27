#ifndef XI_ARRAY
#define XI_ARRAY

#include <type_traits>
#include <ctime>
#include <cstdlib>
#include <random>
#include <tuple>

namespace xi_array
{
    template <typename T>
    inline T* random_numbers(int size)
    {
        static_assert(
            std::is_arithmetic<T>::value,
            "Type must be a numerical value"
        );
        
        if (size <= 0) return nullptr;

        std::random_device rd;
        std::mt19937 gen(time(0));
        T* arr = new T;
        
        if (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<> dis(0.0, 1.0);

            for (int i = 0; i < size; ++i)
            {
                arr[i] = static_cast<T>(dis(gen));
            }

            return arr;
        }
        else 
        {
            std::uniform_int_distribution<> dis(0.0, RAND_MAX);

            for (int i = 0; i < size; ++i)
            {
                arr[i] = static_cast<T>(dis(gen));
            }

            return arr;
        }
    }

    template <typename T>
    inline T** random_numbers(std::tuple<int, int> tuple)
    {
        static_assert(
            std::is_arithmetic<T>::value,
            "Type must be a numerical value"
        );

        const int ROWS = std::get<0>(tuple);
        const int COLS = std::get<1>(tuple);
        
        if (ROWS <= 0 || COLS <= 0) return nullptr;

        std::random_device rd;
        std::mt19937 gen(time(0));
        T* arr = new T;
        
        if (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<> dis(0.0, 1.0);

            for (int i = 0; i < ROWS; ++i)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    arr[i][j] = static_cast<T>(dis(gen));
                }
            }

            return arr;
        }
        else 
        {
            std::uniform_int_distribution<> dis(0.0, RAND_MAX);

            for (int i = 0; i < ROWS; ++i)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    arr[i][j] = static_cast<T>(dis(gen));
                }
            }

            return arr;
        }
    }

    template <typename T>
    inline T* ones(int SIZE)
    {
        static_assert(
            std::is_arithmetic<T>::value,
            "Type must be a numerical value"
        );

        T* arr = new T[SIZE];

        for (int i = 0; i < SIZE; ++i)
            arr[i] = 1;
        
        return arr;
    }

    template <typename T>
    inline T** ones(std::tuple<int, int> tuple)
    {
        static_assert(
            std::is_arithmetic<T>::value,
            "Type must be a numerical value"
        );

        const int ROWS = std::get<0>(tuple);
        const int COLS = std::get<1>(tuple);

        T** arr = new T*[COLS];

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                arr[i][j] = 1;
        
        return arr;
    }
}

#endif