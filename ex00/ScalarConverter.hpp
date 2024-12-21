#ifndef EX00_SCALARCONVERTER_HPP
#define EX00_SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath> 
#include <cerrno>

enum ConversionType {
    INF_F,
    INF,
    SINGLE_CHAR,
    INVALID,
    DOUBLE_LITERAL,
    FLOAT_LITERAL,
    INT_LITERAL
};

//A method is a function that is defined within a class and operates on instances of that class. 
//A static method is a method that belongs to the class rather than any instance of the class and doesn't have access to instance variables.
//A static method can be called directly from the class itself and doesn't require any object creation.
//A static method can access static data member and can change the value of it.

class ScalarConverter {
    private:
        ScalarConverter(); // Default constructor
        ScalarConverter(const ScalarConverter &src); // Copy constructor
        ~ScalarConverter(); // Destructor
        ScalarConverter &operator=(const ScalarConverter &src); // Assignment operator

    public:
        static void convert(const std::string &str);
};

#endif //EX00_SCALARCONVERTER_HPP