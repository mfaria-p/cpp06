#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>

// Function prototypes
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random instance of A, B, or C
    Base* base = generate();

    // Identify the instance using a pointer
    std::cout << "Identifying using pointer: ";
    identify(base);

    // Identify the instance using a reference
    std::cout << "Identifying using reference: ";
    identify(*base);

    Base* unknown = NULL;
    std::cout << "Identifying unknown type using pointer: ";
    identify(unknown);

    if (base)   
        delete base;

    return 0;
}

