#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this != &src)
        return *this;
    return *this;
}

static bool ft_isdigit(char c) {
    return c >= '0' && c <= '9';
}

static bool ft_isprint(char c) {
    return c >= 32 && c <= 126;
}

//std::strtod() converts the string to a floating point number (of type double).
// std::strtod() skips all leading whitespaces, then takes an optional sign, followed by a sequence of digits optionally containing a decimal-point character
// std::strtod() stops reading the input string at the first character that it cannot recognize as part of a number.
// std::strtod() returns the converted floating point number as a value of type double.
// std::strtod() also sets the pointer pointed to by endptr to point to the first character after the number in the input string.
// If no conversion can be performed, std::strtod() returns zero and sets the pointer pointed to by endptr to point to the input string.
// If the correct value is outside the range of representable values, std::strtod() returns either HUGE_VAL or -HUGE_VAL (according to the sign of the value), and sets errno to ERANGE.
// If the correct value would cause underflow, std::strtod() returns zero and sets errno to ERANGE.

static ConversionType getConversionType(const std::string &str) {
    if (str == "-inff" || str == "+inff" || str == "nanf") {
        return INF_F;
    } else if (str == "-inf" || str == "+inf" || str == "nan") {
        return INF;
    } else if (str.length() == 1) {
        if (ft_isprint(str[0]) && !ft_isdigit(str[0])) {
            return SINGLE_CHAR;
        } else if (ft_isdigit(str[0])) {
            return INT_LITERAL;
        } else {
            return INVALID;
        }
    } else {
        char *endptr;
        errno = 0;
        std::strtod(str.c_str(), &endptr);
        if (errno == ERANGE)
            return INVALID;
        else if (*endptr == '\0' && ft_isdigit(*(endptr - 1))) {
            if (str.find('.') != std::string::npos) {
                return DOUBLE_LITERAL;
            } else {
                return INT_LITERAL;
            }
        } else if (*endptr == 'f' && *(endptr + 1) == '\0' && ft_isdigit(*(endptr - 1))) {
            return FLOAT_LITERAL;
        } else {
            return INVALID;
        }
    }
}

//static_cast is used for conversions that are not implicit and would typically require a C-style cast to be performed.
//static_cast is used for compile-time type conversions and is safer than C-style casts because it provides better type checking.
static void printChar(std::string str) 
{
    char c;
    int i;
    float f;
    double d;

    c = str[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f;
    std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << d;
    std::cout << ".0";
    std::cout << std::endl;
}

static void printInt(std::string str) 
{
    int i;
    float f;
    double d;

    i = strtol(str.c_str(), NULL, 10);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    std::cout << "char: ";
    if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else if (i < 0 || i > 255)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: ";
    if (i >= INT_MIN && i <= INT_MAX)
        std::cout << i << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "float: ";
    if (d >= -FLT_MAX && d <= FLT_MAX) 
    {
        std::cout << f;
        if (i < 1e6 && i > -1e6)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } else
        std::cout << "Impossible" << std::endl;

    std::cout << "double: " << d;
    if (i < 1e6 && i > -1e6)
        std::cout << ".0";
    std::cout << std::endl;
}

static void printDouble(std::string str) 
{
    double d;

    d = std::strtod(str.c_str(), NULL);
    std::cout << "char: ";
    if (d < 0 || d > 255)
        std::cout << "impossible" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "float: ";
    if (d >= -FLT_MAX && d <= FLT_MAX) 
    {
        float f = static_cast<float>(d);
        std::cout << f;
        if ((f == static_cast<int>(d) && f < 1e6 && f > -1e6) || (f < 1e6 && f > 1e5) || (f < -1e5 && f > -1e6))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } else
        std::cout << "Impossible" << std::endl;

    std::cout << "double: " << d;
    if ((d == static_cast<int>(d) && d < 1e6 && d > -1e6) || (d < 1e6 && d > 1e5) || (d < -1e5 && d > -1e6))
        std::cout << ".0";
    std::cout << std::endl;
}

static void printFloat(std::string str) 
{
    float f;
    double d;

    f = std::strtof(str.c_str(), NULL);
    d = static_cast<double>(f);
    std::cout << "char: ";
    if (f < 0 || f > 255)
        std::cout << "impossible" << std::endl;
    else if (f < 32 || f > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (f >= INT_MIN && f <= INT_MAX)
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "float: ";
    if (d >= -FLT_MAX && d <= FLT_MAX) {
        float f = static_cast<float>(d);
        std::cout << f;
        if ((f == static_cast<int>(f) && f < 1e6 && f > -1e6) || (f < 1e6 && f > 1e5) || (f < -1e5 && f > -1e6))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } else {
        std::cout << "Impossible" << std::endl;
    }

    std::cout << "double: " << d;
    if ((f == static_cast<int>(f) && d < 1e6 && d > -1e6) || (d < 1e6 && d > 1e5) || (d < -1e5 && d > -1e6))
        std::cout << ".0";
    std::cout << std::endl;
}

//test with 323428.678

void ScalarConverter::convert(const std::string &str) {
    ConversionType type = getConversionType(str);
    char *endptr;
    double d = std::strtod(str.c_str(), &endptr);

    switch (type) {
        case INF_F:
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: " << str << " " << std::endl;
            std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
            break;

        case INF:
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
            break;

        case SINGLE_CHAR:
            printChar(str);
            break;

        case INT_LITERAL:
            if (d < INT_MIN || d > INT_MAX)
                printDouble(str);
            else
                printInt(str);
            break;

        case DOUBLE_LITERAL:
            printDouble(str);
            break;

        case FLOAT_LITERAL:
            if (d < -FLT_MAX || d > FLT_MAX)
                printDouble(str);
            else
                printFloat(str);
            break;

        case INVALID:
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: Impossible" << std::endl;
            std::cout << "double: Impossible" << std::endl;
            break;
    }
}