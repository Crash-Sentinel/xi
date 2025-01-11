/*
    Copyright (c) 2025 Crash Sentinel
    Licensed under the MIT License
    See LICENSE file in the project root for full license information.
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <random>
#include <type_traits>
#include <iostream>
#include <cassert>
#include <utility>

/*
    NOTE:
    Some of the following functions are without documentation, in the very close future
    each of the functions and classes will be with documentation

    GENERAL DOCUMENTATION:
    Main Library for Xi Matrices and Operations
    
    Intended for easy use of different matrix based operations
    and for future use of generating variable data
    to execute data science or for various applications

    Examples as well as general tutorials are to be located
    in the examples folder

    Design Decisions:
        - Allows users to have their own custom matrix
        that includes char and string datatypes in the matrix
        class, for easy and more formal collections of data

        - Operator Overloading done for more intuitive use of Matrix Classes
        instead of creating member functions

            * Most mathematical operations are done in Matrix_Numerical<datatype>
            so calculations wouldn't be done incorrectly on char or string datatypes,


        - 
*/
namespace xi_matrix
{
    /*
    Standard Matrix Of Datatype [ T ] Elements, chars and string datatypes included
    */
    template <typename T>
    class Matrix
    {
        private:
            size_t _rows;
            size_t _cols;
            std::vector<std::vector<T>> _data;
        public:
            /*
                Empty Matrix Constructor, rows = cols = 0 and no data is present
            */
            Matrix() : _rows(0), _cols(0) {};

            /*
                Will initialize rows = cols = [ size_t ] size and fill data values with 0's or blank chars if char or string datatypes are declared
            */
            Matrix(size_t size) : _rows(size), _cols(size) 
            {
                _data.resize(size, std::vector<T>(size));
            };

            /*
                Will initialize the dimensions to a rows x cols fashion and fill data values with 0's or blank chars if char or string datatypes are declared
            */
            Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols)
            {
                _data.resize(rows, std::vector<T>(cols));
            };

            /*
                Will initialize the dimensions to a rows x cols fashion and fill data values with the argued data value
            */
            Matrix(size_t rows, size_t cols, T value) : _rows(rows), _cols(cols)
            {
                _data.resize(rows, std::vector<T>(cols));
                for (int i = 0; i < this->rows(); ++i)
                    for (int j = 0; j < this->cols(); ++j)
                        _data.at(i).at(j) = value;
            };

            /*
                Will copy the dimensions and values of the argued matrix [ a ]
            */
            Matrix(const xi_matrix::Matrix<T>& a) : _rows(a.rows()), _cols(a.cols())
            {
                _data.resize(_rows, std::vector<T>(_cols));

                for (int i = 0; i < _rows; ++i)
                {
                    for (int j = 0; j < _cols; ++j)
                    {
                        this->_data[i][j] = a.at(i, j);
                    }
                }

            };

            /*
                Copies all the values within a 2D array into the matrix class
                Reference thanks to: https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
            */
            template <size_t rows, size_t cols>
            Matrix(T (&array)[rows][cols]) : _rows(rows), _cols(cols) {
                _data.resize(rows, std::vector<T>(cols));
                for (size_t i = 0; i < rows; ++i)
                    for (size_t j = 0; j < cols; ++j)
                        _data.at(i).at(j) = array[i][j];
            };

            /*
                Returns the std::vector<std::vector<T>> of data that the matrix contains
                Read-Write based function
            */
            std::vector<std::vector<T>>& getData() { return _data; }

            /*
                Returns the std::vector<std::vector<T>> of data that the matrix contains
                Read only based function
            */
            std::vector<std::vector<T>>& getData() const { return _data; }

            /*
                Returns the length of rows of the matrix
                Read only based function
            */
            size_t rows() const { return _rows; };

            /*
                Returns the length of columns of the matrix
                Read only based function
            */
            size_t cols() const { return _cols; };

            /*
                Returns a pointer to a pointer of an array that is contained with copied values of the matrix
                Read-Write based function??
            */
            T** array()
            {
                T** arr = new T*[_cols];
                for (int i = 0; i < _rows; ++i)
                {
                    for (int j = 0; j < _cols; ++j)
                    {
                        arr[i][j] = _data.at(i).at(j);
                    }
                }
                return arr;
            };

