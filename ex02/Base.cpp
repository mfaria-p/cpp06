#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>

Base::~Base() {
    std::cout << "Base Destructor called" << std::endl;
}

Base * generate(void) {
    std::srand((std::time(0)));
    int random = rand() % 3;
    if (random == 0) {
        return new A;
    } else if (random == 1) {
        return new B;
    } else {
        return new C;
    }
}

// dynamic_cast is used for safe downcasting of pointers and references.
// It is used to convert a pointer or reference of a base class to a 
//pointer or reference of a derived class.
// If the conversion is not possible, dynamic_cast returns a null pointer 
//for pointers or throws a std::bad_cast exception for references.
// dynamic_cast can only be used with pointers and references to classes

void identify(Base * p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base & p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::exception & e) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::exception & e) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::exception & e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}