            /*
                Read-Write based function
            */
            T at(size_t row, size_t col)
            {
                return _data.at(row).at(col);
            };

            /*
                Read based function
            */
            T at(size_t row, size_t col) const
            {
                return _data.at(row).at(col);
            };

            /*
                Read-Write based function??
            */
            void setValue(size_t row, size_t col, T value) 
            {
                this->getData().at(row).at(col) = value;
            };

            /*
                Read-Write based function??
            */
            void swap(size_t row1, size_t col1, size_t row2, size_t col2)
            {
                T temp = this->at(row1, col1);
                this->setValue(row1, col1, this->at(row2, col2));
                this->setValue(row2, col1, temp);
            };

            /*
                Read-Write based function
            */
            void print()
            {
                std::cout << "[" << std::endl;
                for (int i = 0; i < this->rows(); i++)
                {
                    for (int j = 0; j < this->cols(); j++)
                    {
                        std::cout << this->at(i, j) << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << "]" << std::endl;
            };

            /*
                Read based function
            */
            void print() const
            {
                std::cout << "[" << std::endl;
                for (int i = 0; i < this->rows(); i++)
                {
                    for (int j = 0; j < this->cols(); j++)
                    {
                        std::cout << this->at(i, j) << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << "]" << std::endl;
            };

            /*
                Read-Write based function
            */
            xi_matrix::Matrix<T> transpose()
            {
                std::vector<std::vector<T>> newData(this->cols(), std::vector<T>(this->rows()));

                for (int i = 0; i < this->rows(); ++i)
                {
                    for (int j = 0; j < this->cols(); ++j)
                    {
                        newData[j][i] = this->_data[i][j];
                    }
                }

                xi_matrix::Matrix<T> result(this->cols(), this->rows());
                result.getData() = std::move(newData);

                return result;
            }
            
            /*
                Read-Write based function??
            */
            friend std::ostream& operator<<(std::ostream& os, const xi_matrix::Matrix<T>& m)
            {
                os << "[\n";
                for (int i = 0; i < m.rows(); i++)
                {
                    for (int j = 0; j < m.cols(); j++)
                    {
                        os << m.at(i, j) << " ";
                    }
                    os << "\n";
                }
                os << "]\n";
                return os;
            }

            std::vector<T>& operator[](size_t row)
            {
                if (row >= this->rows())
                {
                    throw std::out_of_range("Row index out of bounds");
                }
                return _data[row];
            }

            std::vector<T>& operator[](size_t row) const
            {
                if (row >= this->rows())
                {
                    throw std::out_of_range("Row index out of bounds");
                }
                return _data[row];
            }

            T& operator()(size_t row, size_t col) 
            {
                if (row >= this->rows() || col >= this->cols())
                {
                    throw std::out_of_range("Index out of bounds");
                }
                return _data[row][col];
            }

            T& operator()(size_t row, size_t col) const 
            {
                if (row >= this->rows() || col >= this->cols())
                {
                    throw std::out_of_range("Index out of bounds");
                }
                return _data[row][col];
            }

            bool operator==(const xi_matrix::Matrix<T>& a) const
            {
                if (this->_cols != a.cols() || this->_rows != a.rows())
                {
                    return false;
                }

                for (int i = 0; i < this->_rows; ++i)
                {
                    for (int j = 0; j < this->_cols; ++j)
                    {
                        if (this->at(i, j) != a.at(i, j))
                        {
                            return false;
                        }
                    }
                }

                return true;
            }
    };

    /*
        Standard Matrix Class for most mathematical operations, determinants and inverses are (soon to be) implemented, char and string datatypes are not allowed
    */
    template <typename T = long double>
    class Matrix_Numerical : public Matrix<T>
    {
        private:
            size_t _rows;
            size_t _cols;
            std::vector<std::vector<T>> _data;
        public:
            static_assert(
                std::is_arithmetic<T>::value && 
                !std::is_same<T, char>::value && 
                !std::is_same<T, unsigned char>::value && 
                !std::is_same<T, signed char>::value, 
                "Value type must be arithmetic and not a character type!"
            );

            using Matrix<T>::Matrix;

            /*
                Currently a Stub Function for later development of determinant, simply returns the first element in the matrix
            */
            T det()
            {
                assert(
                    this->rows() == this->cols() &&
                    "Matrix must be a square matrix in order to calculate determinant!"
                );

                if (this->rows() == 2) { return (this->at(0,0) * this->at(1,1)) - (this->at(0,1) * this->at(1,0)); }
                else if (this->rows() == 3)
                {
                    T aei = this->at(0,0) * this->at(1,1) * this->at(2,2);
                    T bfg = this->at(0,1) * this->at(1,2) * this->at(2,0);
                    T cdh = this->at(0,2) * this->at(1,0) * this->at(2,1);
                    T ceg = this->at(0,2) * this->at(1,1) * this->at(2,0);
                    T bdi = this->at(0,1) * this->at(1,0) * this->at(2,2);
                    T afh = this->at(0,0) * this->at(1,2) * this->at(2,1);

                    return (aei + bfg + cdh - ceg - bdi - afh);
                }

                //Until further functionality progresses
                return this->getData()[0][0];
            }

            // Inverse Function To Be Included Soon
            
            template <typename U>
            xi_matrix::Matrix_Numerical<std::common_type_t<T, U>> 
            operator+(const xi_matrix::Matrix_Numerical<U>& other) {
                
                assert(
                    this->rows() == other.rows() && this->cols() == other.cols()
                    && "Matrix dimensions must match for addition"
                );

                using ResultType = std::common_type_t<T, U>;

                xi_matrix::Matrix_Numerical<ResultType> result(this->rows(), this->cols());

                for (size_t i = 0; i < this->rows(); ++i)
                {
                    for (size_t j = 0; j < this->cols(); ++j)
                    {
                        result.getData()[i][j] = 
                            static_cast<ResultType>(this->at(i, j)) + static_cast<ResultType>(other.at(i, j));
                    }
                }

                return result;
            };

            template <typename U>
            xi_matrix::Matrix_Numerical<std::common_type_t<T, U>>
            operator-(const xi_matrix::Matrix_Numerical<U>& other)
            {
                assert(
                    this->rows() == other.rows() && this->cols() == other.cols()
                    && "Matrix dimensions must match for addition"
                );

                using ResultType = std::common_type_t<T, U>;

                xi_matrix::Matrix_Numerical<ResultType> result(this->rows(), this->cols());

                for (size_t i = 0; i < this->rows(); ++i)
                {
                    for (size_t j = 0; j < this->cols(); ++j)
                    {
                        result.getData()[i][j] = 
                            static_cast<ResultType>(this->at(i, j)) - static_cast<ResultType>(other.at(i, j));
                    }
                }

                return result;
            };

            template <typename U>
            xi_matrix::Matrix_Numerical<T>&
            operator+=(const xi_matrix::Matrix_Numerical<U>& other)
            {
                assert(
                    this->rows() == other.rows() && this->cols() == other.cols()
                    && "Matrix dimensions must match for addition"
                );

                using ResultType = std::common_type_t<T, U>;

                for (int i = 0; i < this->rows(); ++i)
                {
                    for (int j = 0; j < this->cols(); ++j)
                    {
                        this->getData()[i][j] =
                            static_cast<ResultType>(this->at(i, j)) + static_cast<ResultType>(other.at(i, j));
                    }
                }

                return *this;
            };

            template <typename U>
            xi_matrix::Matrix_Numerical<T>&
            operator-=(const xi_matrix::Matrix_Numerical<U>& other)
            {
                assert(
                    this->rows() == other.rows() && this->cols() == other.cols()
                    && "Matrix dimensions must match for addition"
                );

                using ResultType = std::common_type_t<T, U>;

                for (int i = 0; i < this->rows(); ++i)
                {
                    for (int j = 0; j < this->cols(); ++j)
                    {
                        this->getData()[i][j] =
                            static_cast<ResultType>(this->at(i, j)) - static_cast<ResultType>(other.at(i, j));
                    }
                }

                return *this;
            };

            xi_matrix::Matrix_Numerical<T>
            operator++()
            {
                xi_matrix::Matrix_Numerical<T> result(*this);

                for (size_t i = 0; i < result.rows(); ++i)
                {
                    for (size_t j = 0; j < result.cols(); ++j)
                    {
                        result.getData()[i][j] += 1;
                    }
                }

                return result;
            };

            xi_matrix::Matrix_Numerical<T>
            operator--()
            {
                xi_matrix::Matrix_Numerical<T> result(*this);

                for (size_t i = 0; i < result.rows(); ++i)
                {
                    for (size_t j = 0; j < result.cols(); ++j)
                    {
                        result.getData()[i][j] -= 1;
                    }
                }

                return result;
            };

            xi_matrix::Matrix_Numerical<T>
            operator++(int)
            {
                xi_matrix::Matrix_Numerical<T> result(*this);

                for (size_t i = 0; i < result.rows(); ++i)
                {
                    for (size_t j = 0; j < result.cols(); ++j)
                    {
                        this->getData()[i][j] += 1;
                    }
                }

                return result;
            };

            xi_matrix::Matrix_Numerical<T>
            operator--(int)
            {
                xi_matrix::Matrix_Numerical<T> result(*this);

                for (size_t i = 0; i < result.rows(); ++i)
                {
                    for (size_t j = 0; j < result.cols(); ++j)
                    {
                        this->getData()[i][j] -= 1;
                    }
                }

                return result;
            };

            xi_matrix::Matrix_Numerical<T>
            operator*(T number) const
            {
                xi_matrix::Matrix_Numerical<T> result(this->rows(), this->cols());

                for (size_t i = 0; i < this->rows(); ++i)
                {
                    for (size_t j = 0; j < this->cols(); ++j)
                    {
                        result.getData()[i][j] =
                            number * this->at(i, j);
                    }
                }

                return result;
            }

            friend xi_matrix::Matrix_Numerical<T>
            operator*(T scalar, const xi_matrix::Matrix_Numerical<T>& mat)
            {
                return mat * scalar;
            }

            template <typename U>
            xi_matrix::Matrix_Numerical<std::common_type_t<T, U>>
            operator*(const xi_matrix::Matrix_Numerical<U>& other)
            {
                assert(
                    this->cols() == other.rows() && //this->cols() != other.rows()
                    "Matrix dimensions must match up for multiplication"
                );

                using ResultType = std::common_type_t<T, U>;

                xi_matrix::Matrix_Numerical<ResultType> result(this->rows(), other.cols());

                ResultType sum = 0;
                for (int i = 0; i < this->rows(); ++i)
                {
                    for (int j = 0; j < other.cols(); ++j)
                    {
                        sum = 0;
                        for (int k = 0; k < this->cols(); ++k)
                        {
                            sum += (this->at(i, k) * other.at(k, j));
                        }
                        result.getData()[i][j] = sum;
                    }
                }

                return result;
            }
    };

    /*
        Creates a square Identity Matrix, determinants and inverses available as well as mathematical operations, less constructors to use from to make this class
    */
    template <typename T>
    class IdentityMatrix : public Matrix_Numerical<T>
    {
        public:

            IdentityMatrix(size_t size) : Matrix_Numerical<T>(size, size)
            {
                assert(
                    size > 1 && 
                    "Identity Matrix must be at least 2x2 sized"
                );

                for (size_t i = 0; i < size; ++i)
                {
                    for (size_t j = 0; j < size; ++j)
                    {
                        if (i == j)
                        {
                            this->setValue(i, j, static_cast<T>(1)); // Set diagonal to 1
                        }
                        else
                        {
                            this->setValue(i, j, static_cast<T>(0)); // Set off-diagonal to 0
                        }
                    }
                }
            };

            size_t det()
            {
                return 1; // Determinant of an Identity Matrix is always 1
            }

            *this inverse()
            {
                return *this; // Inverse of an Identity Matrix is itself
            }
    };
}

#endif